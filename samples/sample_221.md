[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: changing the byte ordering

## Code:
```foxpro  
* you do not need to call the WSAStartup function
* before using these functions

DECLARE INTEGER ntohs IN ws2_32 INTEGER netshort
DECLARE INTEGER ntohl IN ws2_32 INTEGER netlong
DECLARE INTEGER htonl IN ws2_32 INTEGER hostlong
DECLARE INTEGER htons IN ws2_32 INTEGER hostshort
	
* HOST to NET  u_short -- htons
* NET  to HOST u_short -- ntohs
* HOST to NET  u_long  -- htonl
* NET  to HOST u_long  -- ntohl
	
? "*** Working with U_SHORT values"
lnFtpPort = htons(21)
? "Converted to the network byte order:",lnFtpPort
? "Host byte order again:", ntohs(lnFtpPort)
?
	
? "*** Working with U_LONG values"
lnTelnetPort = htonl(23)
? "Converted to the network byte order:", lnTelnetPort
? "Host byte order again:", ntohl(lnTelnetPort)
?	

DECLARE INTEGER inet_addr IN ws2_32 STRING cp
DECLARE STRING inet_ntoa IN ws2_32 INTEGER in_addr

* The inet_addr function converts a string containing an (Ipv4)
* Internet Protocol dotted address into a proper address
* for the IN_ADDR structure
? "*** Converting IP addresses"
lnIP = inet_addr("127.0.0.1")
? "String value converted into a proper address:", lnIP
	
* The inet_ntoa function converts an (Ipv4) Internet network address
* into a string in Internet standard dotted format
? "Converted back to a string value:", inet_ntoa (lnIP)  
```  
***  


## Listed functions:
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[htonl](../libraries/ws2_32/htonl.md)  
[htons](../libraries/ws2_32/htons.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  
[inet_ntoa](../libraries/ws2_32/inet_ntoa.md)  
[ntohl](../libraries/ws2_32/ntohl.md)  
[ntohs](../libraries/ws2_32/ntohs.md)  
