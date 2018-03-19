[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: retrieving the host information corresponding to a network address

## Before you begin:
See also:

* [Resolving an address to a host name](sample_570.md)  
  
***  


## Code:
```foxpro  
DO declare

IF Not InitWinsock()
	RETURN
ENDIF

#DEFINE AF_UNSPEC      0  && unspecified
#DEFINE AF_UNIX        1  && local to host (pipes, portals)
#DEFINE AF_INET        2 && internetwork: UDP, TCP, etc.
#DEFINE AF_IMPLINK     3  && arpanet imp addresses
#DEFINE AF_PUP         4  && pup protocols: e.g. BSP
#DEFINE AF_CHAOS       5  && mit CHAOS protocols
#DEFINE AF_IPX         6  && IPX and SPX
#DEFINE AF_NS          6  && XEROX NS protocols
#DEFINE AF_ISO         7  && ISO protocols
#DEFINE AF_OSI         7  && OSI is ISO
#DEFINE AF_ECMA        8  && european computer manufacturers
#DEFINE AF_DATAKIT     9  && datakit protocols
#DEFINE AF_CCITT      10  && CCITT protocols, X.25 etc
#DEFINE AF_SNA        11  && IBM SNA
#DEFINE AF_DECnet     12  && DECnet
#DEFINE AF_DLI        13  && Direct data link interface
#DEFINE AF_LAT        14  && LAT
#DEFINE AF_HYLINK     15  && NSC Hyperchannel
#DEFINE AF_APPLETALK  16  && AppleTalk
#DEFINE AF_NETBIOS    17  && NetBios-style addresses
#DEFINE AF_VOICEVIEW  18  && VoiceView
#DEFINE AF_FIREFOX    19  && FireFox
#DEFINE AF_UNKNOWN1   20  && Somebody is using this!
#DEFINE AF_BAN        21  && Banyan
#DEFINE AF_MAX        22

LOCAL lnIP, lnHOSTENTptr, lcHOSTENT

lnIP = inet_addr("64.4.45.7")
lnHOSTENTptr = gethostbyaddr(@lnIP, 4, AF_INET)

IF lnHOSTENTptr = 0
* WSAEINTR          = 10004
* WSAEFAULT         = 10014
* WSAEINPROGRESS    = 10036
* WSAEAFNOSUPPORT   = 10047
* WSAENETDOWN       = 10050
* WSANOTINITIALISED = 10093
* WSAHOST_NOT_FOUND = 11001
* WSATRY_AGAIN      = 11002
* WSANO_RECOVERY    = 11003
* WSANO_DATA        = 11004 - Valid name, no data of requested type

	? "Winsock error code:", WSAGetLastError()
ELSE
#DEFINE HOSTENT_SIZE 16
	lcHOSTENT = GetMemBuf(lnHOSTENTptr, HOSTENT_SIZE)
	? "Host name:", GetMemStr(buf2dword(SUBSTR(lcHOSTENT, 1,4)))
ENDIF

* releasing Ws2_32 library
= WSACleanup()
* End of Main

FUNCTION InitWinsock()
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup(WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

FUNCTION GetMemBuf(lnAddr, lnBufsize)
* returning data from a memory block
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), lnBufsize)
	= Heap2Str(@lcBuffer, lnAddr, lnBufsize)
RETURN m.lcBuffer

FUNCTION GetMemStr(lnAddr)
* returning data from a memory block
* before the first occurence of a zero byte
	LOCAL lcBuffer
	lcBuffer = GetMemBuf(lnAddr, 250)
RETURN SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE declare
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER WSAGetLastError IN ws2_32

	DECLARE INTEGER WSAStartup IN ws2_32;
		INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER gethostbyaddr IN ws2_32;
		INTEGER @addr, INTEGER addrLen,;
		INTEGER addrType

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength

	DECLARE INTEGER inet_addr IN ws2_32 STRING cp  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAGetLastError](../libraries/ws2_32/WSAGetLastError.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[gethostbyaddr](../libraries/ws2_32/gethostbyaddr.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  

## Comment:
The gethostbyaddr function has been deprecated by the introduction of the getnameinfo function.  
  
***  

