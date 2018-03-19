[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving configuration information for the specified server (Win98/Me)

## Code:
```foxpro  
DO decl

#DEFINE SV_TYPE_WORKSTATION 1
#DEFINE SV_TYPE_SERVER 2
#DEFINE SV_TYPE_SQLSERVER 4
#DEFINE SV_TYPE_DOMAIN_CTRL 8
#DEFINE SV_TYPE_PRINTQ_SERVER 0x200
#DEFINE SV_TYPE_SERVER_UNIX 0x800
#DEFINE SV_TYPE_SERVER_NT 0x8000
#DEFINE SV_TYPE_DOMAIN_MASTER 0x80000
#DEFINE SV_TYPE_WINDOWS 0x400000
#DEFINE SV_TYPE_ALL 0xFFFFFFFF

#DEFINE CNLEN         15
#DEFINE NERR_Success   0

*| struct _server_info_1 {
*|   char             sv1_name[CNLEN + 1];  0:16
*|   unsigned char    sv1_version_major;   16:2
*|   unsigned char    sv1_version_minor;   18:2
*|   unsigned long    sv1_type;            20:4
*|   char FAR *       sv1_comment;         24:4
*| }; total bytes = 28

*| struct _server_info_50 {
*|   char             sv50_name[CNLEN + 1];  0:16
*|   unsigned char    sv50_version_major;   16:2
*|   unsigned char    sv50_version_minor;   18:2
*|   unsigned long    sv50_type;            20:4
*|   char FAR *       sv50_comment;         24:4
*|   unsigned short   sv50_security;        28:2
*|   unsigned short   sv50_auditing;        30:2
*|   char FAR *       sv50_container;       32:4
*|   char FAR *       sv50_ab_server;       36:4
*|   char FAR *       sv50_ab_dll;          40:4
*| }; total bytes = 44; should be 46?

LOCAL lcBuffer, lnBufsize, lnInfLevel, lcServerName, lnServerType, lnPtr
lnBufsize = 64  && large enough to fit
lcBuffer = Repli(Chr(0), lnBufsize)
lnInfLevel = 50  && 1 and 50 - valid inf levels for Win9*/Me

* quering local computer, otherwise it should be like \\MYSERVER
lcServerName = .Null.

lnResult = NetServerGetInfo (lcServerName, 50, @lcBuffer,;
	lnBufsize, @lnBufsize)

IF lnResult <> NERR_Success
	* 234 = More data is available
	* 2123 = ?
	? "Error code:", lnResult
	RETURN
ENDIF

? "Server name:", STRTRAN(SUBSTR(lcBuffer, 1,16), Chr(0),"")
? "Major version number:", buf2word(SUBSTR(lcBuffer, 17,2))
? "Minor version number:", buf2word(SUBSTR(lcBuffer, 19,2))

lnServerType = buf2dword(SUBSTR(lcBuffer, 21,4))
? "Networking software type:", lnServerType, GetServerType(lnServerType)

lnPtr = buf2dword(SUBSTR(lcBuffer, 25,4))
? "Server description:", Iif(lnPtr <> 0, mem2str(lnPtr), "")

? "Security type:", buf2word(SUBSTR(lcBuffer, 29,2))
? "Auditing type:", buf2word(SUBSTR(lcBuffer, 31,2))

lnPtr = buf2dword(SUBSTR(lcBuffer, 33,4))
? "Security server:", Iif(lnPtr <> 0, mem2str(lnPtr), "")

lnPtr = buf2dword(SUBSTR(lcBuffer, 37,4))
? "Address domain:", Iif(lnPtr <> 0, mem2str(lnPtr), "")

lnPtr = buf2dword(SUBSTR(lcBuffer, 41,4))
? "Address book service:", Iif(lnPtr <> 0, mem2str(lnPtr), "")

FUNCTION  mem2str(lnMemBlock)
#DEFINE BUFFER_SIZE   16
#DEFINE EMPTY_BUFFER  Repli(Chr(0), BUFFER_SIZE)
	LOCAL lnPtr, lcResult, lcBuffer, lnPos
	lnPtr = lnMemBlock
	lcResult = ""

	DO WHILE .T.
		lcBuffer = EMPTY_BUFFER
		= Heap2Str (@lcBuffer, lnPtr, BUFFER_SIZE)
		lnPos = AT(Chr(0), lcBuffer)

		IF lnPos > 0
			lcResult = lcResult + SUBSTR(lcBuffer, 1, lnPos-1)
			RETURN  lcResult
		ELSE
			lcResult = lcResult + lcBuffer
			lnPtr = lnPtr + BUFFER_SIZE
		ENDIF
	ENDDO

FUNCTION  GetServerType (lnType)
RETURN  Iif (BitAnd(lnType, SV_TYPE_WORKSTATION)<>0,   "Wkstation;","") +;
		Iif (BitAnd(lnType, SV_TYPE_SERVER)<>0,        "Server;","") +;
		Iif (BitAnd(lnType, SV_TYPE_SQLSERVER)<>0,     "SQL Server;","") +;
		Iif (BitAnd(lnType, SV_TYPE_DOMAIN_CTRL)<>0,   "PDC;","") +;
		Iif (BitAnd(lnType, SV_TYPE_PRINTQ_SERVER)<>0, "Print;","") +;
		Iif (BitAnd(lnType, SV_TYPE_SERVER_UNIX)<>0,   "Unix;","") +;
		Iif (BitAnd(lnType, SV_TYPE_SERVER_NT)<>0,     "WinNT;","") +;
		Iif (BitAnd(lnType, SV_TYPE_DOMAIN_MASTER)<>0, "Master;","") +;
		Iif (BitAnd(lnType, SV_TYPE_WINDOWS)<>0,       "Windows;","")

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) +;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) +;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

PROCEDURE  decl
	DECLARE INTEGER NetServerGetInfo IN svrapi;
		STRING pszServer, INTEGER sLevel,;
		STRING @pbBuffer, SHORT cbBuffer, SHORT @pcbTotalAvail

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @, INTEGER, INTEGER  
```  
***  


## Listed functions:
[NetServerGetInfo](../libraries/netapi32/NetServerGetInfo.md)  

## Comment:
A declaration for the NetServerGetInfo is different in WinNT and Win98/Me. For the latter the caller must allocate and deallocate the receiving buffer. Also information levels available are different in both cases. And the least one is different DLLs.  
  
***  

