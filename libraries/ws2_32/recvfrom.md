<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : recvfrom
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
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
```txt  
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
  
```  
***  


## Return value:
If no error occurs, recvfrom returns the number of bytes received. If the connection has been gracefully closed, the return value is zero. Otherwise, a value of SOCKET_ERROR (-1) is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  

