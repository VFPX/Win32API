[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : socket
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The <B>socket</B> function creates a socket that is bound to a specific service provider.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: creating a socket that is bound to a specific service provider](../../samples/sample_226.md)  
[Winsock: reading and setting socket options](../../samples/sample_232.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[A client for testing non-blocking Winsock server](../../samples/sample_413.md)  

## Declaration:
```foxpro  
SOCKET socket(
  int af,
  int type,
  int protocol
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER socket IN ws2_32;
	INTEGER af,;
	INTEGER type,;
	INTEGER protocol  
```  
***  


## Parameters:
af 
[in] Address family specification. 

type 
[in] Type specification for the new socket. 

protocol 
[in] Protocol to be used with the socket that is specific to the indicated address family.   
***  


## Return value:
If no error occurs, socket returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned.  
***  


## Comments:
When a session has been completed, a closesocket must be performed.  
  
***  

