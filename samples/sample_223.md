[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: retrieving information about available transport protocols

## Code:
```foxpro  
*| typedef struct _WSAPROTOCOLCHAIN {
*|   int   ChainLen;
*|   DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
*| } WSAPROTOCOLCHAIN, *LPWSAPROTOCOLCHAIN; total bytes = 32

*| typedef struct _WSAPROTOCOL_INFO {
*|   DWORD            dwServiceFlags1;             0:4
*|   DWORD            dwServiceFlags2;             4:4
*|   DWORD            dwServiceFlags3;             8:4
*|   DWORD            dwServiceFlags4;            12:4
*|   DWORD            dwProviderFlags;            16:4
*|   GUID             ProviderId;                 20:16
*|   DWORD            dwCatalogEntryId;           36:4
*|   WSAPROTOCOLCHAIN ProtocolChain;              40:32
*|   int              iVersion;                   72:4
*|   int              iAddressFamily;             76:4
*|   int              iMaxSockAddr;               80:4
*|   int              iMinSockAddr;               84:4
*|   int              iSocketType;                88:4
*|   int              iProtocol;                  92:4
*|   int              iProtocolMaxOffset;         96:4
*|   int              iNetworkByteOrder;         100:4
*|   int              iSecurityScheme;           104:4
*|   DWORD            dwMessageSize;             108:4
*|   DWORD            dwProviderReserved;        112:4
*|   TCHAR            szProt[WSAPROTOCOL_LEN+1]; 116:256
*| } WSAPROTOCOL_INFO, *LPWSAPROTOCOL_INFO; total bytes = 372

#DEFINE WSAPROTOCOL_INFO_SIZE  372
#DEFINE WSAPROTOCOL_LEN        255
#DEFINE MAX_PROTOCOL_CHAIN       7

DO declare

LOCAL lcBuffer, lnBufsize, lcProtInfo, lnProtIndex, lnProtCount

IF InitWinsock()
	lnBufsize = 16384  && large enough to care not
	lcBuffer = Repli(Chr(0), lnBufsize)
	lnProtCount = WSAEnumProtocols (0, @lcBuffer, @lnBufsize)

	* resulting cursor
	CREATE CURSOR cs (;
		flags1   N(16),;
		flags2   N(16),;
		flags3   N(16),;
		flags4   N(16),;
		guid     C(40),;
		entryid  N(16),;
		chain    C(32),;
		version  N(16),;
		addrfam  N(16),;
		maxsock  N(16),;
		minsock  N(16),;
		socktype N(16),;
		protocol N(16),;
		maxoffs  N(16),;
		btorder  N(16),;
		secur    N(16),;
		msgsize  N(16),;
		reserved N(16),;
		protname C(250);
	)
	
	* scan the buffer filled by the WSAEnumProtocols function
	FOR lnProtIndex=0 TO lnProtCount-1
		* extract protocol info substring from the buffer
		lcProtInfo = SUBSTR(lcBuffer, lnProtIndex*WSAPROTOCOL_INFO_SIZE+1,;
			WSAPROTOCOL_INFO_SIZE)

		= DisplayProtInfo (lcProtInfo)
	ENDFOR

	= WSACleanup()
	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF
* End of Main

PROCEDURE DisplayProtInfo(lcProtInfo)
	LOCAL lcProt

	lcProt = SUBSTR(lcProtInfo, 117)  && protocol name offset
	lcProt = SUBSTR(lcProt, 1,AT(Chr(0),lcProt)-1)
	
	* append the protocol info to the resulting cursor
	INSERT INTO cs VALUES (;
		buf2dword(SUBSTR(lcProtInfo,   1,4)),;
		buf2dword(SUBSTR(lcProtInfo,   5,4)),;
		buf2dword(SUBSTR(lcProtInfo,   9,4)),;
		buf2dword(SUBSTR(lcProtInfo,  13,4)),;
		GUIDToString(SUBSTR(lcProtInfo, 21,16)),;
		buf2dword(SUBSTR(lcProtInfo,  37,4)),;
		SUBSTR(lcProtInfo, 41,32),;
		buf2dword(SUBSTR(lcProtInfo,  73,4)),;
		buf2dword(SUBSTR(lcProtInfo,  77,4)),;
		buf2dword(SUBSTR(lcProtInfo,  81,4)),;
		buf2dword(SUBSTR(lcProtInfo,  85,4)),;
		buf2dword(SUBSTR(lcProtInfo,  89,4)),;
		buf2dword(SUBSTR(lcProtInfo,  93,4)),;
		buf2dword(SUBSTR(lcProtInfo,  97,4)),;
		buf2dword(SUBSTR(lcProtInfo, 101,4)),;
		buf2dword(SUBSTR(lcProtInfo, 105,4)),;
		buf2dword(SUBSTR(lcProtInfo, 109,4)),;
		buf2dword(SUBSTR(lcProtInfo, 113,4)),;
		m.lcProt;
		)
RETURN

FUNCTION InitWinsock()
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup (WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION GUIDToString(cGUID as String) as String
	LOCAL cBuffer, nBufsize
	nBufsize=128
	cBuffer = REPLICATE(CHR(0), nBufsize*2)
	= StringFromGUID2(cGUID, @cBuffer, nBufsize)
	cBuffer = SUBSTR(cBuffer, 1, AT(CHR(0)+CHR(0), cBuffer))
RETURN STRCONV(cBuffer,6)

PROCEDURE declare
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER WSACleanup IN ws2_32

	DECLARE INTEGER WSAEnumProtocols IN ws2_32;
		INTEGER lpiProtocols, STRING @lpProtBuf, INTEGER @lpdwBufLen

	DECLARE INTEGER StringFromGUID2 IN ole32;
		STRING rguid, STRING @lpsz, INTEGER cchMax  
```  
***  


## Listed functions:
[StringFromGUID2](../libraries/ole32/StringFromGUID2.md)  
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAEnumProtocols](../libraries/iphlpapi/WSAEnumProtocols.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
