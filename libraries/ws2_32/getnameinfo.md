[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : getnameinfo
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Provides protocol-independent name resolution from an address to an ANSI host name and from a port number to the ANSI service name.
***  


## Code examples:
[Winsock: resolving an address to a host name](../../samples/sample_570.md)  

## Declaration:
```foxpro  
int WSAAPI getnameinfo(
  __in   const struct sockaddr FAR *sa,
  __in   socklen_t salen,
  __out  char FAR *host,
  __in   DWORD hostlen,
  __out  char FAR *serv,
  __in   DWORD servlen,
  __in   int flags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getnameinfo IN ws2_32;
	STRING @sockaddr,;
	INTEGER salen,;
	STRING @host,;
	LONG hostlen,;
	STRING @serv,;
	LONG servlen,;
	INTEGER procFlags
  
```  
***  


## Parameters:
sa [in]
A pointer to a socket address structure that contains the address and port number of the socket. For IPv4, the sa parameter points to a sockaddr_in structure. For IPv6, the sa parameter points to a sockaddr_in6 structure.

salen [in]
The length, in bytes, of the structure pointed to by the sa parameter.

host [out]
A pointer to an ANSI string used to hold the host name. 

hostlen [in]
The length, in bytes, of the buffer pointed to by the host parameter. 

serv [out]
A pointer to an ANSI string to hold the service name. 

servlen [in]
The length, in bytes, of the buffer pointed to by the serv parameter.

flags [in]
A value used to customize processing of the getnameinfo function.  
***  


## Return value:
On success, getnameinfo returns zero. Any nonzero return value indicates failure and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
The getnameinfo function deprecates the gethostbyaddr function.  
  
***  

