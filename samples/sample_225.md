[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: how to retrieve the protocol information corresponding to a protocol number

## Code:
```foxpro  
DO decl

IF InitWinsock()
	CREATE CURSOR cs (protno N(5), protname C(20), aliases C(50))
	FOR ii=0 TO 128
		= DisplayProtInfo (ii)
	ENDFOR

	= WSACleanup()
	GO TOP
	BROW NORMAL NOWAIT
ENDIF
* End of Main

PROCEDURE  DisplayProtInfo (lnIndex)
	LOCAL lnProtoentPtr
	lnProtoentPtr = getprotobynumber (lnIndex)

	IF lnProtoentPtr = 0
	* no protocol found with this protocol number
		RETURN
	ENDIF

*| struct protoent {
*|   char FAR *        p_name;     0:4
*|   char FAR * FAR *  p_aliases;  4:4
*|   short             p_proto;    8:4
*| }; total bytes = 12
#DEFINE PROTOENT_SIZE  12

	LOCAL lcBuffer, lcProt, lcAliases, lnProt
	lcBuffer = Repli(Chr(0), PROTOENT_SIZE)
	= Heap2Str (@lcBuffer, lnProtoentPtr, PROTOENT_SIZE)

	lcProt    = GetMemStr(buf2dword(SUBSTR(lcBuffer, 1,4)))
	lcAliases = GetAliases(buf2dword(SUBSTR(lcBuffer, 5,4)))
	lnProt    = buf2word(SUBSTR(lcBuffer, 9,2))
	
	INSERT INTO cs VALUES (lnProt, lcProt, lcAliases)
RETURN

FUNCTION  GetAliases (lnArrayPtr)
* returns a string with alternate names for the protocol
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
	DECLARE INTEGER getprotobynumber IN ws2_32 INTEGER number

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[getprotobynumber](../libraries/ws2_32/getprotobynumber.md)  
