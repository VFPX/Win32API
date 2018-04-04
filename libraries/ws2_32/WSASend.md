[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSASend
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Sends data on a connected socket.
***  


## Code examples:
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
int WSASend(
  SOCKET s,
  LPWSABUF lpBuffers,
  DWORD dwBufferCount,
  LPDWORD lpNumberOfBytesSent,
  DWORD dwFlags,
  LPWSAOVERLAPPED lpOverlapped,
  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSASend IN ws2_32;
	INTEGER s,;
	STRING @lpBuffers,;
	LONG dwBufferCount,;
	LONG @lpNumberOfBytesSent,;
	LONG dwFlags,;
	INTEGER lpOverlapped,;
	INTEGER lpCompletionRoutine  
```  
***  


## Parameters:
s 
[in] A descriptor that identifies a connected socket. 

lpBuffers 
[in] A pointer to an array of WSABUF structures. Each WSABUF structure contains a pointer to a buffer and the length, in bytes, of the buffer.

dwBufferCount 
[in] Number of WSABUF structures in the lpBuffers array. 

lpNumberOfBytesSent 
[out] A pointer to the number, in bytes, sent by this call if the I/O operation completes immediately.

dwFlags 
[in] Flags used to modify the behavior of the WSASend function call. For more information, see Using dwFlags in the Remarks section. 

lpOverlapped 
[in] A pointer to a WSAOVERLAPPED structure. This parameter is ignored for nonoverlapped sockets. 

lpCompletionRoutine 
[in] A pointer to the completion routine called when the send operation has been completed.  
***  


## Return value:
If no error occurs and the send operation has completed immediately, WSASend returns zero.  
***  

