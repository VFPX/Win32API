<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : getprotobynumber
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
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
```txt  
number
[in] Protocol number, in host byte order.  
```  
***  


## Return value:
If no error occurs, getprotobynumber returns a pointer to the protoent structure. Otherwise, it returns a NULL pointer and a specific error number can be retrieved by calling WSAGetLastError.  
***  

