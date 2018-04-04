[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSACloseEvent
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSACloseEvent function closes an open event object handle.
***  


## Code examples:
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
BOOL WSACloseEvent(
  WSAEVENT hEvent
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSACloseEvent IN ws2_32;
	INTEGER hEvent  
```  
***  


## Parameters:
hEvent 
[in] Object handle identifying the open event.   
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
The handle to the event object is closed so that further references to this handle will fail with the error WSA_INVALID_HANDLE.  
  
***  

