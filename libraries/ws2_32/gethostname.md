[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : gethostname
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The gethostname function retrieves the standard host name for the local computer.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: retrieving the standard host name and IP address for the local machine](../../samples/sample_215.md)  
[Retrieving the IP-to-physical address mapping table](../../samples/sample_230.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  

## Declaration:
```foxpro  
int gethostname(
  char FAR *name,
  int namelen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER gethostname IN ws2_32;
	STRING  @ name,;
	INTEGER   namelen  
```  
***  


## Parameters:
name 
[out] Pointer to a buffer that receives the local host name. 

namelen 
[in] Length of the buffer.   
***  


## Return value:
If no error occurs, gethostname returns zero. Otherwise, it returns SOCKET_ERROR (-1) and a specific error code can be retrieved by calling WSAGetLastError.  
***  

