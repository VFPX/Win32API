[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : gethostbyname
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The gethostbyname function retrieves host information corresponding to a host name from a host database.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: retrieving the standard host name and IP address for the local machine](../../samples/sample_215.md)  
[Winsock: retrieving information from a host database for a given host name](../../samples/sample_216.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  

## Declaration:
```foxpro  
struct hostent FAR *gethostbyname(
  const char FAR *name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER gethostbyname IN ws2_32;
	STRING hostname  
```  
***  


## Parameters:
name 
[in] Pointer to the null-terminated name of the host to resolve.   
***  


## Return value:
If no error occurs, gethostbyname returns a pointer to the hostent structure described above. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  


## Comments:
The gethostbyname function has been deprecated by the introduction of the getaddrinfo function.  
  
***  

