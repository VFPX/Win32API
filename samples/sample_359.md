<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Retrieving the path of the printer-driver directory and printer-processor directory

## Code:
```foxpro  
DO decl

LOCAL lcBuffer, lnBufsize
lcBuffer = Repli(Chr(0), 250)
lnBufsize = 0

IF GetPrinterDriverDirectory(Null, Null, 1,;
	@lcBuffer, Len(lcBuffer), @lnBufsize) <> 0

	lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)
	? "Printer Driver Directory:", lcBuffer
ENDIF

lcBuffer = Repli(Chr(0), 250)
lnBufsize = 0
IF GetPrintProcessorDirectory(Null, Null, 1,;
	@lcBuffer, Len(lcBuffer), @lnBufsize) <> 0

	lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)
	? "Printer Processor Directory:", lcBuffer
ENDIF

PROCEDURE decl
	DECLARE INTEGER GetPrinterDriverDirectory IN winspool.drv;
		STRING pName, STRING pEnvir, LONG Lvl,;
		STRING @pDriverDir, LONG cbBuf, LONG @pcbNeeded

	DECLARE INTEGER GetPrintProcessorDirectory IN winspool.drv;
		STRING pName, STRING pEnvir, INTEGER Lvl,;
		STRING @pPrintProcInfo, INTEGER cbBuf, INTEGER @pcbNeeded  
```  
***  


## Listed functions:
[GetPrintProcessorDirectory](../libraries/winspool.drv/GetPrintProcessorDirectory.md)  
[GetPrinterDriverDirectory](../libraries/winspool.drv/GetPrinterDriverDirectory.md)  
