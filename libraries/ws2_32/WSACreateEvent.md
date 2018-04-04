[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSACreateEvent
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSACreateEvent function creates a new event object.
***  


## Code examples:
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
WSAEVENT WSACreateEvent(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSACreateEvent IN ws2_32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
If no error occurs, WSACreateEvent returns the handle of the event object. Otherwise, the return value is WSA_INVALID_EVENT.  
***  


## Comments:
The scope of an event object is limited to the process in which it is created.  
  
***  

