[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : sendto
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Sends data to a specific destination.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  

## Declaration:
```foxpro  
int sendto(
  SOCKET s,
  const char* buf,
  int len,
  int flags,
  const struct sockaddr* to,
  int tolen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER sendto IN ws2_32;
	INTEGER s,;
	STRING @buf,;
	INTEGER buflen,;
	INTEGER wsflags,;
	STRING @sendto,;
	INTEGER tolen  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a (possibly connected) socket. 

buf 
[in] Buffer containing the data to be transmitted. 

len 
[in] Length of the data in buf, in bytes. 

flags 
[in] Indicator specifying the way in which the call is made. 

to 
[in] Optional pointer to a sockaddr structure that contains the address of the target socket. 
tolen 
[in] Size of the address in to, in bytes.   
***  


## Return value:
If no error occurs, sendto returns the total number of bytes sent, which can be less than the number indicated by len. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
The sendto function is normally used on a connectionless socket to send a datagram to a specific peer socket identified by the to parameter. Even if the connectionless socket has been previously connected to a specific address, the to parameter overrides the destination address for that particular datagram only.   
  
On a connection-oriented socket, the to and tolen parameters are ignored, making sendto equivalent to send.  
  
***  

