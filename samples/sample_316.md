[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting Unicode data from the Clipboard to a character string using a given code page

## Code:
```foxpro  
#DEFINE CF_UNICODETEXT  13
DO decl

LOCAL hData, lcUnicode

IF OpenClipboard(0) <> 0
	IF IsClipboardFormatAvailable(CF_UNICODETEXT) <> 0
		hData = GetClipboardData (CF_UNICODETEXT)
		lcUnicode = memwchar2str(hData)
*		? uconv (lcUnicode,  866)  && code page  866
		? uconv (lcUnicode, 1251)  && code page 1251
	ELSE
		? "No Unicode data available."
	ENDIF
	= CloseClipboard()  && the must
ENDIF
* end of main

FUNCTION uconv (lcSrc, lnCodePage)
	LOCAL lcDst, lnUsedDefault, lnResult
	lcDst = Repli(Chr(0), Len(lcSrc) * 2)
	lnUsedDefault = 0
	
	lnResult = WideCharToMultiByte (lnCodePage, 0,;
		lcSrc, Len(lcSrc),;
		@lcDst, Len(lcDst), "?", 0)

	IF lnResult = 0
	*   87 - ERROR_INVALID_PARAMETER
	*  122 - ERROR_INSUFFICIENT_BUFFER
	* 1004 - ERROR_INVALID_FLAGS
		? "Error code:", GetLastError()
		lcDst = ""
	ELSE
		lcDst = SUBSTR(lcDst, 1, lnResult)
	ENDIF
RETURN SUBSTR(lcDst, 1, AT(Chr(0),lcDst)-1)

FUNCTION  memwchar2str (lnMemBlock)
* copies Unicode characters (two-byte) from a memory address to a VFP string
RETURN  mem2str(lnMemBlock, Chr(0)+Chr(0))

FUNCTION  mem2str(lnMemBlock, end_sequence)
#DEFINE BUFFER_SIZE   16
#DEFINE EMPTY_BUFFER  Repli(Chr(0), BUFFER_SIZE)

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @, INTEGER, INTEGER

	LOCAL lnPtr, lcResult, lcBuffer, lnPos
	lnPtr = lnMemBlock
	lcResult = ""

	DO WHILE .T.
		lcBuffer = EMPTY_BUFFER
		= Heap2Str (@lcBuffer, lnPtr, BUFFER_SIZE)
		lnPos = AT(end_sequence, lcBuffer)
		IF lnPos > 0
			lcResult = lcResult + SUBSTR(lcBuffer, 1, lnPos-1)
			RETURN  lcResult
		ELSE
			lcResult = lcResult + lcBuffer
			lnPtr = lnPtr + BUFFER_SIZE
		ENDIF
	ENDDO

PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER GetClipboardData IN user32 INTEGER uFormat
	DECLARE INTEGER IsClipboardFormatAvailable IN user32 INTEGER wFormat

	DECLARE INTEGER WideCharToMultiByte IN kernel32;
		INTEGER CodePage, INTEGER dwFlags, STRING lpWideCharStr,;
		INTEGER cchWideChar, STRING @lpMultiByteStr, INTEGER cbMultiByte,;
		STRING lpDefaultChar, INTEGER lpUsedDefaultChar  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[GetClipboardData](../libraries/user32/GetClipboardData.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[IsClipboardFormatAvailable](../libraries/user32/IsClipboardFormatAvailable.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[WideCharToMultiByte](../libraries/kernel32/WideCharToMultiByte.md)  
