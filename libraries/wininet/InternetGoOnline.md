<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetGoOnline
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Prompts the user for permission to initiate connection to a URL.
***  


## Code examples:
[Using InternetGoOnline function](../../samples/sample_067.md)  
[Another way to go online (it is not about choosing an ISP)](../../samples/sample_141.md)  

## Declaration:
```foxpro  
BOOL InternetGoOnline(
    LPTSTR lpszURL,
    HWND hwndParent,
    DWORD dwReserved
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InternetGoOnline IN wininet;
	STRING  lpszURL,;
	INTEGER hwndParent,;
	INTEGER dwReserved  
```  
***  


## Parameters:
```txt  
lpszURL
[in] Pointer to a string variable containing the URL of the Web site to connect to.

hwndParent
[in] Handle to the parent window.

dwReserved
[in] Reserved. Must be set to zero.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

