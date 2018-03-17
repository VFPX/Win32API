<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ws_connect
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
***  


#### The <Strong>connect</Strong> function establishes a connection to a specified socket.

***  


## Declaration:
```foxpro  
int connect(
  SOCKET s,
  const struct sockaddr* name,
  int namelen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER connect IN ws2_32 AS ws_connect;
	INTEGER   s,;
	STRING  @ sname,;
	INTEGER   namelen
  
```  
***  


## Parameters:
```txt  
s
[in] Descriptor identifying an unconnected socket.

name
[in] Name of the socket in the SOCKADDR structure to which the connection should be established.

namelen
[in] Length of name, in bytes  
```  
***  


## Return value:
If no error occurs, connect returns zero.  
***  

