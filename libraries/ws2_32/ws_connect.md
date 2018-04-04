[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ws_connect
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
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
s 
[in] Descriptor identifying an unconnected socket. 

name 
[in] Name of the socket in the SOCKADDR structure to which the connection should be established. 

namelen 
[in] Length of name, in bytes   
***  


## Return value:
If no error occurs, connect returns zero.  
***  

