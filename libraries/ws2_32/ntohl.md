[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ntohl
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
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
netlong 
[in] 32-bit number in TCP/IP network byte order.   
***  


## Return value:
The ntohl function takes a 32-bit number in TCP/IP network byte order and returns a 32-bit number in host byte order.  
***  

