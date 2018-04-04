[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : htons
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: how to retrieve a service information corresponding to a port](../../samples/sample_219.md)  
[Winsock: how to retrieve a service information corresponding to a service name](../../samples/sample_220.md)  
[Winsock: changing the byte ordering](../../samples/sample_221.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[A client for testing non-blocking Winsock server](../../samples/sample_413.md)  
[Winsock: resolving an address to a host name](../../samples/sample_570.md)  

## Declaration:
```foxpro  
u_short htons(
  u_short hostshort
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER htons IN ws2_32;
	INTEGER hostshort  
```  
***  


## Parameters:
hostshort 
[in] 16-bit number in host byte order.   
***  


## Return value:
The htons function returns the value in TCP/IP network byte order.  
***  

