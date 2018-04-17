[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : getsockopt
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  

#### The getsockopt function retrieves a socket option.
***  


## Code examples:
[Winsock: reading and setting socket options](../../samples/sample_232.md)  

## Declaration:
```foxpro  
int getsockopt(
  SOCKET s,
  int level,
  int optname,
  char FAR *optval,
  int FAR *optlen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER getsockopt IN ws2_32;
	INTEGER   s,;
	INTEGER   level,;
	INTEGER   optname,;
	STRING  @ optval,;
	INTEGER @ optlen  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a socket. 

level 
[in] Level at which the option is defined; the supported levels include SOL_SOCKET and IPPROTO_TCP. 

optname 
[in] Socket option for which the value is to be retrieved. 

optval 
[out] Pointer to the buffer in which the value for the requested option is to be returned. 

optlen 
[in, out] Pointer to the size of the optval buffer. 
  
***  


## Return value:
If no error occurs, getsockopt returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
See also [setsockopt](setsockopt.md) function.  
  
***  

