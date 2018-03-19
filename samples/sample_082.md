[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating printer drivers installed

## Before you begin:

See also:

* [Enumerating locally installed printers](sample_146.md)  
* [Enumerating the print processors and supporting data types installed on the specified server](sample_333.md)  
* [Enumerating print jobs and retrieving information for default printer](sample_368.md)  
* [How to retrieve number of print jobs that have been queued for the printer](sample_367.md)  
* [Enumerating the ports that are available for printing on a specified server](sample_334.md)  

  
***  


## Code:
```foxpro  
#DEFINE GMEM_FIXED 0
DO declare

*|typedef struct _DRIVER_INFO_2 {
*|  DWORD  cVersion;     0:4
*|  LPTSTR pName;        4:4
*|  LPTSTR pEnvironment; 8:4
*|  LPTSTR pDriverPath;  12:4
*|  LPTSTR pDataFile;    16:4
*|  LPTSTR pConfigFile;  20:4
*|} DRIVER_INFO_2, *PDRIVER_INFO_2; -> 24 bytes

#DEFINE DRIVER_INFO_SIZE 24

PRIVATE hBuffer, nBufsize, cBuffer, cInfo

nBufsize = 16384
hBuffer = GlobalAlloc(GMEM_FIXED, nBufsize)

LOCAL lcServer, lnResult, lnReturned, lnCount
STORE 0 TO lnReturned, lnIndex, lnCount

* use Null for local computer or a valid server name
* e.g. "\\MYSERVER"
lcServer = Null
lnResult = EnumPrinterDrivers(lcServer,;
	Null, 2, hBuffer, nBufsize,;
	@lnReturned, @lnCount)

IF lnResult = 0
	? "Error code:", GetLastError()
	= GlobalFree(hBuffer)
	RETURN
ENDIF

cBuffer = REPLICATE(CHR(0), nBufsize)
= Mem2Str(@cBuffer, hBuffer, nBufsize)

* cursor for storing driver data
CREATE CURSOR csDrvList (;
	ver I, drvname C(50),;
	envname C(20),;
	drvpath C(200),;
	drvfile C(200), cfgfile C(200))

FOR lnIndex=0 TO lnCount-1

	cInfo = SUBSTR(cBuffer,;
		lnIndex * DRIVER_INFO_SIZE+1,;
		DRIVER_INFO_SIZE)

	INSERT INTO csDrvList;
	VALUES (mw(1), ms(5), ms(9),;
		ms(13), ms(17), ms(21))

ENDFOR

= GlobalFree(hBuffer)

IF USED("csDrvList")
	GO TOP
	EDIT NORMAL NOWAIT
ENDIF
* end of main

FUNCTION mw(lnOffs As Number)
RETURN buf2dword(SUBSTR(cInfo, lnOffs, 4))

FUNCTION ms(lnOffs As Number)
RETURN GetMemStr(buf2dword(SUBSTR(cInfo, lnOffs, 4)))

FUNCTION GetMemStr(lnAddr As Number)
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

FUNCTION buf2dword (lcBuffer As Character)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)), 8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER EnumPrinterDrivers IN winspool.drv;
		STRING pName, STRING pEnvironment,;
		LONG Lvl, INTEGER pDrvInfo,;
		INTEGER cbBuf, INTEGER @pcbNeeded,;
		INTEGER @pcReturned

	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE RtlMoveMemory IN kernel32 As Mem2Str;
		STRING @Dest, INTEGER Src,;
		INTEGER nLength  
```  
***  


## Listed functions:
[EnumPrinterDrivers](../libraries/winspool.drv/EnumPrinterDrivers.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
