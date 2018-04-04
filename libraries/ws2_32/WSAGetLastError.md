[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAGetLastError
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSAGetLastError function returns the error status for the last operation that failed.
***  


## Code examples:
[How to build UDP responder](../../samples/sample_052.md)  
[Winsock: retrieving the host information corresponding to a network address](../../samples/sample_217.md)  
[Winsock: reading and setting socket options](../../samples/sample_232.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  
[Winsock: resolving an address to a host name](../../samples/sample_570.md)  

## Declaration:
```foxpro  
int WSAGetLastError (void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAGetLastError IN ws2_32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value indicates the error code for this thread"s last Windows Sockets operation that failed.  
***  


## Comments:
MSDN: a successful function call, or a call to WSAGetLastError, does not reset the error code. To reset the error code, use the WSASetLastError function call with iError set to zero.   
  
***  

