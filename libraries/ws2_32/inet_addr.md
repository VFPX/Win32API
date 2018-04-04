[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : inet_addr
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The inet_addr function converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the IN_ADDR structure.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: retrieving the host information corresponding to a network address](../../samples/sample_217.md)  
[Winsock: changing the byte ordering](../../samples/sample_221.md)  
[How to retrieve network parameters for the local computer (including Host name, Domain name, and DNS Server)](../../samples/sample_348.md)  
[How to ping a remote site using IP Helper API calls](../../samples/sample_382.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[A client for testing non-blocking Winsock server](../../samples/sample_413.md)  
[Winsock: resolving an address to a host name](../../samples/sample_570.md)  
[Obtaining MAC address through Address Resolution Protocol (ARP) request](../../samples/sample_585.md)  

## Declaration:
```foxpro  
unsigned long inet_addr(
  const char   FAR *cp
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER inet_addr IN ws2_32;
	STRING cp  
```  
***  


## Parameters:
cp 
[in] Null-terminated character string representing a number expressed in the Internet standard "."" (dotted) notation.  
***  


## Return value:
If no error occurs, inet_addr returns an unsigned long value containing a suitable binary representation of the Internet address given. Otherwise the function returns the value INADDR_NONE (0x7F000001).  
***  

