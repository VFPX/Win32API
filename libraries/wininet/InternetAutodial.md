<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetAutodial
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
dwFlags
[in] Unsigned long integer value that contains a flag that controlls this operation.

hwndParent
[in] Handle to the parent window.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

