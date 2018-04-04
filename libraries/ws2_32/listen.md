[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : listen
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
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
s 
[in] Descriptor identifying a bound, unconnected socket. 

backlog 
[in] Maximum length of the queue of pending connections.  
***  


## Return value:
If no error occurs, listen returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
If <Strong>backlog</Strong> set to SOMAXCONN (0x7FFFFFFF), the underlying service provider responsible for socket <Strong>s</Strong> will set the backlog to a maximum reasonable value.  
  
***  

