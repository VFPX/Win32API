[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : getprotobynumber
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The getprotobynumber function retrieves protocol information corresponding to a protocol number.
***  


## Code examples:
[Winsock: how to retrieve the protocol information corresponding to a protocol number](../../samples/sample_225.md)  

## Declaration:
```foxpro  
struct PROTOENT FAR * getprotobynumber(
  int number
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getprotobynumber IN ws2_32;
	INTEGER number  
```  
***  


## Parameters:
number 
[in] Protocol number, in host byte order.   
***  


## Return value:
If no error occurs, getprotobynumber returns a pointer to the protoent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

