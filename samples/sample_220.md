[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: how to retrieve a service information corresponding to a service name

## Code:
```foxpro  
DO decl

IF InitWinsock()
	= DisplayServInfo ("pop3")
	= DisplayServInfo ("smtp")
	= DisplayServInfo ("news")
	= DisplayServInfo ("ftp")
	= DisplayServInfo ("telnet")
	= DisplayServInfo ("talk")
	= DisplayServInfo ("exec")
	= DisplayServInfo ("biff")

	= WSACleanup()
ENDIF
* End of Main

PROCEDURE  DisplayServInfo (lcServName)
*| struct servent {
*|   char FAR *        s_name;      0:4
*|   char FAR * FAR *  s_aliases;   4:4
*|   short             s_port;      8:4
*|   char FAR *        s_proto;    12:4
*| }; total bytes = 16
#DEFINE SERVENT_SIZE  16

	LOCAL lnServentPtr, lcBuffer, lcService, lnPort, lcProt, lcAliases
	lnServentPtr = getservbyname (lcServName, .NULL.)
	IF lnServentPtr = 0
	* no service found with this name
		? lcProt
		RETURN
	ENDIF

	lcBuffer = Repli(Chr(0), SERVENT_SIZE)
	= Heap2Str (@lcBuffer, lnServentPtr, SERVENT_SIZE)

	lcService = GetMemStr(buf2dword(SUBSTR(lcBuffer, 1,4)))
	lcAliases = GetAliases(buf2dword(SUBSTR(lcBuffer, 5,4)))
	lnPort    = htons(buf2word(SUBSTR(lcBuffer, 9,2)))
	lcProt    = GetMemStr(buf2dword(SUBSTR(lcBuffer, 13,4)))
	
	? PADR(lcService,20), STR(lnPort,5), PADR(lcProt,12), lcAliases
RETURN

FUNCTION  GetAliases (lnArrayPtr)
* returns a string with alternate names for the service
* delimited with semicolons
	IF lnArrayPtr = 0
		EXIT
	ENDIF

	LOCAL lcResult, lnDataPtr, lcAlias
	lcResult = ""

	DO WHILE .T.
		* each array element contains a pointer to data
		lnDataPtr = buf2dword(GetMemBuf(lnArrayPtr, 4))

		IF lnDataPtr <> 0
			lcAlias = GetMemStr(lnDataPtr)
			lcResult = lcResult +;
				Iif(Empty(lcResult), "",";") + lcAlias
		ELSE
		* the last array element contains null
			EXIT
		ENDIF
		lnArrayPtr = lnArrayPtr + 4  && next array element
	ENDDO
RETURN  lcResult

FUNCTION  InitWinsock()
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup (WS_VERSION, @lcWSADATA)
RETURN  (lnInitResult = 0)

FUNCTION  GetMemBuf (lnAddr, lnBufsize)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), lnBufsize)
	= Heap2Str (@lcBuffer, lnAddr, lnBufsize)
RETURN  lcBuffer

FUNCTION  GetMemStr (lnAddr)
* returning data from a memory block
* before the first occurence of a zero byte
	LOCAL lcBuffer
	lcBuffer = GetMemBuf (lnAddr, 250)
RETURN  SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER getservbyname IN ws2_32 STRING name, STRING proto
	DECLARE INTEGER htons IN ws2_32 INTEGER hostshort

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[getservbyname](../libraries/ws2_32/getservbyname.md)  
[htons](../libraries/ws2_32/htons.md)  
