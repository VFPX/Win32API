<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetGetConnectedState
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Retrieves the connected state of the local system.
***  


## Code examples:
[Retrieving the state of your Internet connection](../../samples/sample_068.md)  

## Declaration:
```foxpro  
BOOL InternetGetConnectedState(
    LPDWORD lpdwFlags,
    DWORD dwReserved
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InternetGetConnectedState IN wininet;
	INTEGER @ lpdwFlags,;
   	INTEGER   dwReserved  
```  
***  


## Parameters:
```txt  
lpdwFlags
[out] Pointer to an unsigned long integer variable where the connection description should be returned.

dwReserved
[in] Reserved. Must be set to zero.
  
```  
***  


## Return value:
Returns TRUE if there is an Internet connection, or FALSE otherwise.  
***  


## Comments:
The InternetGetConnectedStateEx is an extended version of this function.   
  
The InternetCheckConnection allows an application to check if a connection to the Internet can be established.  
  
***  

