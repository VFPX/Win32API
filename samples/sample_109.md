[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Wininet last error description

## Code:
```foxpro  
#DEFINE ERROR_INSUFFICIENT_BUFFER   122

	DECLARE SHORT InternetGetLastResponseInfo IN wininet;
		INTEGER @ lpdwError,;
		STRING  @ lpszBuffer,;
		INTEGER @ lpdwBufferLength

	DECLARE INTEGER GetLastError IN kernel32

	LOCAL lpdwError, lpdwBufferLength, lpszBuffer, lnResult

	lpdwError = 0
	lpdwBufferLength = 250
	lpszBuffer = SPACE(lpdwBufferLength)
	
	lnResult = InternetGetLastResponseInfo (@lpdwError,;
			@lpszBuffer, @lpdwBufferLength)

	IF lnResult = 0 And GetLastError() = ERROR_INSUFFICIENT_BUFFER
		lpszBuffer = SPACE(lpdwBufferLength)
		lnResult = InternetGetLastResponseInfo (@lpdwError,;
				@lpszBuffer, @lpdwBufferLength)
	ENDIF

	IF lnResult = 1
		? "Error:", lpdwError
		? "Message:", LEFT(lpszBuffer, lpdwBufferLength)
	ELSE
		? "No response is available"
	ENDIF
RETURN  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[InternetGetLastResponseInfo](../libraries/wininet/InternetGetLastResponseInfo.md)  

## Comment:
This procedure retrieves the last Microsoft&reg; Win32&reg; Internet function error description or server response on the thread calling it.  
  
Do not expect any valid response of this function unless you have a connection to a server.  
  
  
***  

