[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve network parameters for the local computer (including Host name, Domain name, and DNS Server)

## Before you begin:
Normally this information is available through the DOS call:  

`ipconfig /all`
  
***  


## Code:
```foxpro  
#DEFINE ERROR_SUCCESS           0
#DEFINE ERROR_NOT_SUPPORTED     50
#DEFINE ERROR_INVALID_PARAMETER 87
#DEFINE ERROR_BUFFER_OVERFLOW   111
#DEFINE ERROR_NO_DATA           232
#DEFINE MAX_HOSTNAME_LEN        128
#DEFINE MAX_DOMAIN_NAME_LEN     128
DO decl

LOCAL cBuffer, nBufsize, nResult, cHost, cDomain, cDnsIP, cDnsUrl
nBufsize = 0
cBuffer = ""

* this call usually returns the ERROR_BUFFER_OVERFLOW
* with nBufsize set to the required amount of memory
= GetNetworkParams(@cBuffer, @nBufsize)
cBuffer = Repli(Chr(0), nBufsize)

nResult = GetNetworkParams(@cBuffer, @nBufsize)
IF nResult <> ERROR_SUCCESS
	? "Error code:", nResult
ELSE
*|typedef struct {
*|  char HostName[MAX_HOSTNAME_LEN + 4];      0:132
*|  char DomainName[MAX_DOMAIN_NAME_LEN + 4]; 132:132
*|  PIP_ADDR_STRING CurrentDnsServer;         264:8
*|  IP_ADDR_STRING DnsServerList;             272:...
*|  UINT NodeType;
*|  char ScopeId[MAX_SCOPE_ID_LEN + 4];
*|  UINT EnableRouting;
*|  UINT EnableProxy;
*|  UINT EnableDns;
*|} FIXED_INFO, *PFIXED_INFO

	cHost = STRTRAN(SUBSTR(cBuffer, 1, 132), Chr(0),"")
	cDomain = STRTRAN(SUBSTR(cBuffer, 133, 132), Chr(0),"")
	cDnsIP = STRTRAN(SUBSTR(cBuffer, 273, 15), Chr(0),"")
	cDnsUrl = GetUrlByIP(cDnsIP)

	? "Host name:", cHost
	? "Domain name:", cDomain
	? "DNS Server:", cDnsIP + ", " + cDnsUrl
ENDIF
* end of main

FUNCTION GetUrlByIP(cIP)
#DEFINE AF_INET    2
	LOCAL nIP, nAddr, cBuffer, cUrl
	cUrl = ""

	IF InitWinsock()
		nIP = inet_addr(cIP)
		nAddr = gethostbyaddr(@nIP, 4, AF_INET)
		IF nAddr <> 0
			cBuffer = Repli(Chr(0), 16)
			= CopyMemory(@cBuffer, nAddr, 16)

			nAddr = buf2dword(SUBSTR(cBuffer,1,4))

			cUrl = Repli(Chr(0), 250)
			= CopyMemory(@cUrl, nAddr, 250)
			cUrl = SUBSTR(cUrl, 1, AT(Chr(0),cUrl)-1)
		ENDIF
		= WSACleanup()
	ENDIF
RETURN "http://" + cUrl

FUNCTION InitWinsock
* Initializing the Winsock service for the application
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup (WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE decl
	DECLARE INTEGER inet_addr IN ws2_32 STRING cp
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData
	DECLARE INTEGER WSACleanup IN ws2_32

	DECLARE INTEGER GetNetworkParams IN iphlpapi;
		STRING @pFixedInfo, LONG @pOutBufLen

	DECLARE INTEGER gethostbyaddr IN ws2_32;
		INTEGER @addr, INTEGER nLen, INTEGER nType

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[GetNetworkParams](../libraries/iphlpapi/GetNetworkParams.md)  
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[gethostbyaddr](../libraries/ws2_32/gethostbyaddr.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  


***  

