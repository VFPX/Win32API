[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : getservbyport
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The getservbyport function retrieves service information corresponding to a port and protocol.
***  


## Code examples:
[Winsock: how to retrieve a service information corresponding to a port](../../samples/sample_219.md)  

## Declaration:
```foxpro  
struct servent FAR * getservbyport(
  int port,
  const char FAR *proto
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getservbyport IN ws2_32;
	INTEGER port,;
	STRING  proto  
```  
***  


## Parameters:
port 
[in] Port for a service, in network byte order. 

proto 
[in] Optional pointer to a protocol name.   
***  


## Return value:
If no error occurs, getservbyport returns a pointer to the servent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

