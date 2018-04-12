[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating ports that are available for printing on a specified server

## Before you begin:
The code presents the *PrinterPort * and *PrinterPorts* classes. The latter is a collection of *PrinterPort* objects for a given server. The collection is populated using the EnumPorts call.  

The *PrinterPort* object has properties *portname, monitorname, description* and *porttype*.  

See also:

* [Enumerating locally installed printers](sample_146.md)
* [Enumerating printer drivers installed](sample_082.md)  
* [Enumerating the print processors and supporting data types installed on the specified server](sample_333.md)  
* [Enumerating print jobs and retrieving information for default printer](sample_368.md)  
* [How to retrieve number of print jobs that have been queued for the printer](sample_367.md)  
  
***  


## Code:
```foxpro  
DEFINE CLASS PrinterPorts As Collection
	server=""
	errorcode=0

PROCEDURE Init(cServer)
	THIS.server = m.cServer
	THIS.EnumPorts

PROCEDURE EnumPorts
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER

	DECLARE INTEGER EnumPorts IN winspool.drv;
		STRING pName, INTEGER lvl,;
		INTEGER pPorts, INTEGER cbBuf,;
		INTEGER @pcbNeeded, INTEGER @pcReturned

	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO
	
	LOCAL hBuffer, cBuffer, nBufsize, nResult,;
		nPortCount, nPortIndex, cPortBuffer

	STORE 0 TO hBuffer, nBufsize, nPortCount
	
	= EnumPorts(THIS.server, 2, hBuffer,;
		nBufsize, @nBufsize, @nPortCount)

	hBuffer = GlobalAlloc(0, nBufsize)

	nResult = EnumPorts(THIS.server, 2, hBuffer,;
		nBufsize, @nBufsize, @nPortCount)

	IF nResult = 0
		THIS.errorcode = GetLastError()
	ELSE
		cBuffer = REPLICATE(CHR(0), nBufsize)
		= MemToStr(@cBuffer, hBuffer, nBufsize)
		
		FOR nPortIndex=1 TO nPortCount
			LOCAL oPort As PrinterPort
			oPort = CREATEOBJECT("PrinterPort", hBuffer,;
				cBuffer, nPortIndex)
			THIS.Add(oPort)
			oPort=Null
		NEXT
	ENDIF

	= GlobalFree(hBuffer)

FUNCTION AddPort(cMonitor As String) As Boolean
	DECLARE INTEGER AddPort IN winspool.drv;
		STRING pName, INTEGER hWindow, STRING pMonitorName

	LOCAL nResult
	nResult = AddPort(THIS.server, _screen.HWnd, m.cMonitor)
	IF nResult <> 0
		THIS.EnumPorts
		RETURN .T.
	ELSE
	* 50=ERROR_NOT_SUPPORTED
		THIS.errorcode = GetLastError()
	ENDIF
RETURN .F.

FUNCTION DeletePort(cPortName As String) As Boolean
	DECLARE INTEGER DeletePort IN winspool.drv;
		STRING pName, INTEGER hWindow, STRING pPortName

	LOCAL nResult
	nResult = DeletePort(THIS.server, _screen.HWnd, m.cPortName)

	IF nResult <> 0
		THIS.EnumPorts
		RETURN .T.
	ELSE
		THIS.errorcode = GetLastError()
	ENDIF
RETURN .F.

ENDDEFINE

DEFINE CLASS PrinterPort As Session
*!*	typedef struct _PORT_INFO_2 {
*!*	  LPTSTR pPortName;    0:4
*!*	  LPTSTR pMonitorName  4:4
*!*	  LPTSTR pDescription; 8:4
*!*	  DWORD fPortType;    12:4
*!*	  DWORD Reserved;     16:4
*!*	} PORT_INFO_2, *PPORT_INFO_2; 20 bytes
#DEFINE PORT_INFO_2_SIZE 20
	portname=""
	monitorname=""
	description=""
	porttype=0

PROCEDURE Init(hBuffer, cBuffer, nPortIndex)
	LOCAL cPortBuffer
	cPortBuffer = SUBSTR(cBuffer, PORT_INFO_2_SIZE *;
		(nPortIndex-1)+1, PORT_INFO_2_SIZE)

	THIS.porttype = buf2dword(SUBSTR(cPortBuffer, 13,4))

	THIS.portname = THIS.GetString(@cBuffer,;
		buf2dword(SUBSTR(cPortBuffer, 1,4))-m.hBuffer+1)

	THIS.monitorname = THIS.GetString(@cBuffer,;
		buf2dword(SUBSTR(cPortBuffer, 5,4))-m.hBuffer+1)

	THIS.description = THIS.GetString(@cBuffer,;
		buf2dword(SUBSTR(cPortBuffer, 9,4))-m.hBuffer+1)

PROTECTED FUNCTION GetString(cBuffer, nOffset)
	LOCAL cResult, ch
	cResult = ""
	IF BETWEEN(nOffset, 1, LEN(cBuffer))
		DO WHILE .T.
			ch = SUBSTR(cBuffer, nOffset, 1)
			IF ch = CHR(0) OR nOffset = LEN(cBuffer)
				EXIT
			ENDIF
			cResult = cResult + m.ch
			nOffset = nOffset + 1
		ENDDO
	ENDIF
RETURN m.cResult
ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[AddPort](../libraries/setupapi/AddPort.md)  
[DeletePort](../libraries/winspool.drv/DeletePort.md)  
[EnumPorts](../libraries/winspool.drv/EnumPorts.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  

## Comment:
March 14, 2005. *The code has been completely rewritten.*  
  
* * *  
Test this class:
```foxpro
LOCAL oPorts, oPort  
oPorts = CREATEOBJECT("PrinterPorts", "") && local computer  
  
FOR EACH oPort IN oPorts  
	? oPort.portname, oPort.monitorname  
NEXT  
  
? oPorts.AddPort("Local Port")  
? oPorts.DeletePort("FILE:")
```

***  

