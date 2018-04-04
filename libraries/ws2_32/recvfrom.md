[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : recvfrom
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Receives a datagram and stores the source address.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  

## Declaration:
```foxpro  
int recvfrom(
  SOCKET s,
  char* buf,
  int len,
  int flags,
  struct sockaddr* from,
  int* fromlen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER recvfrom IN ws2_32;
	INTEGER s,;
	STRING @buf,;
	INTEGER buflen,;
	INTEGER rcvflags,;
	STRING @sockaddr,;
	INTEGER @fromlen  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a bound socket. 

buf 
[out] Buffer for the incoming data. 

len 
[in] Length of buf, in bytes. 

flags 
[in] Indicator specifying the way in which the call is made. 

from 
[out] Optional pointer to a buffer in a sockaddr structure that will hold the source address upon return. 

fromlen 
[in, out] Optional pointer to the size, in bytes, of the from buffer. 
  
***  


## Return value:
If no error occurs, recvfrom returns the number of bytes received. If the connection has been gracefully closed, the return value is zero. Otherwise, a value of SOCKET_ERROR (-1) is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  

