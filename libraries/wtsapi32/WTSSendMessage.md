<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSSendMessage
Group: Terminal Services - Library: wtsapi32    
***  


#### Displays a message box on the client desktop of a specified Terminal Services session.
***  


## Declaration:
```foxpro  
BOOL WTSSendMessage(
	HANDLE hServer,
	DWORD SessionId,
	LPTSTR pTitle,
	DWORD TitleLength,
	LPTSTR pMessage,
	DWORD MessageLength,
	DWORD Style,
	DWORD Timeout,
	DWORD* pResponse,
	BOOL bWait
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSSendMessage IN WtsApi32;
	INTEGER hServer,;
	LONG SessionId,;
	STRING @pTitle,;
	LONG TitleLength,;
	STRING @pMessage,;
	LONG MessageLength,;
	LONG MsgStyle,;
	LONG MsgTimeout,;
	LONG @pResponse,;
	INTEGER bWait  
```  
***  


## Parameters:
```txt  
hServer
[in] Handle to a terminal server. Specify a handle opened by the WTSOpenServer function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the terminal server on which your application is running.

SessionId
[in] A Terminal Services session identifier. To indicate the current session, specify WTS_CURRENT_SESSION.

pTitle
[in] Pointer to a null-terminated string for the title bar of the message box.

TitleLength
[in] Specifies the length, in bytes, of the title bar string.

pMessage
[in] Pointer to a null-terminated string containing the message to display.

MessageLength
[in] Specifies the length, in bytes, of the message string.

Style
[in] Specifies the contents and behavior of the message box.

Timeout
[in] Specifies the time, in seconds, that the WTSSendMessage function waits for the user"s response.

pResponse
[out] Pointer to a variable that receives the user"s response.

bWait
[in] If TRUE, WTSSendMessage does not return until the user responds or the time-out interval elapses. If the Timeout parameter is zero, the function does not return until the user responds.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
<div class="precode">#DEFINE WTS_CURRENT_SERVER_HANDLE 0  
  
LOCAL cTitle, cMsg, nResponse  
cTitle = "Test Message"  
cMsg = "This is a test message. Please do not reply."  
nResponse = 0  
  
? WTSSendMessage(hServer, 0,;  
	@cTitle, LEN(cTitle),;  
	@cMsg, LEN(m.cMsg), 0, 15, @nResponse, 1)  
</div>  
  
***  

