[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: reading and setting socket options

## Code:
```foxpro  
#DEFINE AF_INET 2
#DEFINE SOCK_STREAM 1
#DEFINE SOCK_DGRAM 2
#DEFINE IPPROTO_TCP 6
#DEFINE INVALID_SOCKET -1

#DEFINE SOCKET_ERROR -1
#DEFINE SOL_SOCKET 0xffff  && options for socket level

* option flags per socket
#DEFINE SO_DEBUG         1  && turns on debugging info recording
#DEFINE SO_ACCEPTCONN    2  && socket has had listen() - READ-ONLY
#DEFINE SO_REUSEADDR     4  && allows local address reuse
#DEFINE SO_KEEPALIVE     8  && keeps connections alive
#DEFINE SO_DONTROUTE    16  && uses interface addresses only
#DEFINE SO_BROADCAST    32  && permits sending of broadcast msgs.
#DEFINE SO_USELOOPBACK  64  && bypasses hardware when possible
#DEFINE SO_LINGER      128  && lingers on close if data present
#DEFINE SO_OOBINLINE   256  && leaves received OOB data in line
#DEFINE SO_SNDBUF     4097  && send-buffer size
#DEFINE SO_RCVBUF     4098  && receive-buffer size
#DEFINE SO_ERROR      4103  && gets error status and clears
#DEFINE SO_TYPE       4104  && gets socket type - READ-ONLY

DO declare

= InitWinsock()

LOCAL hSocket
hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)

IF hSocket <> INVALID_SOCKET
	= SetSendBufferSize(hSocket, 16384)
	= PrintSocketData(hSocket)
	= closesocket(hSocket)
ENDIF

= WSACleanup()
* end of main

PROCEDURE SetSendBufferSize(hSocket, nBufsize As Long)
* sets the size of the sending buffer
	LOCAL nResult

	DECLARE INTEGER setsockopt IN ws2_32;
		INTEGER s, INTEGER level, INTEGER optname,;
		LONG @optval, INTEGER optlen

	nResult = setsockopt(hSocket, SOL_SOCKET,;
		SO_SNDBUF, @nBufsize, 4)

	IF nResult <> 0
		= MESSAGEBOX("setsockopt() call failed " +;
			"with error code: " +;
			TRANSFORM(WSAGetLastError()), 48, "WSA Error!")
	ENDIF

RETURN (m.nResult=0)

PROCEDURE PrintSocketData(hSocket)
	LOCAL cOutput

TEXT TO m.cOutput NOSHOW TEXTMERGE
Socket type:                   <<scIntOpt(hSocket, SO_TYPE)>>
RECV buffer size:              <<scIntOpt(hSocket, SO_RCVBUF)>>
SEND buffer size:              <<scIntOpt(hSocket, SO_SNDBUF)>>
Accepts connections:           <<scIntOpt(hSocket, SO_ACCEPTCONN)>>
Local address reuse allowed:   <<scIntOpt(hSocket, SO_REUSEADDR)>>
Keeps connections alive:       <<scIntOpt(hSocket, SO_KEEPALIVE)>>
Uses interface addresses only: <<scIntOpt(hSocket, SO_DONTROUTE)>>
Broadcasting permitted:        <<scIntOpt(hSocket, SO_BROADCAST)>>
Uses loopback :                <<scIntOpt(hSocket, SO_USELOOPBACK)>>
Is in debugging state:         <<scIntOpt(hSocket, SO_DEBUG)>>
Error status:                  <<scIntOpt(hSocket, SO_ERROR)>>
ENDTEXT
	? m.cOutput

FUNCTION scIntOpt(hSocket, lnOption)
* reading a DWORD socket option
	LOCAL lnResult, lcBuffer, lnBufsize
	lnBufsize = 4  && DWORD
	lcBuffer = Repli(Chr(0), lnBufsize)
	lnResult = getsockopt(hSocket, SOL_SOCKET,;
		lnOption, @lcBuffer, @lnBufsize)
RETURN  Iif(lnResult=SOCKET_ERROR, .F., buf2dword(lcBuffer))

FUNCTION InitWinsock()
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup(WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE declare
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER closesocket IN ws2_32 INTEGER s
	DECLARE INTEGER WSAGetLastError IN ws2_32

	DECLARE INTEGER WSAStartup IN ws2_32;
		INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER socket IN ws2_32;
		INTEGER af, INTEGER type, INTEGER protocol

	DECLARE INTEGER getsockopt IN ws2_32;
		INTEGER s, INTEGER level, INTEGER optname,;
		STRING @optval, INTEGER @optlen  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAGetLastError](../libraries/ws2_32/WSAGetLastError.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[closesocket](../libraries/ws2_32/closesocket.md)  
[getsockopt](../libraries/ws2_32/getsockopt.md)  
[setsockopt](../libraries/ws2_32/setsockopt.md)  
[socket](../libraries/ws2_32/socket.md)  

## Comment:
Check this article [HOWTO: Using getsockopt() and setsockopt() in Visual Basic (Q237688)](http://www.ecs.syr.edu/faculty/Fawcett/handouts/cse686/Summer01/Socket%20Stuff/Q237688%20-%20HOWTO%20Using%20getsockopt()%20and%20setsockopt()%20in%20Visual%20Basic.htm).  
  

***  

