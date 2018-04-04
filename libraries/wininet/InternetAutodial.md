[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetAutodial
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Causes the modem to automatically dial the default Internet connection.
***  


## Code examples:
[Dial the Net Automatically](../../samples/sample_140.md)  

## Declaration:
```foxpro  
BOOL InternetAutodial(
	DWORD dwFlags,
    HWND hwndParent
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetAutodial IN wininet.dll;
	INTEGER dwFlags,;
	INTEGER dwReserved  
```  
***  


## Parameters:
dwFlags
[in] Unsigned long integer value that contains a flag that controlls this operation. 

hwndParent
[in] Handle to the parent window.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

