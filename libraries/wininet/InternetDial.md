<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetDial
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Initiates a connection to the Internet using a modem.
***  


## Code examples:
[Initiating Inet connection using a modem](../../samples/sample_312.md)  

## Declaration:
```foxpro  
DWORD InternetDial(
	HWND hwndParent,
    LPTSTR lpszConnectoid,
    DWORD dwFlags,
    LPDWORD lpdwConnection,
    DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetDial IN wininet;
	INTEGER   hwndParent,;
	STRING    lpszConnectoid,;
	INTEGER   dwFlags,;
    INTEGER @ lpdwConnection,;
	INTEGER   dwReserved
  
```  
***  


## Parameters:
```txt  
hwndParent
[in] Handle to the parent window.

lpszConnectoid
[in] Pointer to a string variable containing the name of the dial-up connection to use.

dwFlags
[in] Unsigned long integer value that contains the flags to use.

lpdwConnection
[out] Pointer to an unsigned long integer value containing the number associated to the connection.

dwReserved
[in] Reserved. Must be set to 0.  
```  
***  


## Return value:
Returns ERROR_SUCCESS (0) if successful, or an error value otherwise.   
***  

