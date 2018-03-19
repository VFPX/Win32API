[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving System Error message strings

## Code:
```foxpro  
LPARAMETERS nErrorno  && pass an error code

#DEFINE FORMAT_MESSAGE_ALLOCATE_BUFFER 0x100
#DEFINE FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#DEFINE FORMAT_MESSAGE_FROM_STRING 0x400
#DEFINE FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#DEFINE FORMAT_MESSAGE_IGNORE_INSERTS 0x200
#DEFINE FORMAT_MESSAGE_MAX_WIDTH_MASK 0xFF

	DECLARE INTEGER FormatMessage IN kernel32;
		INTEGER dwFlags, INTEGER lpSource, INTEGER dwMsgId,;
		INTEGER dwLangId, INTEGER @lpBuffer,;
		INTEGER nSize, INTEGER Arguments

	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @dst, INTEGER src, INTEGER nLen

	LOCAL nFlags, hBuffer, nLen, cBuffer
	cBuffer=""

	* specify format parameters
	nFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER +;
		FORMAT_MESSAGE_FROM_SYSTEM +;
		FORMAT_MESSAGE_IGNORE_INSERTS

	hBuffer = 0
	nLen = FormatMessage(nFlags, 0,;
		nErrorno, 0, @hBuffer, 0, 0)

	IF nLen <> 0
		cBuffer = REPLICATE(Chr(0), 500)
		= CopyMemory(@cBuffer, hBuffer, nLen)
		= LocalFree(hBuffer)
		RETURN STRTRAN(LEFT(cBuffer, nLen), Chr(13)+Chr(10), "")
	ELSE
		RETURN "#empty#"
	ENDIF  
```  
***  


## Listed functions:
[FormatMessage](../libraries/kernel32/FormatMessage.md)  
[LocalFree](../libraries/kernel32/LocalFree.md)  

## Comment:
W32 function GetLastError returns system error codes. There are about 2000 or more system error codes .   
  
The FormatMessage retrieves data from the MESSAGETABLE resource in KERNEL32.DLL. Most likely, the same can be accomplished with the FindResource and LoadResource calls (RT_MESSAGETABLE).  
  
***  

