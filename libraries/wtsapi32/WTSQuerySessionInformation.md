<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSQuerySessionInformation
Group: Terminal Services - Library: wtsapi32    
***  


#### Retrieves session information for the specified session on the specified terminal server. It can be used to query session information on local and remote terminal servers.

***  


## Declaration:
```foxpro  
BOOL WTSQuerySessionInformation(
	HANDLE hServer,
	DWORD SessionId,
	WTS_INFO_CLASS WTSInfoClass,
	LPTSTR* ppBuffer,
	DWORD* pBytesReturned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSQuerySessionInformationA IN Wtsapi32;
AS WTSQuerySessionInformation;
	INTEGER hServer,;
	LONG SessionId,;
	INTEGER WTSInfoClass,;
	INTEGER @ppBuffer,;
	LONG @pBytesReturned  
```  
***  


## Parameters:
```txt  
hServer
[in] Handle to a terminal server.

SessionId
[in] A Terminal Services session identifier.

WTSInfoClass
[in] Specifies the type of information to retrieve.

ppBuffer
[out] Pointer to a variable that receives a pointer to the requested information.

pBytesReturned
[out] Pointer to a variable that receives the size, in bytes, of the data returned in ppBuffer.

  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
For <Em>hServer</Em>, specify a handle opened by the WTSOpenServer function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the terminal server on which your application is running.  
  
To free the returned buffer, call the WTSFreeMemory function.  
  
***  

