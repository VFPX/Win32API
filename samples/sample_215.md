[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: retrieving the standard host name and IP address for the local machine

## Before you begin:
The HOSTENT structure is used by Winsock functions to store information about a given host, such as host name, IP address, and so forth.  
  
***  


## Code:
```foxpro  
#DEFINE HOSTENT_SIZE 16
#DEFINE SOCKET_ERROR -1
#DEFINE WSADATA_SIZE 398
#DEFINE WS_VERSION 0x0202
#DEFINE CRLF CHR(13)+CHR(10)
DO declare

IF InitWinsock()
	LOCAL lcLocalHost, lcLocalIP

	lcLocalHost = GetLocalHostName()

*	lcLocalHost = GETENV("COMPUTERNAME")
*	lcLocalHost = "SOMECOMPUTER"
*	lcLocalHost = "www.microsoft.com"
*	lcLocalHost = "smtp1.sympatico.ca"

	lcLocalIP = GetHostIP(lcLocalHost)

	? "Host:", lcLocalHost
	? "IP:", lcLocalIP

	= WSACleanup()
ENDIF
* end of main

FUNCTION GetLocalHostName
* returns standard host name for the local machine
	LOCAL lcBuffer, lnResult
	lcBuffer = SPACE(250)
	lnResult = gethostname(@lcBuffer, Len(lcBuffer))
RETURN Iif(lnResult=0,;
	SUBSTR(lcBuffer, 1,AT(Chr(0),lcBuffer)-1), "")

FUNCTION GetHostIP(lcHostname)
	LOCAL lcHOSTENTptr, lcHOSTENT, lnAddrlistPtr

	* address for the HOSTENT structure
	lcHOSTENTptr = gethostbyname(lcHostname)

	IF lcHOSTENTptr <> 0
		lcHOSTENT = GetMemBuf(lcHOSTENTptr, HOSTENT_SIZE)

		* a pointer to a null-terminated list of addresses
		lnAddrlistPtr = buf2dword(SUBSTR(lcHOSTENT, 13,4))
		RETURN GetIPfromHOSTENT (lnAddrlistPtr)
	ENDIF
RETURN ""

PROCEDURE GetIPfromHOSTENT(nAddrlistPtr)
* Dec.3, 2005 updated
	LOCAL nDataAddress, cResult
	cResult = ""

	DO WHILE .T.  && may have more than one ip address
		nDataAddress = buf2dword(GetMemBuf(nAddrlistPtr, 4))
		IF nDataAddress = 0
			EXIT
		ENDIF
		cResult = cResult +;
			IIF(EMPTY(cResult), "", CRLF) +;
			GetIPAddress(GetMemBuf(nDataAddress, 4))
		nAddrlistPtr = nAddrlistPtr + 4
	ENDDO
RETURN m.cResult

FUNCTION GetIPAddress(lcAddrBuf)
* converts ip address 4-character buffer
* to string representation
	LOCAL lcResult, ii
	lcResult = ""
	FOR ii=1 TO 4
		lcResult = lcResult +;
			LTRIM(STR(Asc(SUBSTR(lcAddrBuf, ii,1)))) +;
			Iif(ii=4, "",".")
	ENDFOR
RETURN lcResult

FUNCTION InitWinsock()
* starts Winsock service for the application
	LOCAL lcWSADATA, lnInitResult
	lcWSADATA = Repli(Chr(0), WSADATA_SIZE)
	lnInitResult = WSAStartup (WS_VERSION, @lcWSADATA)
RETURN (lnInitResult = 0)

FUNCTION GetMemBuf(lnAddr, lnBufsize)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), lnBufsize)
	= MemToStr(@lcBuffer, lnAddr, lnBufsize)
RETURN lcBuffer

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE declare
	DECLARE INTEGER WSACleanup IN ws2_32

	DECLARE INTEGER gethostbyname IN ws2_32;
		STRING hostname

	DECLARE INTEGER WSAStartup IN ws2_32;
		INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER gethostname IN ws2_32;
		STRING @name, INTEGER namelen

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLength  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[gethostbyname](../libraries/ws2_32/gethostbyname.md)  
[gethostname](../libraries/ws2_32/gethostname.md)  

## Comment:
Dec.3, 2005: determines more than one ip address for a host name, if present.  
  
***  

