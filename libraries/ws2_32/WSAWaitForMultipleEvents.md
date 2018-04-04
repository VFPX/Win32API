[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAWaitForMultipleEvents
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The WSAWaitForMultipleEvents function returns either when one or all of the specified event objects are in the signaled state, or when the time-out interval expires.
***  


## Code examples:
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  

## Declaration:
```foxpro  
DWORD WSAWaitForMultipleEvents(
  DWORD cEvents,
  const WSAEVENT* lphEvents,
  BOOL fWaitAll,
  DWORD dwTimeout,
  BOOL fAlertable
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAWaitForMultipleEvents IN ws2_32;
	INTEGER   cEvents,;
	INTEGER @ lphEvents,;
	INTEGER   fWaitAll,;
	INTEGER   dwTimeout,;
	INTEGER   fAlertable
  
```  
***  


## Parameters:
cEvents 
[in] Indicator specifying the number of event object handles in the array pointed to by lphEvents.

lphEvents 
[in] Pointer to an array of event object handles. 

fWaitAll 
[in] Indicator specifying the wait type.

dwTimeout 
[in] Indicator specifying the time-out interval, in milliseconds.

fAlertable 
[in] Indicator specifying whether the function returns when the system queues an I/O completion routine for execution by the calling thread.  
***  


## Return value:
If the WSAWaitForMultipleEvents function succeeds, the return value indicates the event object that caused the function to return.  
***  


## Comments:
Related functions: WSACloseEvent, WSAEventSelect, WSACreateEvent.  
  
***  

