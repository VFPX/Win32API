[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : getservbyname
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The getservbyname function retrieves service information corresponding to a service name and protocol.
***  


## Code examples:
[Winsock: how to retrieve a service information corresponding to a service name](../../samples/sample_220.md)  

## Declaration:
```foxpro  
struct servent FAR * getservbyname(
  const char FAR *name,
  const char FAR *proto
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getservbyname IN ws2_32;
	STRING name,;
	STRING proto  
```  
***  


## Parameters:
name 
[in] Pointer to a null-terminated service name. 

proto 
[in] Optional pointer to a null-terminated protocol name.   
***  


## Return value:
If no error occurs, getservbyname returns a pointer to the servent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

