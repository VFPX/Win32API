[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: initializing the service in the VFP application

## Code:
```foxpro  
#DEFINE WSADESCRIPTION_LEN   256
#DEFINE WSASYS_STATUS_LEN    128
DO decl

*| typedef struct WSAData {
*| WORD           wVersion;                              0:2
*| WORD           wHighVersion;                          2:2
*| char           szDescription[WSADESCRIPTION_LEN+1];   4:257
*| char           szSystemStatus[WSASYS_STATUS_LEN+1]; 261:129
*| unsigned short iMaxSockets;                         390:2
*| unsigned short iMaxUdpDg;                           392:2
*| char FAR *     lpVendorInfo;                        394:4
*| } WSADATA, *LPWSADATA; total bytes = 20

#DEFINE WSADATA_SIZE  398
*#DEFINE WS_VERSION 0x0101
#DEFINE WS_VERSION 0x0202

LOCAL lcBuffer, lnResult
lcBuffer = Repli(Chr(0), WSADATA_SIZE)

lnResult = WSAStartup (WS_VERSION, @lcBuffer)
IF lnResult = 0
	? "The lowest version expected:", buf2word(SUBSTR(lcBuffer, 1,2))
	? "The highest version:", buf2word(SUBSTR(lcBuffer, 3,2))
	? "Description:", STRTRAN(SUBSTR(lcBuffer,  5,257), Chr(0),"")
	? "System Status:", STRTRAN(SUBSTR(lcBuffer, 262,129), Chr(0),"")
	
	= "Cleanup:", WSACleanup()
ELSE
	? "Error returned:", lnResult
ENDIF

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

PROCEDURE  decl
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData
	DECLARE INTEGER WSACleanup IN ws2_32  
```  
***  


## Listed functions:
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
