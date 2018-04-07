[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAStartup
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSAStartup function initiates use of Ws2_32.dll by a process.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: initializing the service in the VFP application](../../samples/sample_214.md)  
[Winsock: retrieving the standard host name and IP address for the local machine](../../samples/sample_215.md)  
[Winsock: retrieving information from a host database for a given host name](../../samples/sample_216.md)  
[Winsock: retrieving the host information corresponding to a network address](../../samples/sample_217.md)  
[Winsock: how to retrieve a service information corresponding to a port](../../samples/sample_219.md)  
[Winsock: how to retrieve a service information corresponding to a service name](../../samples/sample_220.md)  
[Winsock: changing the byte ordering](../../samples/sample_221.md)  
[Winsock: retrieving information about available transport protocols](../../samples/sample_223.md)  
[Winsock: how to retrieve the protocol information corresponding to a protocol name](../../samples/sample_224.md)  
[Winsock: how to retrieve the protocol information corresponding to a protocol number](../../samples/sample_225.md)  
[Winsock: creating a socket that is bound to a specific service provider](../../samples/sample_226.md)  
[Retrieving the IP-to-physical address mapping table](../../samples/sample_230.md)  
[Winsock: reading and setting socket options](../../samples/sample_232.md)  
[Retrieving the interface–to–IP address mapping table](../../samples/sample_233.md)  
[How to retrieve network parameters for the local computer (including Host name, Domain name, and DNS Server)](../../samples/sample_348.md)  
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[A client for testing non-blocking Winsock server](../../samples/sample_413.md)  
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  
[Winsock: resolving an address to a host name](../../samples/sample_570.md)  

## Declaration:
```foxpro  
int WSAStartup(
  WORD wVersionRequested,
  LPWSADATA lpWSAData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAStartup IN ws2_32;
	INTEGER   wVerRq,;
	STRING  @ lpWSAData  
```  
***  


## Parameters:
wVersionRequested 
[in] Highest version of Windows Sockets support that the caller can use. The high-order byte specifies the minor version (revision) number; the low-order byte specifies the major version number. 

lpWSAData 
[out] Pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation. 
  
***  


## Return value:
The WSAStartup function returns zero if successful. Otherwise, it returns one of the predefined error codes.  
***  


## Comments:
MSDN: An application cannot call WSAGetLastError to determine the error code as is normally done in Windows Sockets if WSAStartup fails.   
  
See also: [WSACleanup](../ws2_32/WSACleanup.md).  
  
***  

