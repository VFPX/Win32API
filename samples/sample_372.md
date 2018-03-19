[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Displaying printer-properties Property Sheet for the specified printer

## Code:
```foxpro  
#DEFINE PRINTER_ACCESS_ADMINISTER  4
#DEFINE PRINTER_ACCESS_USE         8
DO decl

LOCAL cPrinter, hPrinter, lcPrnDefaults

cPrinter = GetPrnName()  && default printer

* PRINTER_DEFAULTS structure
lcPrnDefaults = Repli(Chr(0),8) +;
	Chr(PRINTER_ACCESS_ADMINISTER) + Repli(Chr(0),3)

hPrinter = 0
IF OpenPrinter(cPrinter, @hPrinter, lcPrnDefaults) = 0
	? "Error opening printer [" + cPrinter + "]"
	RETURN
ENDIF

= PrinterProperties(GetActiveWindow(), hPrinter)
= ClosePrinter(hPrinter)
* end of main

FUNCTION GetPrnName
* returns default printer name from Windows Registry
	LOCAL lcBuffer, lcPrinter, lcDriver, lcPort
	lcBuffer = Repli(Chr(0), 120)
	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, Len(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
RETURN SUBSTR(lcBuffer, 1, AT(",", lcBuffer, 1)-1)

PROCEDURE decl
	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, STRING pDefault

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER PrinterProperties IN winspool.drv;
		INTEGER hWnd, INTEGER hPrinter  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  
[PrinterProperties](../libraries/winspool.drv/PrinterProperties.md)  
