[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: retrieving Web pages using sockets (HTTP, port 80)

## Before you begin:
Retrieved data is stored in a Memo field of a cursor.   
  
***  


## Code:
```foxpro  
#DEFINE AF_INET      2
#DEFINE SOCK_STREAM  1
#DEFINE IPPROTO_TCP  6
#DEFINE SOCKET_ERROR   -1
#DEFINE INVALID_SOCKET -1
#DEFINE CrLf  Chr(13)+Chr(10)
DO decl

IF WSAStartup(0x202, Repli(Chr(0),512)) = 0
	= HTTPGetData("http://www.west-wind.com/")
	= HTTPGetData("http://www.foxcentral.net/")
	= HTTPGetData("http://www.universalthread.com/")
	= HTTPGetData("http://www.dotcomsolution.com/activevfp.asp")
	= HTTPGetData("http://fox.wikis.com/wc.dll?Wiki~RecentChanges")
	= HTTPGetData("http://www.allapi.net/apilist/FindExecutable.shtml")

	= HTTPGetData("http://download.microsoft.com/download/vfox60/" +;
		"Install/6.0/W9X2K/EN-US/Gotchas.zip")

	= HTTPGetData("http://download.microsoft.com/download/vfox60/" +;
		"Install/6.0/W9X2K/EN-US/gps0311.zip")

	= WSACleanup()
	IF USED("csView")
		GO TOP
		BROW NORMAL NOWAIT
	ENDIF
ENDIF
* end of main

PROCEDURE HTTPGetData(cUrl)
#DEFINE READ_SIZE 1024  && reading with blocks of this size
	LOCAL cServer, cIP, hSocket, cRq, cRecv, cBuffer
	cServer = UrlGetServer(cUrl)
	cIP = GetIP(cServer)

	IF EMPTY(cIP)
		? "Host Database is not available or [" + cUrl + "] can not be found."
		RETURN
	ENDIF

	cBuffer = ""

	? cUrl, cIP

	* creating socket -- Internet address family
	hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)

	IF hSocket = INVALID_SOCKET
		? "Invalid socket"
		RETURN .F.
	ENDIF

	IF ConnectTo(hSocket, cIP, 80)
		* assembling a request string
		cRq = "GET " + cUrl + " HTTP/1.0" + CrLf +;
			"User-Agent: win32vfp" + CrLf +;
			"Referer: Using Sockets sample code" + CrLf+CrLf

		* sending data to connected socket
		IF send(hSocket, @cRq, Len(cRq), 0) <> SOCKET_ERROR
		* receiving data in a loop until zero length block returned
			cRecv = Repli(Chr(0), READ_SIZE)
			DO WHILE .T.
				nRecv = recv(hSocket, @cRecv, READ_SIZE, 0)
				IF nRecv = 0
					EXIT
				ELSE
					cBuffer = cBuffer + LEFT(cRecv, nRecv)
					?? "."
				ENDIF
			ENDDO
		ENDIF
	ENDIF
	= closesocket(hSocket)
	?? Len(cBuffer), "bytes"

	* saving returned data in a cursor
	IF Not USED("csView")
		CREATE CURSOR csView (datalen I, content M, ip C(15), url C(200))
	ENDIF
	INSERT INTO csView VALUES(Len(cBuffer), cBuffer, cIP, cUrl)

FUNCTION ConnectTo(hSocket, cHostIP, nPort)
* connects to remote host through a specified socket
	LOCAL cBuffer, cPort, cHost
	cPort = num2word(htons(nPort))
	nHost = inet_addr(cHostIP)
	cHost = num2dword(nHost)
	cBuffer = num2word(AF_INET) + cPort + cHost + Repli(Chr(0),8)
RETURN (ws_connect(hSocket, @cBuffer, Len(cBuffer))=0)

FUNCTION IsDataAvailable(hSocket)
* checks if there is data available to read from the socket
	LOCAL cRead, cWrite, cError, nCount
	STORE num2dword(1) + num2dword(hSocket) TO cRead, cWrite, cError
	nCount = ws_select(0, @cRead, @cWrite, @cError, 0)
RETURN (buf2dword(SUBSTR(cRead,1,4)) > 0)

FUNCTION GetIP(cServer)
* returns IP like 127.0.0.1 for a given server name like www.somwhere.com
#DEFINE HOSTENT_SIZE 16
	LOCAL nStruct, nSize, cBuffer, nAddr, cIP
	nStruct = gethostbyname(cServer)
	IF nStruct = 0
		RETURN ""
	ENDIF
	cBuffer = Repli(Chr(0), HOSTENT_SIZE)
	cIP = Repli(Chr(0), 4)
	= CopyMemory(@cBuffer, nStruct, HOSTENT_SIZE)
	= CopyMemory(@cIP, buf2dword(SUBS(cBuffer,13,4)),4)
	= CopyMemory(@cIP, buf2dword(cIP),4)
RETURN inet_ntoa(buf2dword(cIP))

FUNCTION UrlGetServer(cUrl)
* returns server name from a given Url string
#DEFINE URL_PART_HOSTNAME 2
	LOCAL nBuflen, cBuffer
	nBuflen = 1024
	cBuffer = Repli(Chr(0), nBuflen)
	= UrlGetPart(cUrl, @cBuffer, @nBuflen, URL_PART_HOSTNAME, 0)
RETURN SUBSTR(cBuffer, 1,AT(Chr(0),cBuffer)-1)

PROCEDURE decl
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING lpWSAData
	DECLARE INTEGER socket IN ws2_32 INTEGER af, INTEGER tp, INTEGER pt
	DECLARE INTEGER gethostbyname IN ws2_32 STRING host
	DECLARE INTEGER closesocket IN ws2_32 INTEGER s
	DECLARE INTEGER htons IN ws2_32 INTEGER hostshort
	DECLARE STRING inet_ntoa IN ws2_32 INTEGER in_addr
	DECLARE INTEGER inet_addr IN ws2_32 STRING cp

	DECLARE INTEGER connect IN ws2_32 AS ws_connect;
		INTEGER s, STRING @sname, INTEGER namelen

	DECLARE INTEGER select IN ws2_32 AS ws_select;
		INTEGER nfds, STRING @readfds, STRING @writefds,;
		STRING @exceptfds, INTEGER tmout

	DECLARE INTEGER send IN ws2_32;
		INTEGER s, STRING @buf, INTEGER buflen, INTEGER flags

	DECLARE INTEGER recv IN ws2_32;
		INTEGER s, STRING @buf, INTEGER buflen, INTEGER flags

	DECLARE INTEGER UrlGetPart IN shlwapi;
		STRING pszIn, STRING @pszOut, INTEGER @pcchOut,;
		INTEGER dwPart, INTEGER dwFlags

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Src, INTEGER nLength

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBS(lcBuffer, 2,1)),8) +;
	BitLShift(Asc(SUBS(lcBuffer, 3,1)),16) +;
	BitLShift(Asc(SUBS(lcBuffer, 4,1)),24)

FUNCTION num2dword(lnValue)
#DEFINE m0 256
#DEFINE m1 65536
#DEFINE m2 16777216
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
[UrlGetPart](../libraries/shlwapi/UrlGetPart.md)  
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[closesocket](../libraries/ws2_32/closesocket.md)  
[gethostbyname](../libraries/ws2_32/gethostbyname.md)  
[htons](../libraries/ws2_32/htons.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  
[inet_ntoa](../libraries/ws2_32/inet_ntoa.md)  
[recv](../libraries/ws2_32/recv.md)  
[send](../libraries/ws2_32/send.md)  
[socket](../libraries/ws2_32/socket.md)  

## Comment:
As well you can store received data in a temporary file and load this file to a browser.  
  
Same functionality can be achieved using Wininet functions -- InternetOpenUrl, HttpOpenRequest -- or using the URLDownloadToFile function from URL Monikers.  

***  

