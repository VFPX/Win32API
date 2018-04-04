[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : inet_ntoa
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The inet_ntoa function converts an (Ipv4) Internet network address into a string in Internet standard dotted format.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: retrieving information from a host database for a given host name](../../samples/sample_216.md)  
[Winsock: changing the byte ordering](../../samples/sample_221.md)  
[Retrieving the IP-to-physical address mapping table](../../samples/sample_230.md)  
[Retrieving the interface–to–IP address mapping table](../../samples/sample_233.md)  
[Retrieving the User Datagram Protocol (UDP) listener table](../../samples/sample_234.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  

## Declaration:
```foxpro  
char FAR * inet_ntoa(
  struct   in_addr in
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE STRING inet_ntoa IN ws2_32;
	INTEGER in_addr  
```  
***  


## Parameters:
in 
[in] Pointer to an in_addr structure that represents an Internet host address.   
***  


## Return value:
If no error occurs, inet_ntoa returns a character pointer to a static buffer containing the text address in standard "."" notation. Otherwise, it returns NULL.   
***  

