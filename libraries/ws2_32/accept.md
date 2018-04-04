[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : accept
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The accept function permits an incoming connection attempt on a socket.
***  


## Code examples:
[How to create non-blocking Winsock server](../../samples/sample_412.md)  

## Declaration:
```foxpro  
SOCKET accept(
  SOCKET s,
  struct sockaddr* addr,
  int* addrlen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER accept IN ws2_32;
	INTEGER   s,;
	STRING  @ addr,;
	INTEGER @ addrlen
  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a socket that has been placed in a listening state with the listen function. <font color=#0a0000>The connection is actually made with the socket that is returned by accept</font>. 

addr 
[out] Optional pointer to a buffer that receives the address of the connecting entity, as known to the communications layer.

addrlen 
[out] Optional pointer to an integer that contains the length of addr.   
***  


## Return value:
If no error occurs, accept returns a value of type SOCKET that is a descriptor for the new socket. This returned value is a handle for the socket on which the actual connection is made.

Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling WSAGetLastError.
  
***  

