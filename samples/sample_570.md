[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: resolving an address to a host name

## Before you begin:
See also:

* [Retrieving the host information corresponding to a network address](sample_217.md)  
  
***  


## Code:
```foxpro  
#DEFINE AF_INET 2
#DEFINE NI_MAXHOST 1025
#DEFINE NI_MAXSERV 32

#DEFINE NI_NOFQDN 1
#DEFINE NI_NUMERICHOST 2
#DEFINE NI_NAMEREQD 4
#DEFINE NI_NUMERICSERV 8
#DEFINE NI_DGRAM 0x16

DO declare

IF NOT InitWinsock()
	MESSAGEBOX("Winsock Library initialization failed!",;
		48, "Error")
	RETURN
ENDIF

LOCAL cSocaddrIn, cHostName, cServiceName,;
	cIpAddress, nPort, nFlags, nResult

* 21 = ftp
* 25 = smtp
* 80 = hhtp
* 110 = pop3
* 443 = https

cIpAddress = "212.58.244.67"
nPort = 80
nFlags = NI_NAMEREQD
cHostName = REPLICATE(CHR(0), NI_MAXHOST)
cServiceName = REPLICATE(CHR(0), NI_MAXSERV)

cSocaddrIn = GetSocaddrIn(cIpAddress, nPort)

nResult = getnameinfo(@cSocaddrIn, LEN(cSocaddrIn),;
	@cHostName, NI_MAXHOST,;
	@cServiceName, NI_MAXSERV,;
	nFlags)

IF nResult = 0
	cHostName = STRTRAN(cHostName, CHR(0), "")
	cServiceName = STRTRAN(cServiceName, CHR(0), "")
	? cHostName
	? cServiceName
ELSE
* WSANO_DATA = 1104 : The requested name is valid,
* but does not have an Internet IP address at the name server.
	? "Winsock error:", WSAGetLastError()
ENDIF

= WSACleanup()
* end of main

FUNCTION InitWinsock
#DEFINE WSADATA_SIZE  398
#DEFINE WS_VERSION    0x0202
	DECLARE INTEGER WSAStartup IN ws2_32;
		INTEGER wVerRq, STRING @lpWSAData
	LOCAL cWSADATAln, nInitResult
	cWSADATA = REPLICATE(CHR(0), WSADATA_SIZE)
	nInitResult = WSAStartup(WS_VERSION, @cWSADATA)
RETURN (nInitResult=0)

FUNCTION GetSocaddrIn(cIP As String,;
	nPort As Number) As String
	LOCAL cBuffer, cPort, cHost
	cPort = num2word(htons(nPort))
	cHost = num2dword(inet_addr(cIP))
RETURN num2word(AF_INET) + m.cPort +;
	m.cHost + REPLICATE(CHR(0),8)

PROCEDURE declare
	DECLARE INTEGER inet_addr IN ws2_32 STRING cp
	DECLARE INTEGER htons IN ws2_32 INTEGER hostshort
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER WSAGetLastError IN ws2_32

	DECLARE INTEGER getnameinfo IN ws2_32;
		STRING @sockaddr, INTEGER salen,;
		STRING @host, LONG hostlen,;
		STRING @serv, LONG servlen,;
		INTEGER procFlags

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
[getnameinfo](../libraries/ws2_32/getnameinfo.md)  
[htons](../libraries/ws2_32/htons.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  

## Comment:
The getnameinfo function deprecates the gethostbyaddr function.  
  
***  

