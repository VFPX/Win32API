[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAConnect
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### Establishes a connection to another socket application, exchanges connect data, and specifies required quality of service based on the specified FLOWSPEC structure.

***  


## Code examples:
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
int WSAConnect(
  SOCKET s,
  const struct sockaddr* name,
  int namelen,
  LPWSABUF lpCallerData,
  LPWSABUF lpCalleeData,
  LPQOS lpSQOS,
  LPQOS lpGQOS
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAConnect IN ws2_32;
	INTEGER s,;
	STRING @sname,;
	INTEGER namelen,;
	INTEGER lpCallerData,;
	INTEGER lpCalleeData,;
	INTEGER lpSQOS,;
	INTEGER lpGQOS  
```  
***  


## Parameters:
s 
[in] Descriptor identifying an unconnected socket. 

name 
[in] Name of the socket in a sockaddr structure in the other application to which to connect. 

namelen 
[in] Length of name, in bytes. 

lpCallerData 
[in] Pointer to the user data that is to be transferred to the other socket during connection establishment. See Remarks. 

lpCalleeData 
[out] Pointer to the user data that is to be transferred back from the other socket during connection establishment. See Remarks. 

lpSQOS 
[in] Pointer to the FLOWSPEC structures for socket s, one for each direction. 

lpGQOS 
[in] Reserved for future use with socket groups. A pointer to the FLOWSPEC structures for the socket group (if applicable). Should be NULL.   
***  


## Return value:
If no error occurs, WSAConnect returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling WSAGetLastError.  
***  

