[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : htonl
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
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
hostlong 
[in] 32-bit number in host byte order.  
***  


## Return value:
The htonl function returns the value in TCP/IP"s network byte order.  
***  

