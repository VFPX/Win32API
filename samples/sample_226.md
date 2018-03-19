[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: creating a socket that is bound to a specific service provider

## Code:
```foxpro  
#DEFINE SOCKET_ERROR    -1
#DEFINE INVALID_SOCKET  -1

* address family constants
#DEFINE AF_INET      2  && internetwork: UDP, TCP, etc.
#DEFINE AF_IPX       6  && IPX and SPX
#DEFINE AF_NETBIOS  17  && NetBios-style addresses

* socket type constants
#DEFINE SOCK_STREAM     1
#DEFINE SOCK_DGRAM      2
#DEFINE SOCK_RAW        3
#DEFINE SOCK_RDM        4
#DEFINE SOCK_SEQPACKET  5

* protocol constants
#DEFINE IPPROTO_IP      0
#DEFINE IPPROTO_TCP     6
#DEFINE IPPROTO_UDP    17
#DEFINE IPPROTO_RAW   255

DO decl

IF InitWinsock()
	LOCAL hSocket

	hSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)
	? "New socket:", hSocket

	IF hSocket <> INVALID_SOCKET
		? "Closing the socket:",;
			Iif(closesocket(hSocket)=0, "Ok","Error")
	ENDIF

	= WSACleanup()
ENDIF
* End of Main

FUNCTION  InitWinsock()
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup (WS_VERSION, @lcWSADATA)
RETURN  (lnInitResult = 0)

PROCEDURE  decl
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData
	DECLARE INTEGER WSACleanup IN ws2_32

	DECLARE INTEGER closesocket IN ws2_32 INTEGER s
	DECLARE INTEGER socket IN ws2_32;
		INTEGER af, INTEGER type, INTEGER protocol  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[closesocket](../libraries/ws2_32/closesocket.md)  
[socket](../libraries/ws2_32/socket.md)  
