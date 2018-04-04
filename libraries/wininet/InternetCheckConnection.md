[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetCheckConnection
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Allows an application to check if a connection to the Internet can be established.
***  


## Code examples:
[Testing if a connection to an Url can be established](../../samples/sample_327.md)  

## Declaration:
```foxpro  
BOOL InternetCheckConnection(
	LPCTSTR lpszUrl,
	DWORD dwFlags,
	DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetCheckConnection IN wininet;
	STRING  lpszUrl,;
	INTEGER dwFlags,;
	INTEGER dwReserved
  
```  
***  


## Parameters:
lpszUrl
[in] Pointer to a string containing the URL to use to check the connection. This value can be set to NULL.

dwFlags
[in] Unsigned long integer value containing the flag values.

dwReserved
[in] Reserved. Must be set to 0.  
***  


## Return value:
Returns TRUE if a connection is made successfully, or FALSE otherwise.  
***  


## Comments:
Can test a general Internet connection availabiilty. The InternetGetConnectedState provide similar functionality.  
  
***  

