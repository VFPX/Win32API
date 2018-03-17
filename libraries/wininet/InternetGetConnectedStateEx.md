<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetGetConnectedStateEx
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Retrieves the connected state of the specified Internet connection.
***  


## Code examples:
[Retrieving the state of your Internet connection](../../samples/sample_068.md)  

## Declaration:
```foxpro  
BOOL InternetGetConnectedStateEx(
    LPDWORD lpdwFlags,
    LPTSTR lpszConnectionName,
    DWORD dwNameLen,
    DWORD dwReserved
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InternetGetConnectedStateEx IN wininet;
	INTEGER @ lpdwFlags,;
	STRING  @ lpszConnectionName,;
	INTEGER   dwNameLen,;
	INTEGER   dwReserved  
```  
***  


## Parameters:
```txt  
lpdwFlags
[out] Pointer to an unsigned long integer variable where the connection description should be returned.

lpszConnectionName
[out] Pointer to a string value that receives the connection name.

dwNameLen
[in] Unsigned long integer value that contains the length of the lpszConnectionName string in TCHAR.

dwReserved
[in] Reserved. Must be set to zero.
  
```  
***  


## Return value:
Returns TRUE if there is an Internet connection, or FALSE otherwise.  
***  


## Comments:
Except the returned connection name this function is similar to the InternetGetConnectedState function. The InternetCheckConnection allows an application to check if a connection to the Internet can be established.  
  
***  

