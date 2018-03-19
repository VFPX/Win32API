[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve the number of print jobs queued for the printer

## Before you begin:
See also:

* [How to delete all print jobs for a printer](sample_370.md)  
* [Retrieving default spooling directory name](sample_358.md)  
* [Simple printer queue monitor](sample_373.md)  

* [Enumerating locally installed printers](sample_146.md)  
* [Enumerating printer drivers installed](sample_082.md)  
* [Enumerating the print processors and supporting data types installed on the specified server](sample_333.md)  

* [Enumerating print jobs and retrieving information for default printer](sample_368.md)  
* [Enumerating the ports that are available for printing on a specified server](sample_334.md)  

  
***  


## Code:
```foxpro  
* the offset to the "Jobs number" member
* in the PRINTER_INFO_2 structure
#DEFINE CJOBS_OFFSET  77

DO declare

LOCAL hPrinter, cPrinter, cPrnInfo, nBufsize, nResult
cPrinter = GetPrnName()
? "Default printer: ", cPrinter

hPrinter = 0
IF OpenPrinter(cPrinter, @hPrinter, 0) = 0
	? "Unable to obtain the handle for this printer."
	RETURN
ENDIF

nBufsize = 4096  && allocate sufficient buffer
cPrnInfo = REPLICATE(Chr(0), nBufsize)
nResult = GetPrinterA(hPrinter, 2, @cPrnInfo,;
	nBufsize, @nBufsize)

IF nResult = 0
	? "Error code:", GetLastError()
ELSE
	? "Number of print jobs queued:",;
		buf2dword(SUBSTR(cPrnInfo, CJOBS_OFFSET,4))
ENDIF

= ClosePrinter(hPrinter)
* end of main

FUNCTION GetPrnName
* returns default printer name from Windows Registry
	LOCAL cBuffer, cPrinter, cDriver, cPort
	cBuffer = REPLICATE(CHR(0), 120)

	= GetProfileString("Windows", "Device", ",,,",;
		@cBuffer, Len(cBuffer))
	cBuffer = STRTRAN(cBuffer, Chr(0), "")
RETURN SUBSTR(cBuffer, 1, AT(",", cBuffer, 1)-1)

PROCEDURE declare
	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

	DECLARE INTEGER GetPrinter IN winspool.drv AS GetPrinterA;
		INTEGER hPrinter, INTEGER Lvl, STRING @pPrinter,;
		INTEGER cbBuf, INTEGER @pcbNeeded

	DECLARE INTEGER GetLastError IN kernel32

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetPrinter](../libraries/winspool.drv/GetPrinter.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  

## Comment:
This is a very simple code that uses the GetPrinter API function with *Level* parameter set to 2. The default printer name is retrieved from Windows Registry. For Windows NT/XP you can use the GetDefaultPrinter function instead.  
  
To run this code for another printer, not the default one, assign its name to *lcPrinter* variable.  
  
More detailed information about the printer queue is returned by the EnumJobs function. It includes MachineName, UserName, Document, Status, SysTime, PagesPrinter and other parameters.  
  
***  

