[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : send
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The <Strong>send</Strong> function sends data on a connected socket.

***  


## Code examples:
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[A client for testing non-blocking Winsock server](../../samples/sample_413.md)  

## Declaration:
```foxpro  
int send(
  SOCKET s,
  const char* buf,
  int len,
  int flags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER send IN ws2_32;
	INTEGER   s,;
	STRING  @ buf,;
	INTEGER   buflen,;
	INTEGER   flags
  
```  
***  


## Parameters:
s 
[in] Descriptor identifying a connected socket. 

buf 
[in] Buffer containing the data to be transmitted. 

len 
[in] Length of the data in buf, in bytes 

flags 
[in] Indicator specifying the way in which the call is made. 
  
***  


## Return value:
If no error occurs, send returns the total number of bytes sent, which can be less than the number indicated by len.  
***  

