[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to build UDP responder

## Before you begin:
The goal was to create a VFP application for receiving UDP packet from a client and responding to the same client using the IP address and the port obtained from the initial packet. The *sockaddr* structure that the recvfrom call populates contains required information.  

The UdpBase class uses several Winsock API functions. It implements the basic functionality such as creates a UDP socket and binds it to a local port. After that the class can use this socket for sending and receiving datagrams.  

The WaitForRequest method of the class indefinitely waits for incoming datagrams. Upon receiving a datagram it sends a message back to the client.  

```foxpro
DEFINE CLASS UdpServer As UdpBase  

PROCEDURE WaitForRequest(nPort)  
	IF NOT THIS.StartServer(nPort)  
		RETURN .F.  
	ELSE  
		? "Waiting for incoming requests on " +;  
			THIS.LocalIP + ":" +;  
			TRANSFORM(THIS.LocalPort) + "..."  
	ENDIF  

	* waits indefinitely for a request from a client  
	* on local ip address and port specified in nPort  
	THIS.ReceiveDatagram  

	IF EMPTY(THIS.SenderIP) OR EMPTY(THIS.SenderPort)  
	* failed to get a response or   
	* when defining the source of the response  
		RETURN .F.  
	ELSE  
	* displays request received  
		? "Request received from " + THIS.SenderIP +;  
			":" + TRANSFORM(THIS.SenderPort)  
		? THIS.DataReceived  
	ENDIF  

	* assemble a data to be sent back to client  
	LOCAL cConfirmation  
	cConfirmation = "Responder: " + SYS(0) +;  
		" " + TTOC(DATETIME())  

	* sends data back to client  
	* the client is supposed to be in listening mode  
	THIS.SendDatagram(m.cConfirmation,;  
		THIS.SenderIP, THIS.SenderPort)  

ENDDEFINE
```
See also:

* [How to create non-blocking Winsock server](sample_412.md)  
  
***  


## Code:
```foxpro  
#DEFINE AF_INET 2
#DEFINE SOCK_DGRAM 2
#DEFINE IPPROTO_UDP 17
#DEFINE SOCKET_ERROR -1
#DEFINE INVALID_SOCKET 0
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
#DEFINE SOMAXCONN 0x7FFFFFFF

DEFINE CLASS UdpClient As UdpBase

PROCEDURE SendRequest(nLocalPort, cData, cRemoteIP, nRemotePort)
	IF NOT THIS.StartServer(nLocalPort)
		= MESSAGEBOX(TRANSFORM(THIS.errorno) + ". " +;
			THIS.errormessage + "     ", 48,;
			"Failed to create UDP socket on port " +;
			TRANSFORM(m.nLocalPort))
		RETURN .F.
	ENDIF

	* sends data to server specified by cRemoteIP, nRemotePort
	* the server is supposed to be in listening mode
	THIS.SendDatagram(m.cData, cRemoteIP, nRemotePort)
	
	* waits indefinitely for a response from server
	* on local ip address and port specified in nLocalPort
	THIS.ReceiveDatagram

	IF EMPTY(THIS.SenderIP) OR EMPTY(THIS.SenderPort)
	* failed to get a response or to define the source of the response
		= MESSAGEBOX(TRANSFORM(THIS.errorno) + ". " +;
			THIS.errormessage + "     ", 48, "Error")
		EXIT
	ELSE
	* displays response received
		? "Response received from " +;
			THIS.SenderIP + ":" + TRANSFORM(THIS.SenderPort)
		? THIS.DataReceived
	ENDIF
ENDDEFINE

DEFINE CLASS UdpServer As UdpBase

PROCEDURE WaitForRequest(nLocalPort)
	IF NOT THIS.StartServer(nLocalPort)
		= MESSAGEBOX(TRANSFORM(THIS.errorno) + ". " +;
			THIS.errormessage + "     ", 48,;
			"Failed to create UDP socket on port " +;
			TRANSFORM(m.nLocalPort))
		RETURN .F.
	ELSE
		? "Waiting for incoming requests on " +;
			THIS.LocalIP + ":" + TRANSFORM(THIS.LocalPort) + "..."
	ENDIF
	
	* waits indefinitely for a request from a client
	* on local ip address and port specified in nLocalPort
	THIS.ReceiveDatagram

	IF EMPTY(THIS.SenderIP) OR EMPTY(THIS.SenderPort)
	* failed to get a response or to define the source of the response
		= MESSAGEBOX(TRANSFORM(THIS.errorno) + ". " +;
			THIS.errormessage + "     ", 48, "Error")
		EXIT
	ELSE
	* displays request received
		? "Request received from " + THIS.SenderIP + ":" + TRANSFORM(THIS.SenderPort)
		? THIS.DataReceived
	ENDIF
	
	* assemble a data to be sent back to client
	LOCAL cConfirmation
	cConfirmation = "Responder: " + SYS(0) + " " + TTOC(DATETIME())
	
	* sends data back to client
	* the client is supposed to be in listening mode
	THIS.SendDatagram(m.cConfirmation,;
		THIS.SenderIP, THIS.SenderPort)
	
ENDDEFINE

DEFINE CLASS UdpBase As Session
	errorno=0
	errormessage=""
	LocalIP=""
	LocalName=""
	LocalPort=0
	hSocket=0
	SenderIP=""
	SenderPort=""
	DataReceived=""

PROCEDURE Init
	THIS.declare
	IF NOT THIS.InitWinsock()
		THIS.SetLastError(-1,;
			"Failed to initialize Winsock on this computer.")
		RETURN .F.
	ENDIF
	THIS.GetLocalIP

PROCEDURE StartServer(nLocalPort)
	THIS.StopServer
	THIS.LocalPort = m.nLocalPort
	THIS.hSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)

	LOCAL cBindBuffer, nError
	cBindBuffer = THIS.GetBindBuf(THIS.LocalIP, THIS.LocalPort)

	IF ws_bind(THIS.hSocket, @cBindBuffer, LEN(m.cBindBuffer)) <> 0
		THIS.SetLastError(WSAGetLastError(),;
			"Failed to bind the socket to local address.")
		RETURN .F.
	ENDIF
RETURN .T.

PROCEDURE StopServer
	IF THIS.hSocket <> 0
		IF closesocket(THIS.hSocket) = 0
			THIS.hSocket=0
		ELSE
			THIS.SetLastError(WSAGetLastError(),;
				"Call to closesocket() API failed.")
			RETURN .F.
		ENDIF
	ENDIF
RETURN .T.

PROCEDURE Destroy
	THIS.StopServer
	= WSACleanup()

PROTECTED PROCEDURE InitWinsock
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = REPLICATE(CHR(0), WSADATA_SIZE)
	lnInitResult = WSAStartup(WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

PROCEDURE ResetLastError
	THIS.SetLastError(0, "")

PROCEDURE SetLastError(nError, cMsg)
	THIS.errorno=m.nError
	THIS.errormessage=m.cMsg

PROTECTED PROCEDURE GetLocalIP
#DEFINE HOSTENT_SIZE 16
	LOCAL cBuffer, nResult, nAddr

	cBuffer = REPLICATE(CHR(0), 250)
	nResult = gethostname(@cBuffer, Len(cBuffer))

	THIS.LocalName = IIF(nResult=0,;
		SUBSTR(cBuffer, 1,AT(Chr(0),cBuffer)-1), "")

	nAddr = gethostbyname(THIS.LocalName)
	IF nAddr <> 0
		cBuffer = REPLICATE(CHR(0), HOSTENT_SIZE)
		= MemToStr(@cBuffer, nAddr, HOSTENT_SIZE)
		
		* obtain a pointer to the list of addresses
		nAddr = buf2dword(SUBSTR(cBuffer, 13,4))

		cBuffer = REPLICATE(CHR(0), 4)
		= MemToStr(@cBuffer, nAddr, 4)
		nAddr = buf2dword(cBuffer)
		= MemToStr(@cBuffer, nAddr, 4)
		nAddr = buf2dword(cBuffer)
		THIS.LocalIP = inet_ntoa(nAddr)
	ENDIF

FUNCTION SendDatagram(cData, cTargetIP, nTargetPort) As Number
	LOCAL cBindBuffer, nResult

	IF THIS.hSocket = INVALID_SOCKET
		THIS.SetLastError(WSAGetLastError(),;
			"SendDatagram: call to socket() API failed.")
		RETURN .F.
	ENDIF

	cBindBuffer = THIS.GetBindBuf(m.cTargetIP, m.nTargetPort)
	nResult = sendto(THIS.hSocket, @cData, LEN(m.cData),;
		0, @cBindBuffer, LEN(m.cBindBuffer))

	IF nResult = SOCKET_ERROR
		THIS.SetLastError(WSAGetLastError(),;
			"SendDatagram: call to sendto() API failed.")
	ENDIF
RETURN m.nResult

PROCEDURE ReceiveDatagram
	LOCAL cBuffer, cSockaddr, nSockaddrLen, nResult
	cBuffer = REPLICATE(CHR(0), 0x1000)
	nSockaddrLen=64
	cSockaddr = REPLICATE(CHR(0), nSockaddrLen)

	THIS.SenderIP=""
	THIS.SenderPort=0

	nResult = recvfrom(THIS.hSocket, @cBuffer, LEN(m.cBuffer),;
		0, @cSockaddr, @nSockaddrLen)

	IF nResult = SOCKET_ERROR
		THIS.SetLastError(WSAGetLastError(),;
			"ReceiveDatagram: call to recvfrom() API failed.")
	ENDIF

	THIS.SenderIP = inet_ntoa(buf2dword(SUBSTR(cSockaddr,5,4)))
	THIS.SenderPort = ASC(SUBSTR(m.cSockaddr, 3,1)) * 256 +;
		ASC(SUBSTR(m.cSockaddr, 4,1))
		
	IF nResult > 0
		THIS.DataReceived = SUBSTR(m.cBuffer, 1, m.nResult)
	ELSE
		THIS.DataReceived = ""
	ENDIF

PROTECTED FUNCTION GetBindBuf(cIP, nPort)
	LOCAL cBuffer, cPort, cHost
	cPort = num2word(BitClear(htons(nPort),16))
	cHost = num2dword(inet_addr(cIP))
RETURN num2word(AF_INET) + cPort + cHost + REPLICATE(CHR(0),8)

PROTECTED PROCEDURE declare
	DECLARE INTEGER inet_addr IN ws2_32 STRING cp
	DECLARE STRING inet_ntoa IN ws2_32 INTEGER in_addr
	DECLARE INTEGER htons IN ws2_32 INTEGER hostshort
	DECLARE INTEGER WSAGetLastError IN ws2_32
	DECLARE INTEGER closesocket IN ws2_32 INTEGER s
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER gethostbyname IN ws2_32 STRING hostname

	DECLARE INTEGER gethostname IN ws2_32;
		STRING @hstname, INTEGER namlen

	DECLARE INTEGER bind IN ws2_32 As ws_bind;
		INTEGER s, STRING @sockaddr, INTEGER namelen

	DECLARE INTEGER WSAStartup IN ws2_32;
		INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER socket IN ws2_32;
		INTEGER af, INTEGER socktype, INTEGER protocol

	DECLARE INTEGER recvfrom IN ws2_32;
		INTEGER s, STRING @buf, INTEGER buflen,;
		INTEGER rcvflags, STRING @sockaddr, INTEGER @fromlen

	DECLARE INTEGER sendto IN ws2_32;
		INTEGER s, STRING @buf, INTEGER buflen,;
		INTEGER wsflags, STRING @sendto, INTEGER tolen

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLen

	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER dst, STRING @src, INTEGER nLen

ENDDEFINE

*** static functions ***
FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAGetLastError](../libraries/ws2_32/WSAGetLastError.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[bind](../libraries/ws2_32/bind.md)  
[closesocket](../libraries/ws2_32/closesocket.md)  
[gethostbyname](../libraries/ws2_32/gethostbyname.md)  
[gethostname](../libraries/ws2_32/gethostname.md)  
[htons](../libraries/ws2_32/htons.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  
[inet_ntoa](../libraries/ws2_32/inet_ntoa.md)  
[recvfrom](../libraries/ws2_32/recvfrom.md)  
[sendto](../libraries/ws2_32/sendto.md)  
[socket](../libraries/ws2_32/socket.md)  

## Comment:
The <a href="http://en.wikipedia.org/wiki/User_Datagram_Protocol">User Datagram Protocol (UDP)</a> is one of the core Internet protocols. By using the UDP an application can send short messages, also known as datagrams, across the network.  
  
A datagram is a self-contained connectionless <a href="http://en.wikipedia.org/wiki/Packet">packet</a>, one which contains enough information in the header to allow the network to forward it to the destination independently of previous or future datagrams.  
  
***  

