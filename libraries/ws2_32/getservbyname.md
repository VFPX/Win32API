<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : getservbyname
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The getservbyname function retrieves service information corresponding to a service name and protocol.
***  


## Code examples:
[Winsock: how to retrieve a service information corresponding to a service name](../../samples/sample_220.md)  

## Declaration:
```foxpro  
struct servent FAR * getservbyname(
  const char FAR *name,
  const char FAR *proto
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getservbyname IN ws2_32;
	STRING name,;
	STRING proto  
```  
***  


## Parameters:
```txt  
name
[in] Pointer to a null-terminated service name.

proto
[in] Optional pointer to a null-terminated protocol name.  
```  
***  


## Return value:
If no error occurs, getservbyname returns a pointer to the servent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

