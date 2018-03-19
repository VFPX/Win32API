[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the IP-to-physical address mapping table

## Code:
```foxpro  
DO decl

*| typedef struct _MIB_IPNETTABLE {
*|   DWORD           dwNumEntries;    // number of entries in table
*|   MIB_IPNETROW    table[ANY_SIZE]; // array of ARP entries
*| } MIB_IPNETTABLE, *PMIB_IPNETTABLE; total bytes = 4+undef

#DEFINE MAXLEN_PHYSADDR  8
*| typedef struct _MIB_IPNETROW {
*|   DWORD   dwIndex;                     // adapter index       0:4
*|   DWORD   dwPhysAddrLen;               // physical addr.len.  4:4
*|   BYTE    bPhysAddr[MAXLEN_PHYSADDR];  // physical addr.      8:8
*|   DWORD   dwAddr;                      // IP addr.           16:4
*|   DWORD   dwType;                      // ARP entry type     20:4
*| } MIB_IPNETROW, *PMIB_IPNETROW; total bytes = 24
#DEFINE MIB_IPNETROW_SIZE  24

PRIVATE lWinsockEnabled
lWinsockEnabled = InitWinsock()

LOCAL lcBuffer, lnBufsize, lnEntries, lnIndex, lcEntryBuf
* allocate a space large enough to keep the data
lnBufsize = 8192

lcBuffer = Repli(Chr(0), lnBufsize)
= GetIpNetTable (@lcBuffer, @lnBufsize, 0)
lnEntries = buf2dword(SUBSTR(lcBuffer, 1,4))

* resulting cursor
CREATE CURSOR cs (aindex N(3), addrlen N(3),;
	addr C(8), ip C(15), arptype N(3), hostname C(50))

FOR lnIndex = 1 TO lnEntries
	lcEntryBuf = SUBSTR(lcBuffer, 5+(lnIndex-1)*MIB_IPNETROW_SIZE,;
		MIB_IPNETROW_SIZE)
	= AddEntry (lcEntryBuf)
ENDFOR

IF lWinsockEnabled
	= WSACleanup()
ENDIF

GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE  AddEntry (lcEntryBuf)
	LOCAL lnAdapterIdx, lnPhAddrLen, lcPhAddr,;
		lcIPAddrBuf, lcIPAddr, lcHostName, lnEntryType

	* the index of the adapter
	lnAdapterIdx = buf2dword(SUBSTR(lcEntryBuf,  1,4))

	* the physical address
	lnPhAddrLen  = buf2dword(SUBSTR(lcEntryBuf,  5,4))
	lcPhAddr     = SUBSTR(lcEntryBuf, 9,8)

	* IP address
	lcIPAddrBuf  = SUBSTR(lcEntryBuf, 17,4)
	lcIPAddr = inet_ntoa(buf2dword(lcIPAddrBuf))
	lcHostName = GetHostName(lcIPAddrBuf)  && takes some time
	
	* Address Resolution Protocol (ARP) entry type
	* 4-static, 3-dynamic, 2-invalid, 1-other
	lnEntryType  = buf2dword(SUBSTR(lcEntryBuf, 21,4))
	
	? lcIPAddr
	INSERT INTO cs VALUES (lnAdapterIdx, lnPhAddrLen, lcPhAddr,;
		lcIPAddr, lnEntryType, lcHostName)
RETURN

FUNCTION  GetHostName (lcAddrBuf)
#DEFINE AF_INET        2 && internetwork: UDP, TCP, etc.
#DEFINE HOSTENT_SIZE  16
	LOCAL lcResult, lnHOSTENTptr, lcHOSTENT
	lcResult = ""

	IF lWinsockEnabled
		lnHOSTENTptr = gethostbyaddr(lcAddrBuf, 4, AF_INET)
		IF lnHOSTENTptr <> 0
			lcHOSTENT = GetMemBuf (lnHOSTENTptr, HOSTENT_SIZE)
			lcResult = GetMemStr(buf2dword(SUBSTR(lcHOSTENT, 1,4)))
		ENDIF
	ENDIF
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
* returning data from a memory block
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

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE STRING inet_ntoa IN ws2_32 INTEGER in_addr
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData

	DECLARE INTEGER GetIpNetTable IN iphlpapi;
		STRING @pIpNetTable, INTEGER @pdwSize, INTEGER bOrder

	DECLARE INTEGER gethostbyaddr IN ws2_32;
		STRING addr, INTEGER len, INTEGER type

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[GetIpNetTable](../libraries/iphlpapi/GetIpNetTable.md)  
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[gethostbyaddr](../libraries/ws2_32/gethostbyaddr.md)  
[gethostname](../libraries/ws2_32/gethostname.md)  
[inet_ntoa](../libraries/ws2_32/inet_ntoa.md)  
