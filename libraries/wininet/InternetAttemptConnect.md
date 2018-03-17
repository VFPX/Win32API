<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetAttemptConnect
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Attempts to make a connection to the Internet.
***  


## Declaration:
```foxpro  
DWORD InternetAttemptConnect(
	DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetAttemptConnect IN wininet;
	INTEGER dwReserved
  
```  
***  


## Parameters:
```txt  
dwReserved
[in] Reserved. Must be set to 0.  
```  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a Microsoft® Win32® error value otherwise.  
***  


## Comments:
This function allows an application to first attempt to connect before issuing any requests. A client program can use this to evoke the dial-up dialog box. If the attempt fails, the application should enter offline mode.  
  
Notice that this function returns 0 if successful, comparing to True being returned by similar functions InternetAutodial and InternetGoOnline.  
  
***  

