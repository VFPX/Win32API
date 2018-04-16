[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Winsock: retrieving information from a host database for a given host name

## Before you begin:
An example of return for this sample code:  
```txt
Host name: microsoft.com  
IP 1: 207.46.249.190  
IP 2: 207.46.249.222  
IP 3: 207.46.249.27  
IP 4: 207.46.134.155  
IP 5: 207.46.134.190  
IP 6: 207.46.134.222
```

  
***  


## Code:
```foxpro  
*| struct HOSTENT {
*|   char FAR *       h_name;       0:4
*|   char FAR * FAR * h_aliases;    4:4
*|   short            h_addrtype;   8:2
*|   short            h_length;    10:2
*|   char FAR * FAR * h_addr_list; 12:4
*| }; total = 16 bytes
#DEFINE HOSTENT_SIZE  16
DO decl

IF Not InitWinsock()
	? "WSAStartup failed"
	RETURN
ENDIF

LOCAL nHost, lcHOSTENT, lnNamePtr, lnAddrlistPtr
nHost = gethostbyname("microsoft.com")

IF nHost <> 0
	* copying data from the HOSTENT structure to a VFP string
	lcHOSTENT = GetMemBuf(nHost, HOSTENT_SIZE)

	* a pointer to the host name
	lnNamePtr = buf2dword(SUBSTR(lcHOSTENT, 1,4))
	? "Host name:", GetMemStr(lnNamePtr)
	
	* a pointer to a null-terminated list of IP addresses
	lnAddrlistPtr = buf2dword(SUBSTR(lcHOSTENT, 13,4))

	* displaying IP addresses for this host
	= DisplayIPs(lnAddrlistPtr)
ELSE
* 10093 = WSANOTINITIALISED
* Either the application has not called WSAStartup, or WSAStartup failed
	? "Error:", GetLastError()
ENDIF
= WSACleanup()
* End of Main

PROCEDURE  DisplayIPs (lnAddrlistPtr)
* retrieving IP addresses from the list

	LOCAL lnElementPtr, lnIPcount, lcDataAddress, lnDataAddress,;
		lcIPAddrBuf

	lnIPcount = 0  && list elements retrieved
	lnElementPtr = lnAddrlistPtr  && first member on the list

	* scanning the list one member by another
	* until a null member found
	DO WHILE .T.
		* the list member contains a DWORD memory address
		lcDataAddress = GetMemBuf(lnElementPtr, 4)
		lnDataAddress = buf2dword(lcDataAddress)
		
		IF lnDataAddress = 0
		* the last member on this list is null
			EXIT
		ENDIF
	
		* retrieving a DWORD with an IP address
		lcIPAddrBuf = GetMemBuf (lnDataAddress, 4)
	
		lnIPcount = lnIPcount + 1
		? "IP " + LTRIM(STR(lnIPcount)) + ":",;
			inet_ntoa(buf2dword(lcIPAddrBuf))

		* shifting to the next element on the list
		lnElementPtr = lnElementPtr + 4   && DWORD
	ENDDO
RETURN

FUNCTION GetMemStr (lnAddr)
* returning data from a memory block as a VFP string
#DEFINE MEMSTR_BUFSIZE   128
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), MEMSTR_BUFSIZE)
	= CopyMemory (@lcBuffer, lnAddr, MEMSTR_BUFSIZE)
RETURN SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)

FUNCTION GetMemBuf (lnAddr, lnBufsize)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), lnBufsize)
	= CopyMemory (@lcBuffer, lnAddr, lnBufsize)
RETURN lcBuffer

FUNCTION InitWinsock()
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
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER WSAStartup IN ws2_32 INTEGER wVerRq, STRING @lpWSAData
	DECLARE INTEGER WSACleanup IN ws2_32
	DECLARE INTEGER gethostbyname IN ws2_32 STRING hostname
	DECLARE STRING inet_ntoa IN ws2_32 INTEGER in_addr

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Src, INTEGER nLength  
```  
***  


## Listed functions:
[CopyMemory](../libraries/kernel32/CopyMemory.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[WSACleanup](../libraries/ws2_32/WSACleanup.md)  
[WSAStartup](../libraries/ws2_32/WSAStartup.md)  
[gethostbyname](../libraries/ws2_32/gethostbyname.md)  
[inet_ntoa](../libraries/ws2_32/inet_ntoa.md)  


***  

