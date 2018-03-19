[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving default spooling directory name

## Before you begin:
See also:

* [How to delete all print jobs for a printer](sample_370.md)  
* [How to retrieve the number of print jobs queued for the printer](sample_367.md)  
* [Simple printer queue monitor](sample_373.md)  
  
***  


## Code:
```foxpro  
DO decl

LOCAL cPrinter, hPrinter, lnType, lcBuffer, lnBufsize
cPrinter = GetDefaultPrinter()
STORE 0 TO hPrinter, lnType, lnBufsize

IF OpenPrinter(cPrinter, @hPrinter, 0) <> 0
	lcBuffer = Repli(Chr(0), 250)
	= GetPrinterData(hPrinter, "DefaultSpoolDirectory",;
		@lnType, @lcBuffer, Len(lcBuffer), @lnBufsize)

	? "Default Spool Directory:", SUBSTR(lcBuffer, 1,lnBufsize-1)

	= ClosePrinter(hPrinter)
ENDIF
* end of main

FUNCTION GetDefaultPrinter
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), 120)

	* retrieving the printer, printer driver, and output-port names
	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

	= GetProfileString("Windows", "Device", ",,,", @lcBuffer, Len(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
RETURN SUBSTR(lcBuffer, 1, AT(",", lcBuffer)-1)

PROCEDURE decl
	DECLARE INTEGER GetPrinterData IN winspool.drv;
		INTEGER hPrinter, STRING pValueName, INTEGER @pType,;
		STRING @pData, LONG nSize, LONG @pcbNeeded

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetPrinterData](../libraries/winspool.drv/GetPrinterData.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  

## Comment:
Some reasons may exist for changing the print spooling directory, which task can be done either with the SetPrinterData function or manually through Start - Settings - Printers command.  
  
***  

