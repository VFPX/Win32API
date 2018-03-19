[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting default printer

## Before you begin:
See also:

* [Retrieving the name of the default printer](sample_360.md)  
* [Browsing Windows Known Folders (Special Folders)](sample_576.md)  
  
***  


## Code:
```foxpro  
DO declare

LOCAL cCurrentPrinter
cCurrentPrinter = GetDefaultPrinter()

? "Default printer:", cCurrentPrinter

IF SetDefaultPrinter("Microsoft XPS Document Writer") = 0
	* 1801 - ERROR_INVALID_PRINTER_NAME
	? "SetDefaultPrinter failed:", GetLastError()
ELSE
	? "New default printer:", GetDefaultPrinter()

	SetDefaultPrinter(m.cCurrentPrinter)
	? "Default printer restored:", GetDefaultPrinter()
ENDIF

* end of main

FUNCTION GetDefaultPrinter
	LOCAL cPrinter, nBufsize, nResult
	nBufsize = 250
	cPrinter = REPLICATE(CHR(0), nBufsize)

	TRY
		IF GetDefaultPrinterAPI(@cPrinter, @nBufsize) <> 0
			cPrinter = SUBSTR(cPrinter, 1,;
				AT(Chr(0),cPrinter)-1)
		ELSE
			cPrinter=""
		ENDIF
	CATCH
		cPrinter=""
	ENDTRY
RETURN m.cPrinter

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	
	DECLARE INTEGER SetDefaultPrinter IN winspool.drv;
		STRING pszPrinter

	DECLARE INTEGER GetDefaultPrinter IN winspool.drv;
	as GetDefaultPrinterAPI;
		STRING @pszBuffer,;
		INTEGER @pcchBuffer  
```  
***  


## Listed functions:
[GetDefaultPrinter](../libraries/winspool.drv/GetDefaultPrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[SetDefaultPrinter](../libraries/winspool.drv/SetDefaultPrinter.md)  
