[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSARecv
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Receives data from a connected socket.
***  


## Code examples:
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
int WSARecv(
  SOCKET s,
  LPWSABUF lpBuffers,
  DWORD dwBufferCount,
  LPDWORD lpNumberOfBytesRecvd,
  LPDWORD lpFlags,
  LPWSAOVERLAPPED lpOverlapped,
  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSARecv IN ws2_32;
	INTEGER s,;
	STRING @lpBuffers,;
	LONG dwBufferCount,;
	LONG @lpNumberOfBytesRecvd,;
	LONG @lpFlags,;
	INTEGER lpOverlapped,;
	INTEGER lpCompletionRoutine  
```  
***  


## Parameters:
s 
[in] A descriptor identifying a connected socket. 

lpBuffers 
[in, out] A pointer to an array of WSABUF structures. Each WSABUF structure contains a pointer to a buffer and the length, in bytes, of the buffer. 

dwBufferCount 
[in] The number of WSABUF structures in the lpBuffers array. 

lpNumberOfBytesRecvd 
[out] A pointer to the number, in bytes, received by this call if the receive operation completes immediately.

lpFlags 
[in, out] A pointer to flags used to modify the behavior of the WSARecv function call. For more information, see the Remarks section. 

lpOverlapped 
[in] A pointer to a WSAOVERLAPPED structure (ignored for nonoverlapped sockets). 

lpCompletionRoutine 
[in] A pointer to the completion routine called when the receive operation has been completed (ignored for nonoverlapped sockets). 
  
***  


## Return value:
If no error occurs and the receive operation has completed immediately, WSARecv returns zero.  
***  

