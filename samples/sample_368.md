[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)

## Before you begin:
This code enumerates print jobs for default printer (*if both the jobs and the printer exist* :). The **JOB_INFO_1** structure is used, which includes such members as printer name, machine name, user name, document etc.  

Check another examples:  
* [Enumerating locally installed printers](sample_146.md)  
* [Enumerating printer drivers installed](sample_082.md)  
* [Enumerating the print processors and supporting data types installed on the specified server](sample_333.md)  
* [How to retrieve number of print jobs that have been queued for the printer](sample_367.md)  
* [Enumerating the ports that are available for printing on a specified server](sample_334.md)  
  
***  


## Code:
```foxpro  
DO decl
#DEFINE GMEM_FIXED  0

*|typedef struct _JOB_INFO_1 {
*|  DWORD  JobId;          0:4
*|  LPTSTR pPrinterName;   4:4
*|  LPTSTR pMachineName;   8:4
*|  LPTSTR pUserName;     12:4
*|  LPTSTR pDocument;     16:4
*|  LPTSTR pDatatype;     20:4
*|  LPTSTR pStatus;       24:4
*|  DWORD  Status;        28:4
*|  DWORD  Priority;      32:4
*|  DWORD  Position;      36:4
*|  DWORD  TotalPages;    40:4
*|  DWORD  PagesPrinted;  44:4
*|  SYSTEMTIME Submitted; 48:16
*|} JOB_INFO_1, *PJOB_INFO_1; 64 bytes
#DEFINE JOB_INFO_SIZE  64

PRIVATE hBuffer, cBuffer, nBufsize, nMinsize, nCount, cInfo
LOCAL hPrinter, lcPrinter, lnIndex, lnResult

* use default printer name or any other valid printer name
*lcPrinter = GetPrnNameNT()  && WinNT users
lcPrinter = GetPrnName()  && more common way

hPrinter = 0
IF OpenPrinter(lcPrinter, @hPrinter, 0) = 0
	? "Unable to retrieve printer handle for printer [" +;
		lcPrinter + "]"
	RETURN
ENDIF

* Allocate a sufficient buffer from the very beginning.
* Calling the EnumJobs with a nil buffer to define a buffer size
* -- it does not work with VFP, sometimes causing
* the well-known C0000005 Exception Error
* http://fox.wikis.com/wc.dll?Wiki~C0000005ExError

nBufsize = 16384  && dont be too modest
hBuffer = GlobalAlloc(GMEM_FIXED, nBufsize)

STORE 0 TO nCount, nMinsize

* calling with level 1 -- JOB_INFO_1
lnResult = EnumJobs(hPrinter, 0, 10, 1, hBuffer, nBufsize,;
	@nMinsize, @nCount)

= ClosePrinter(hPrinter)

IF lnResult = 0
* 122 = ERROR_INSUFFICIENT_BUFFER
	= GlobalFree(hBuffer)
	? "Error code:", GetLastError()
	? "Expected bufsize:", nBufsize
	RETURN
ENDIF

? "Jobs for printer [" + lcPrinter + "]", nCount

IF nCount = 0
	= GlobalFree(hBuffer)
	RETURN
ENDIF

* Now copying data from the memory address to a regular string
* to operate with it in VFP terms.
* Actually it is easier for me to use memory buffer as a source
* of offsets to apply SUBSTR to cBuffer accordingly

* nMinsize -- we dont need this, most of times its just a suggestion
* how large the buffer should be
* the reality is: array of JOB_INFO_ structures is on top of the buffer,
* and all string members -- on the bottom

cBuffer = Repli(Chr(0), nBufsize)
= Mem2Str(@cBuffer, hBuffer, nBufsize)

FOR lnIndex=0 TO nCount-1
	cInfo = SUBSTR(cBuffer, lnIndex*JOB_INFO_SIZE+1, JOB_INFO_SIZE)
	DO ParseJobInfo
ENDFOR

IF USED("csResult")
	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF
= GlobalFree(hBuffer)
* end of main

PROCEDURE ParseJobInfo
	IF Not USED("csResult")
	* mirrors the JOB_INFO_1 structure except the SYSTEMTIME member
	* adjust field sizes if they are too small
		CREATE CURSOR csResult (;
		jobid I, prnname C(30), compname C(20), usrname C(20),;
		document C(50), datatype C(20), jstat C(10), jstat1 I,;
		priority I, position I, totalpg I, printpg I )
	ENDIF

	INSERT INTO csResult VALUES (mw(1), ms(5), ms(9), ms(13),;
		ms(17), ms(21), ms(25), mw(29), mw(33), mw(37), mw(41), mw(45))
RETURN

FUNCTION mw(lnOffs)
RETURN buf2dword(SUBSTR(cInfo, lnOffs,4))

FUNCTION ms(lnOffs)
RETURN GetMemStr(buf2dword(SUBSTR(cInfo, lnOffs,4)))

FUNCTION GetMemStr(lnAddr)
	IF lnAddr = 0
		RETURN ""
	ENDIF

	LOCAL lnOffs, lcResult, ch
	lnOffs = lnAddr - hBuffer + 1
	lcResult = ""

	DO WHILE lnOffs < nBufsize
		ch = SUBSTR(cBuffer, lnOffs,1)
		IF ch = Chr(0)
			EXIT
		ELSE
			lcResult = lcResult + ch
		ENDIF
		lnOffs = lnOffs + 1
	ENDDO
RETURN lcResult

FUNCTION GetPrnNameNT
* returns default printer name (WinNT)
	LOCAL lcPrinter, lnBufsize
	lnBufsize = 250
	lcPrinter = Repli(Chr(0), lnBufsize)
RETURN Iif(GetDefaultPrinter(@lcPrinter, @lnBufsize)=0, "",;
	SUBSTR(lcPrinter, 1, AT(Chr(0),lcPrinter)-1))

FUNCTION GetPrnName
* returns default printer name from registry
	LOCAL lcBuffer, lnPos
	lcBuffer = Repli(Chr(0), 120)

	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, Len(lcBuffer))

	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
	lnPos = AT(",", lcBuffer, 1)
RETURN SUBSTR(lcBuffer, 1, lnPos-1)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE decl
	DECLARE INTEGER EnumJobs IN winspool.drv;
		INTEGER hPrinter, INTEGER FirstJob, INTEGER NoJobs,;
		INTEGER Lvl, INTEGER pJob, INTEGER cbBuf,;
		INTEGER @pcbNeeded, INTEGER @pcReturned

	DECLARE INTEGER GetDefaultPrinter IN winspool.drv;
		STRING @pszBuffer, INTEGER @pcchBuffer

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

	DECLARE RtlMoveMemory IN kernel32 As Mem2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[EnumJobs](../libraries/winspool.drv/EnumJobs.md)  
[GetDefaultPrinter](../libraries/winspool.drv/GetDefaultPrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  

## Comment:
Technically it is easy to make this code working with JOB_INFO_2 and JOB_INFO_3 structures.  
  
***  

