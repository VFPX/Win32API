[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : setsockopt
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The setsockopt function sets a socket option.
***  


## Code examples:
[Winsock: reading and setting socket options](../../samples/sample_232.md)  

## Declaration:
```foxpro  
int setsockopt(
  SOCKET s,
  int level,
  int optname,
  const char* optval,
  int optlen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER setsockopt IN ws2_32;
	INTEGER   s,;
	INTEGER   level,;
	INTEGER   optname,;
	STRING  @ optval,;
	INTEGER   optlen

  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a socket. 

level 
[in] Level at which the option is defined. Example: SOL_SOCKET. 

optname 
[in] Socket option for which the value is to be set.

optval 
[in] Pointer to the buffer in which the value for the requested option is specified. 

optlen 
[in] Size of the optval buffer, in bytes. 
  
***  


## Return value:
If no error occurs, setsockopt returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling WSAGetLastError.  
***  


## Comments:
See also getsockopt function.  
  
***  

