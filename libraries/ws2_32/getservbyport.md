<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : getservbyport
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The getservbyport function retrieves service information corresponding to a port and protocol.
***  


## Code examples:
[Winsock: how to retrieve a service information corresponding to a port](../../samples/sample_219.md)  

## Declaration:
```foxpro  
struct servent FAR * getservbyport(
  int port,
  const char FAR *proto
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getservbyport IN ws2_32;
	INTEGER port,;
	STRING  proto  
```  
***  


## Parameters:
```txt  
port
[in] Port for a service, in network byte order.

proto
[in] Optional pointer to a protocol name.  
```  
***  


## Return value:
If no error occurs, getservbyport returns a pointer to the servent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

