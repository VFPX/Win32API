[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : bind
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The bind function associates a local address (IP address and port) with a socket.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  

## Declaration:
```foxpro  
int bind(
  SOCKET s,
  const struct sockaddr* name,
  int namelen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER bind IN ws2_32 As ws_bind;
	INTEGER  s,;
	STRING @ sockaddr,;
	INTEGER  namelen
  
```  
***  


## Parameters:
s 
[in] Descriptor identifying an unbound socket. 

name 
[in] Address to assign to the socket from the sockaddr structure. 

namelen 
[in] Length of the value in the name parameter, in bytes.   
***  


## Return value:
If no error occurs, bind returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
In Visual FoxPro 8 declare bind function with an alias, because it may mix with BINDEVENT.  
  
***  

