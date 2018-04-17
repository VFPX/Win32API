[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)

## Short description:
This code sample retrieves the name of default printer on local computer and obtains detailed information for this printer in PRINTER_INFO_5 format.   
***  


## Before you begin:
This code sample retrieves the name of default printer on local computer and obtains detailed information for this printer in   [PRINTER_INFO_5](https://msdn.microsoft.com/en-us/library/windows/desktop/dd162848(v=vs.85).aspx) format. 

See also:

* [Using EnumPrinters function to enumerate locally installed printers](sample_146.md)  
* [Enumerating print jobs and retrieving information for default printer](sample_368.md)  
* [How to retrieve number of print jobs that have been queued for the printer](sample_367.md)  
* [Setting default printer](sample_589.md)  
  
***  


## Code:
```foxpro  
#DEFINE PRINTER_ATTRIBUTE_QUEUED 0x0001
#DEFINE PRINTER_ATTRIBUTE_DIRECT 0x0002
#DEFINE PRINTER_ATTRIBUTE_DEFAULT 0x0004
#DEFINE PRINTER_ATTRIBUTE_SHARED 0x0008
#DEFINE PRINTER_ATTRIBUTE_NETWORK 0x0010
#DEFINE PRINTER_ATTRIBUTE_HIDDEN 0x0020
#DEFINE PRINTER_ATTRIBUTE_LOCAL 0x0040
#DEFINE PRINTER_ATTRIBUTE_ENABLE_DEVQ 0x0080
#DEFINE PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS 0x0100
#DEFINE PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 0x0200
#DEFINE PRINTER_ATTRIBUTE_WORK_OFFLINE 0x0400
#DEFINE PRINTER_ATTRIBUTE_ENABLE_BIDI 0x0800
#DEFINE PRINTER_ATTRIBUTE_RAW_ONLY 0x1000
#DEFINE PRINTER_ATTRIBUTE_PUBLISHED 0x2000

DO declare

LOCAL cPrinter, hPrinter, cBuffer

cPrinter = GetDefaultPrinter0()
IF EMPTY(cPrinter)
	cPrinter = GetDefaultPrinter1()
ENDIF

IF EMPTY(cPrinter)
	? "Unable to retrieve default printer name"
	RETURN
ENDIF

? "Default printer:", m.cPrinter
?

hPrinter = 0
IF OpenPrinter(cPrinter, @hPrinter, 0) = 0
	? "Unable to retrieve printer handle"
	RETURN
ENDIF

*|typedef struct _PRINTER_INFO_5 {
*|  LPTSTR    pPrinterName;               0:4
*|  LPTSTR    pPortName;                  4:4
*|  DWORD     Attributes;                 8:4
*|  DWORD     DeviceNotSelectedTimeout;  12:4
*|  DWORD     TransmissionRetryTimeout;  16:4
*|} PRINTER_INFO_5, *PPRINTER_INFO_5;

LOCAL oPrinterInfo As LocalMem, nBufsize
nBufsize=1024

* obtaining required size for the structure
= GetPrinterA(hPrinter, 5, 0, 0, @nBufsize)

oPrinterInfo = CREATEOBJECT("LocalMem", nBufsize)

IF GetPrinterA(hPrinter, 5, oPrinterInfo.GetHandle(),;
	nBufsize, @nBufsize) = 0
	? "GetPrinter API call failed with error code: ", GetLastError()
ELSE
	hBuffer = oPrinterInfo.GetHandle()
	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, m.hBuffer, nBufsize)
	
	? "*** Restored from PRINTER_INFO_5 structure"

	? "Printer name:", GetMemStr(cBuffer,;
		buf2dword(SUBSTR(cBuffer, 1, 4))-hBuffer+1)

	? "Port name: ", GetMemStr(cBuffer,;
		buf2dword(SUBSTR(cBuffer, 5, 4))-hBuffer+1)

	* see PRINTER_ATTRIBUTE_ constants
	* e.g. 0x0a48 is a combination of
	*	PRINTER_ATTRIBUTE_SHARED
	*	PRINTER_ATTRIBUTE_LOCAL,
	*	PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST
	*	PRINTER_ATTRIBUTE_ENABLE_BIDI
	? "Attributes:", TRANSFORM(buf2dword(SUBSTR(cBuffer, 9, 4)), "@0")

	? "Not selected Timeout, ms:", buf2dword(SUBSTR(cBuffer, 13, 4))
	? "Retry Timeout, ms:", buf2dword(SUBSTR(cBuffer, 17, 4))
ENDIF

= ClosePrinter(hPrinter)
* end of main

FUNCTION GetMemStr(cBuffer, nOffset)
	LOCAL nSpan
	nSpan = 0
	DO WHILE nOffset+nSpan <= LEN(cBuffer);
		And SUBSTR(cBuffer, nOffset+nSpan, 1) <> CHR(0)
		nSpan = m.nSpan + 1
	ENDDO
RETURN SUBSTR(m.cBuffer, nOffset, nSpan)

FUNCTION GetDefaultPrinter0
* may not be supported on Win9*/Me
	LOCAL cPrinter, nBufsize, nResult
	nBufsize = 250
	cPrinter = REPLICATE(CHR(0), nBufsize)

	TRY
		IF GetDefaultPrinter(@cPrinter, @nBufsize) <> 0
			cPrinter = SUBSTR(cPrinter, 1,;
				AT(Chr(0),cPrinter)-1)
		ELSE
			cPrinter=""
		ENDIF
	CATCH
		cPrinter=""
	ENDTRY
RETURN m.cPrinter

FUNCTION GetDefaultPrinter1
* returns default printer name from Windows Registry
	LOCAL lcBuffer, cPrinter, lcDriver, lcPort
	lcBuffer = REPLICATE(CHR(0), 120)

	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, Len(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
RETURN SUBSTR(lcBuffer, 1, AT(",", lcBuffer, 1)-1)

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem
	DECLARE LONG LocalSize IN kernel32 INTEGER hMem

	DECLARE INTEGER LocalAlloc IN kernel32;
		INTEGER uFlags, INTEGER uBytes

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLength

	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER dst, STRING @src, INTEGER nLength

	DECLARE INTEGER GetDefaultPrinter IN winspool.drv;
		STRING @pszBuffer, INTEGER @pcchBuffer

	DECLARE INTEGER GetPrinter IN winspool.drv;
	AS GetPrinterA;
		INTEGER hPrinter, INTEGER Lvl, INTEGER pPrinter,;
		INTEGER cbBuf, INTEGER @pcbNeeded

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

DEFINE CLASS LocalMem As Session
* implements locally allocated memory block
#DEFINE LMEM_ZEROINIT 0x0040
PROTECTED hMem, bufsize
	hMem=0
	bufsize=0

PROCEDURE Init(nBufsize)
	THIS.bufsize = m.nBufsize
	THIS.hMem = LocalAlloc(LMEM_ZEROINIT, THIS.bufsize)

PROCEDURE Destroy
	IF THIS.hMem <> 0
		= LocalFree(THIS.hMem)
		THIS.hMem=0
	ENDIF

FUNCTION GetHandle
RETURN THIS.hMem

FUNCTION GetSize
RETURN THIS.bufsize

ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetDefaultPrinter](../libraries/winspool.drv/GetDefaultPrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetPrinter](../libraries/winspool.drv/GetPrinter.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[LocalAlloc](../libraries/kernel32/LocalAlloc.md)  
[LocalFree](../libraries/kernel32/LocalFree.md)  
[LocalSize](../libraries/kernel32/LocalSize.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  

## Comment:
The name of the default printer can be read from the Windows Registry: use GetProfileString function with "Windows" and "Device" passed as first two parameters.  
  
Note that GetDefaultPrinter function requires at least Win2K and is not supported on older Windows versions. On Win9*/Me the EnumPrinters called with PRINTER_ENUM_DEFAULT flag returns information about the default printer.  
  

***  

