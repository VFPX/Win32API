<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : getprotobyname
Group: Windows Sockets 2 (Winsock) - Library: iphlpapi    
***  


#### The getprotobyname function retrieves the protocol information corresponding to a protocol name.
***  


## Code examples:
[Winsock: how to retrieve the protocol information corresponding to a protocol name](../../samples/sample_224.md)  

## Declaration:
```foxpro  
struct PROTOENT FAR * getprotobyname(
  const char FAR *name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getprotobyname IN ws2_32;
	STRING name  
```  
***  


## Parameters:
```txt  
name
[in] Pointer to a null-terminated protocol name.  
```  
***  


## Return value:
If no error occurs, getprotobyname returns a pointer to the protoent. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

