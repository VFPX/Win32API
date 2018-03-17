<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ws_select
Group: Windows Sockets 2 (Winsock) - Library: ws2_32    
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
```txt  
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
  
```  
***  


## Return value:
The select function returns the total number of socket handles that are ready and contained in the fd_set structures, zero if the time limit expired, or SOCKET_ERROR if an error occurred.  
***  

