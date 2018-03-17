<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : listen
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The listen function places a socket in a state in which it is listening for an incoming connection.
***  


## Code examples:
[How to create non-blocking Winsock server](../../samples/sample_412.md)  

## Declaration:
```foxpro  
int listen(
  SOCKET s,
  int backlog
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER listen IN ws2_32;
	INTEGER s,;
	INTEGER backlog  
```  
***  


## Parameters:
```txt  
s
[in] Descriptor identifying a bound, unconnected socket.

backlog
[in] Maximum length of the queue of pending connections.  
```  
***  


## Return value:
If no error occurs, listen returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
If <Strong>backlog</Strong> set to SOMAXCONN (0x7FFFFFFF), the underlying service provider responsible for socket <Strong>s</Strong> will set the backlog to a maximum reasonable value.  
  
***  

