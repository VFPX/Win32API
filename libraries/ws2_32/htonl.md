<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : htonl
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The htonl function converts a u_long from host to TCP/IP network byte order (which is big endian).
***  


## Code examples:
[Winsock: changing the byte ordering](../../samples/sample_221.md)  

## Declaration:
```foxpro  
u_long htonl(
  u_long hostlong
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER htonl IN ws2_32;
	INTEGER hostlong  
```  
***  


## Parameters:
```txt  
hostlong
[in] 32-bit number in host byte order.  
```  
***  


## Return value:
The htonl function returns the value in TCP/IP"s network byte order.  
***  

