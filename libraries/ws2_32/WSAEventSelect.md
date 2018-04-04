[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAEventSelect
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSAEventSelect function specifies an event object to be associated with the specified set of FD_XXX network events.
***  


## Code examples:
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
int WSAEventSelect(
  SOCKET s,
  WSAEVENT hEventObject,
  long lNetworkEvents
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAEventSelect IN ws2_32;
	INTEGER s,;
	INTEGER hEventObject,;
	INTEGER lNetworkEvents
  
```  
***  


## Parameters:
s 
[in] Descriptor identifying the socket. 

hEventObject 
[in] Handle identifying the event object to be associated with the specified set of FD_XXX network events. 

lNetworkEvents 
[in] Bitmask that specifies the combination of FD_XXX network events in which the application has interest.  
***  


## Return value:
The return value is zero if the application"s specification of the network events and the associated event object was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling WSAGetLastError.  
***  

