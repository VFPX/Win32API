[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating print processors and supporting data types installed on the specified server

## Before you begin:
Check other examples:  
* [Enumerating locally installed printers](sample_146.md)  
* [Enumerating printer drivers installed](sample_082.md)  
* [Enumerating print jobs and retrieving information for default printer](sample_368.md)  
* [How to retrieve number of print jobs that have been queued for the printer](sample_367.md)  
* [Enumerating the ports that are available for printing on a specified server](sample_334.md)  
  
***  


## Code:
```foxpro  
DO decl

*|typedef struct _PRINTPROCESSOR_INFO_1 {
*|  LPTSTR pName; 0:4
*|} PRINTPROCESSOR_INFO_1, *PPRINTPROCESSOR_INFO_1;

PRIVATE lcServer
* empty server name means local computer
* for a server replace with its like "\\MYSERV"
lcServer = ""

LOCAL lcBuffer, lnNeeded, lnReturned, lnResult,;
	lnIndex, lnAddr, lcProcName
STORE 0 TO lnNeeded, lnReturned

lcBuffer = Repli(Chr(0), 64)

= EnumPrintProcessors(lcServer, "", 1, @lcBuffer,;
	Len(lcBuffer), @lnNeeded, @lnReturned)

FOR lnIndex=1 TO lnReturned
	lnAddr = buf2dword(SUBSTR(lcBuffer, (lnIndex-1)*4+1, 4))
	lcProcName = mem2str(lnAddr)
	DO EnumDTypes WITH lcProcName
ENDFOR

IF USED("csResult")
	GO TOP
	BROW NORMAL NOWAIT
ELSE
	= MessageB("Nothing retrieved for " + lcServer)
ENDIF
* end of main

PROCEDURE EnumDTypes(lcProcName)
*|typedef struct _DATATYPES_INFO_1 {
*|  LPTSTR pName;
*|} DATATYPES_INFO_1, *PDATATYPES_INFO_1;

	LOCAL lcBuffer, lnNeeded, lnReturned, lnResult, lnIndex,;
		lnAddr, lcDTypeName
	STORE 0 TO lnNeeded, lnReturned

	* call with zero buffer to get a number of bytes required
	lnResult = EnumPrintProcessorDatatypes (lcServer, lcProcName, 1,;
		"", 0, @lnNeeded, @lnReturned)

	lcBuffer = Repli(Chr(0), lnNeeded)

	lnResult = EnumPrintProcessorDatatypes (lcServer, lcProcName, 1,;
		@lcBuffer, lnNeeded, @lnNeeded, @lnReturned)

	FOR lnIndex=1 TO lnReturned
		lnAddr = buf2dword(SUBSTR(lcBuffer, (lnIndex-1)*4+1, 4))
		lcDTypeName = mem2str(lnAddr)
		DO AddRec WITH lcProcName, lcDTypeName
	ENDFOR
RETURN

PROCEDURE AddRec (lcProcName, lcDTypeName)
	IF Not USED("csResult")
		CREATE CURSOR csResult (;
			procname C(30), datatype C(50))
	ENDIF
	INSERT INTO csResult VALUES (m.lcProcName, m.lcDTypeName)

PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER EnumPrintProcessors IN winspool.drv;
		STRING pName, STRING pEnvir, INTEGER Level,;
		STRING @pPrintProcInfo, INTEGER cbBuf,;
		INTEGER @pcbNeeded, INTEGER @pcReturned

	DECLARE INTEGER EnumPrintProcessorDatatypes IN winspool.drv;
		STRING pName, STRING pPrnProcName, INTEGER Level,;
		STRING @pDatatypes, INTEGER cbBuf, INTEGER @pcbNeeded,;
		INTEGER @pcReturned

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION  mem2str(lnMemBlock)
#DEFINE BUFFER_SIZE   16
#DEFINE EMPTY_BUFFER  Repli(Chr(0), BUFFER_SIZE)

	IF lnMemBlock = 0
		RETURN ""
	ENDIF

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @, INTEGER, INTEGER

	LOCAL lnPtr, lcResult, lcBuffer, lnPos
	lnPtr = lnMemBlock
	lcResult = ""

	DO WHILE .T.
		lcBuffer = EMPTY_BUFFER
		= Heap2Str (@lcBuffer, lnPtr, BUFFER_SIZE)
		lnPos = AT(Chr(0), lcBuffer)

		IF lnPos > 0
			lcResult = lcResult + SUBSTR(lcBuffer, 1, lnPos-1)
			RETURN lcResult
		ELSE
			lcResult = lcResult + lcBuffer
			lnPtr = lnPtr + BUFFER_SIZE
		ENDIF
	ENDDO  
```  
***  


## Listed functions:
[EnumPrintProcessorDatatypes](../libraries/winspool.drv/EnumPrintProcessorDatatypes.md)  
[EnumPrintProcessors](../libraries/winspool.drv/EnumPrintProcessors.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
The "WinPrint" is an expected return.  
  
***  

