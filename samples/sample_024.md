<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Generating random UUID values

## Before you begin:
See also:

* [How to generate GUID values](sample_456.md)  
  
***  


## Code:
```foxpro  
FOR nIndex=1 TO 10
	? GetUUID()
NEXT
* end of main

PROCEDURE GetUUID()
	DECLARE INTEGER UuidCreate IN Rpcrt4 STRING @Uuid
	DECLARE INTEGER RpcStringFree IN Rpcrt4 LONG @StringUuid

	DECLARE INTEGER UuidToString IN Rpcrt4;
		STRING @Uuid, LONG @StringUuid

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER

	LOCAL cUUID, hBuffer, nBufsize, cResult
	cResult=""
	hBuffer=0
	cUUID=REPLICATE(CHR(0), 16)

	= UuidCreate(@cUUID)

	IF UuidToString(@cUUID, @hBuffer)=0
		nBufsize=36
		cResult=REPLICATE(CHR(0), nBufsize)
		MemToStr(@cResult, hBuffer, nBufsize)
		RpcStringFree(@hBuffer)
	ENDIF
	cResult=UPPER(STRTRAN(m.cResult, CHR(0), ""))
RETURN m.cResult  
```  
***  


## Listed functions:
[RpcStringFree](../libraries/rpcrt4/RpcStringFree.md)  
[UuidCreate](../libraries/rpcrt4/UuidCreate.md)  
[UuidToString](../libraries/rpcrt4/UuidToString.md)  
