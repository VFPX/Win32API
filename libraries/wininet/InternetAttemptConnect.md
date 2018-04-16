[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetAttemptConnect
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
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
dwReserved
[in] Reserved. Must be set to 0.  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a Microsoft&reg; Win32&reg; error value otherwise.  
***  


## Comments:
This function allows an application to first attempt to connect before issuing any requests. A client program can use this to evoke the dial-up dialog box. If the attempt fails, the application should enter offline mode.  
  
Notice that this function returns 0 if successful, comparing to True being returned by similar functions InternetAutodial and InternetGoOnline.  
  
***  

