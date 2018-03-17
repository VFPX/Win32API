<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : gethostbyaddr
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The gethostbyaddr function retrieves the host information corresponding to a network address.
***  


## Code examples:
[Winsock: retrieving the host information corresponding to a network address](../../samples/sample_217.md)  
[Retrieving the IP-to-physical address mapping table](../../samples/sample_230.md)  
[Retrieving the interface–to–IP address mapping table](../../samples/sample_233.md)  
[How to retrieve network parameters for the local computer (including Host name, Domain name, and DNS Server)](../../samples/sample_348.md)  

## Declaration:
```foxpro  
struct HOSTENT FAR * gethostbyaddr(
  const char FAR *addr,
  int len,
  int type
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER gethostbyaddr IN ws2_32;
	STRING  addr,;
	INTEGER len,;
	INTEGER type  
```  
***  


## Parameters:
```txt  
addr
[in] Pointer to an address in network byte order.

len
[in] Length of the address.

type
[in] Type of the address, such as the AF_INET address family type (defined as TCP, UDP, and other associated Internet protocols). Address family types and their corresponding values are defined in the Winsock2.h header file.  
```  
***  


## Return value:
If no error occurs, gethostbyaddr returns a pointer to the hostent structure. Otherwise, it returns a NULL pointer, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
The gethostbyaddr function has been deprecated by the introduction of the getnameinfo function.  
  
***  

