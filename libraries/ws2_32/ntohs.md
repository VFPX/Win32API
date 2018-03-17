<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ntohs
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The ntohs function converts a u_short from TCP/IP network byte order to host byte order (which is little-endian on Intel processors).
***  


## Code examples:
[Winsock: changing the byte ordering](../../samples/sample_221.md)  
[Retrieving the User Datagram Protocol (UDP) listener table](../../samples/sample_234.md)  

## Declaration:
```foxpro  
u_short ntohs(
  u_short netshort
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ntohs IN ws2_32;
	INTEGER netshort  
```  
***  


## Parameters:
```txt  
netshort
[in] 16-bit number in TCP/IP network byte order.  
```  
***  


## Return value:
The ntohs function returns the value in host byte order. If the netshort parameter was already in host byte order, then no operation is performed.  
***  

