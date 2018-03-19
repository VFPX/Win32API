[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Adding printer to the list of supported printers for the specified server

## Code:
```foxpro  
DO decl

*|typedef struct _PRINTER_INFO_2 {
*|  LPTSTR    pServerName;         0:4
*|  LPTSTR    pPrinterName;        4:4
*|  LPTSTR    pShareName;          8:4
*|  LPTSTR    pPortName;           12:4
*|  LPTSTR    pDriverName;         16:4
*|  LPTSTR    pComment;            20:4
*|  LPTSTR    pLocation;           24:4
*|  LPDEVMODE pDevMode;            28:4
*|  LPTSTR    pSepFile;            32:4
*|  LPTSTR    pPrintProcessor;     36:4
*|  LPTSTR    pDatatype;           40:4
*|  LPTSTR    pParameters;         44:4
*|  PSECURITY_DESCRIPTOR pSecDesc; 48:4
*|  DWORD     Attributes;          52:4
*|  DWORD     Priority;            56:4
*|  DWORD     DefaultPriority;     60:4
*|  DWORD     StartTime;           64:4
*|  DWORD     UntilTime;           68:4
*|  DWORD     Status;              72:4
*|  DWORD     cJobs;               76:4
*|  DWORD     AveragePPM;          80:4
*|} PRINTER_INFO_2, *PPRINTER_INFO_2; 84 bytes

LOCAL lcInfoBuffer, hPrinter, lcSrvName, lcPrnName, lcDrvName
lcPrnName = "Epson Stylus COLOR 660 ESC/P 2"
lcDrvName = "Epson Stylus COLOR 660 ESC/P 2"

* empty server name means local computer
* or put existing server name like "\\MYSERV"
* Win9/Me: should be empty, can only install local printers
lcSrvName = ""

* MSDN: You must specify non-NULL values for the pPrinterName,
* pPortName, pDriverName, and pPrintProcessor members of
* this structure before calling AddPrinter.

LOCAL loSrvName, loPrnName, loPortName, loDrvName, loPrnProc
loSrvName  = CreateObject("PChar", lcSrvName)
loPrnName  = CreateObject("PChar", lcPrnName)
loPortName = CreateObject("PChar", "LPT1:")
loDrvName  = CreateObject("PChar", lcDrvName)
loPrnProc  = CreateObject("PChar", "WinPrint")

* filling PRINTER_INFO_2 structure
lcInfoBuffer = num2dword(loSrvName.GetAddr()) +;
	num2dword(loPrnName.GetAddr()) + num2dword(0) +;
	num2dword(loPortName.GetAddr()) +;
	num2dword(loDrvName.GetAddr()) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0) + num2dword(0) +;
	num2dword(loPrnProc.GetAddr()) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0) + num2dword(0) +;
	num2dword(0)

hPrinter = AddPrinter(lcSrvName, 2, @lcInfoBuffer)
IF hPrinter = 0
* 1795 - ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
* 1796 - ERROR_UNKNOWN_PORT
* 1797 - ERROR_UNKNOWN_PRINTER_DRIVER
* 1798 - ERROR_UNKNOWN_PRINTPROCESSOR
* 1801 - ERROR_INVALID_PRINTER_NAME
* 1802 - ERROR_PRINTER_ALREADY_EXISTS
	? "Error code:", GetLastError()
ELSE
	? "Handle to a new printer object:", hPrinter
	= ClosePrinter(hPrinter)
ENDIF

* end of main
PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER AddPrinter IN winspool.drv;
		STRING pName, INTEGER Level, STRING @pPrinter

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

* * *
DEFINE CLASS PChar As Custom
	PROTECTED hMem

PROCEDURE  Init (lcString)
	THIS.hMem = 0
	THIS.setValue (lcString)

PROCEDURE  Destroy
	THIS.ReleaseString

FUNCTION getAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION getValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
			STRING @, INTEGER, INTEGER
		= Heap2Str (@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION getAllocSize  && returns allocated memory size (string length)
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE setValue (lcString) && assigns new string value
#DEFINE GMEM_FIXED   0
	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As Str2Heap;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc (GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= Str2Heap (THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[AddPrinter](../libraries/winspool.drv/AddPrinter.md)  
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  

## Comment:
Use "MYSERVER\Epson" port name on a local computer to add a network printer shared as "Epson" and connected to server MYSERVER.  
  
***  

