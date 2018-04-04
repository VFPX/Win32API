[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ws_select
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The <Strong>select</Strong> function determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.

***  


## Declaration:
```foxpro  
int select(
  int nfds,
  fd_set* readfds,
  fd_set* writefds,
  fd_set* exceptfds,
  const struct timeval* timeout
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER select IN ws2_32 AS ws_select;
	INTEGER   nfds,;
	STRING  @ readfds,;
	STRING  @ writefds,;
	STRING  @ exceptfds,;
	INTEGER   timeout
  
```  
***  


## Parameters:
nfds 
[in] Ignored. The nfds parameter is included only for compatibility with Berkeley sockets. 

readfds 
[in, out] Optional pointer to a set of sockets to be checked for readability. 

writefds 
[in, out] Optional pointer to a set of sockets to be checked for writability 

exceptfds 
[in, out] Optional pointer to a set of sockets to be checked for errors. 

timeout 
[in] Maximum time for select to wait, provided in the form of a TIMEVAL structure.
  
***  


## Return value:
The select function returns the total number of socket handles that are ready and contained in the fd_set structures, zero if the time limit expired, or SOCKET_ERROR if an error occurred.  
***  

