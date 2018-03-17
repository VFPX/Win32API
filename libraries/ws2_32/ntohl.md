<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ntohl
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The ntohl function converts a u_long from TCP/IP network order to host byte order (which is little-endian on Intel processors).
***  


## Code examples:
[Winsock: changing the byte ordering](../../samples/sample_221.md)  

## Declaration:
```foxpro  
u_long ntohl(
  u_long netlong
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ntohl IN ws2_32;
	INTEGER netlong  
```  
***  


## Parameters:
```txt  
netlong
[in] 32-bit number in TCP/IP network byte order.  
```  
***  


## Return value:
The ntohl function takes a 32-bit number in TCP/IP network byte order and returns a 32-bit number in host byte order.  
***  

