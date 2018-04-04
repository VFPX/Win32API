[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : recv
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [ws2_32](../../Libraries.md#ws2_32)  
***  


#### The <Strong>recv</Strong> function receives data from a connected or bound socket.
***  


## Code examples:
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[Winsock: retrieving directory listing from an FTP server using passive data connection (FTP, port 21)](../../samples/sample_386.md)  
[Winsock: reading email messages (POP3, port 110)](../../samples/sample_388.md)  
[Winsock: connecting to a news server (NNTP, port 119)](../../samples/sample_389.md)  
[How to create non-blocking Winsock server](../../samples/sample_412.md)  

## Declaration:
```foxpro  
int recv(
  SOCKET s,
  char* buf,
  int len,
  int flags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER recv IN ws2_32;
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
[out] Buffer for the incoming data. 

len 
[in] Length of buf, in bytes 

flags 
[in] Flag specifying the way in which the call is made.   
***  


## Return value:
If no error occurs, recv returns the number of bytes received. If the connection has been gracefully closed, the return value is zero.  
***  

