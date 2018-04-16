[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to delete all print jobs for a printer

## Before you begin:
See also:

* [Retrieving default spooling directory name](sample_358.md)  
* [How to retrieve the number of print jobs queued for the printer](sample_367.md)  
* [Simple printer queue monitor](sample_373.md)  
  
***  


## Code:
```foxpro  
#DEFINE PRINTER_ACCESS_ADMINISTER  4
#DEFINE PRINTER_CONTROL_PURGE      3
DO decl

LOCAL lcPrinter, lcPrinter, lcPrnDefaults
lcPrinter = GetPrnName()

* For Windows NT/2000/XP
* while opening printer need to set printer defaults
* to provide proper level of access
* otherwise you can not delete jobs

*|typedef struct _PRINTER_DEFAULTS {
*|  LPTSTR      pDatatype;
*|  LPDEVMODE   pDevMode;
*|  ACCESS_MASK DesiredAccess;
*|} PRINTER_DEFAULTS, *PPRINTER_DEFAULTS; total 12 bytes

lcPrnDefaults = Repli(Chr(0),8) +;
	Chr(PRINTER_ACCESS_ADMINISTER) + Repli(Chr(0),3)

hPrinter = 0
IF OpenPrinter(lcPrinter, @hPrinter, @lcPrnDefaults) = 0
	? "Unable to retrieve printer handle for printer [" +;
		lcPrinter + "]"
	RETURN
ENDIF

* removing all existing jobs for the open printer
IF SetPrinter(hPrinter, 0, 0, PRINTER_CONTROL_PURGE) = 0
* 5 = ERROR_ACCESS_DENIED
	? "Unable to delete print jobs"
	? "Error code:", GetLastError()
ELSE
	? "All printer jobs (if any) for printer [" +;
		lcPrinter + "] deleted successfully."
ENDIF
= ClosePrinter(hPrinter)
* end of main

FUNCTION GetPrnName
* returns default printer name from registry
	LOCAL lcBuffer, lnPos
	lcBuffer = Repli(Chr(0), 120)

	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, Len(lcBuffer))

	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
	lnPos = AT(",", lcBuffer, 1)
RETURN SUBSTR(lcBuffer, 1, lnPos-1)

PROCEDURE decl
	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrnName, INTEGER @phPrinter, STRING @pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER SetPrinter IN winspool.drv;
		INTEGER hPrinter, LONG lvl, INTEGER pPrinter, LONG cmd

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  
[SetPrinter](../libraries/winspool.drv/SetPrinter.md)  

## Comment:
The SetPrinter function is used for this task. It makes no selection, but deletes all jobs it can find. For deleting a single job use the SetJob function.  
  
For Windows NT/2000/XP you must open the printer with a certain level of access: PRINTER_ACCESS_ADMINISTER. Otherwise the SetPrinter function will return error code 5 (ERROR_ACCESS_DENIED).  
  
* * *  
Having sufficient rights, a user can manually stop the spooler, delete files from the spooler directory (c:\windows\system32\spool\printers), and then re-start the spooler:  
```dos
NET STOP spooler  
REM DEL *.*  
NET START spooler
```
  
  
***  

