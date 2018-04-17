[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Connecting a local device to a network resource

## Before you begin:
Similar examples:  
* [Starting a dialog box for connecting to network resources (mapping network drive)](sample_309.md)  
* [Mapping and disconnecting network drives in FoxPro application](sample_387.md)  
  
***  


## Code:
```foxpro  
DO decl

#DEFINE NO_ERROR  0

LOCAL nResult
WAIT WINDOW NOWAIT "Establishing network connection... "
nResult = WNetAddConnection("\\myserver\c", "", "Z:")
WAIT CLEAR

IF nResult <> NO_ERROR
*    5 - ERROR_ACCESS_DENIED
*   53 - ERROR_BAD_NETPATH
*   66 - ERROR_BAD_DEV_TYPE
*   67 - ERROR_BAD_NET_NAME
*   85 - ERROR_ALREADY_ASSIGNED
* 1200 - ERROR_BAD_DEVICE
* 1202 - ERROR_DEVICE_ALREADY_REMEMBERED
* 1203 - ERROR_NO_NET_OR_BAD_PATH
* 1206 - ERROR_BAD_PROFILE
* 1208 - ERROR_EXTENDED_ERROR
	IF nResult = 1208 && ERROR_EXTENDED_ERROR
		? "Extended error:", nResult, GetXError()
	ELSE
		? "Error code:", nResult, GetError(nResult)
	ENDIF
ELSE
	? "Connected successfully!"
ENDIF

FUNCTION GetXError
	LOCAL nErrCode, cErrDescr, cProvider, nResult
	nErrCode = 0
	STORE Repli(Chr(0),250) TO cErrDescr, cProvider

	nResult = WNetGetLastError(@nErrCode,;
		@cErrDescr, Len(cErrDescr), @cProvider, Len(cProvider))

	IF nResult = NO_ERROR
		RETURN LTRIM(STR(nErrCode)) + ". " +;
			ALLTRIM(STRTRAN(cErrDescr, Chr(0),""))
	ENDIF
RETURN ""

FUNCTION GetError(nErrCode)
#DEFINE FORMAT_MESSAGE_ALLOCATE_BUFFER    256
#DEFINE FORMAT_MESSAGE_FROM_SYSTEM       4096
#DEFINE FORMAT_MESSAGE_IGNORE_INSERTS     512

	LOCAL nFlags, nBuffer, nLength, cResult
	nFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER +;
		FORMAT_MESSAGE_FROM_SYSTEM + FORMAT_MESSAGE_IGNORE_INSERTS

	nBuffer = 0
	nLength = FormatMessage(nFlags, 0, nErrCode, 0, @nBuffer, 0,0)

	IF nLength <> 0
		cResult = REPLI(Chr(0), 1024)
		= CopyMemory (@cResult, nBuffer, nLength)
		RETURN STRTRAN(LEFT(cResult, nLength), Chr(13)+Chr(10), "")
	ELSE
		RETURN ""
	ENDIF

PROCEDURE decl
	DECLARE INTEGER WNetGetLastError IN mpr;
		INTEGER @lpError, STRING @lpErrBuf, INTEGER nErrBufSize,;
		STRING @lpNameBuf, INTEGER nNameBufSize

	DECLARE INTEGER WNetAddConnection IN mpr;
		STRING lpRemoteName, STRING lpPassw, STRING lpLocalName

	DECLARE INTEGER FormatMessage IN kernel32;
		INTEGER dwFlags, INTEGER lpSource, INTEGER dwMsgId,;
		INTEGER dwLanguageId, INTEGER @lpBuffer, INTEGER nSize,;
		INTEGER Arguments

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[CopyMemory](../libraries/kernel32/CopyMemory.md)  
[FormatMessage](../libraries/kernel32/FormatMessage.md)  
[WNetAddConnection](../libraries/mpr/WNetAddConnection.md)  
[WNetGetLastError](../libraries/odbc32/WNetGetLastError.md)  


***  

