[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating servers of the specified type (e.g. SQL Server) in the primary domain

## Before you begin:
See also:

* [Enumerating network resources](sample_313.md)  
* [Mapping and disconnecting network drives in FoxPro application](sample_387.md)  
* [Retrieving information about shared resources on the local computer (WinNT/XP)](sample_351.md)  
  
***  


## Code:
```foxpro  
* Specifies the type of software the computer is running
#DEFINE SV_TYPE_WORKSTATION 1
#DEFINE SV_TYPE_SERVER 2
#DEFINE SV_TYPE_SQLSERVER 4
#DEFINE SV_TYPE_DOMAIN_CTRL  8
#DEFINE SV_TYPE_PRINTQ_SERVER 0x200
#DEFINE SV_TYPE_SERVER_UNIX 0x800
#DEFINE SV_TYPE_SERVER_NT 0x8000
#DEFINE SV_TYPE_DOMAIN_MASTER 0x80000
#DEFINE SV_TYPE_WINDOWS 0x400000
#DEFINE SV_TYPE_ALL 0xFFFFFFFF

DO declare

	* testing various server lists
*	= EnumServers(SV_TYPE_PRINTQ_SERVER)
*	= EnumServers(SV_TYPE_SERVER)
	= EnumServers(SV_TYPE_SQLSERVER)
*	= EnumServers(SV_TYPE_SERVER_NT)
*	= EnumServers(SV_TYPE_DOMAIN_CTRL)
*	= EnumServers(SV_TYPE_ALL)

PROCEDURE EnumServers(lnServerType)
#DEFINE MAX_PREFERRED_LENGTH -1
#DEFINE SINFO_101_SIZE       24

*| typedef struct _SERVER_INFO_101 {
*|   DWORD     sv101_platform_id;     4
*|   LPWSTR    sv101_name;            4
*|   DWORD     sv101_version_major;   4
*|   DWORD     sv101_version_minor;   4
*|   DWORD     sv101_type;            4
*|   LPWSTR    sv101_comment;         4
*| } SERVER_INFO_101, *PSERVER_INFO_101, *LPSERVER_INFO_101;

	LOCAL lnBuffer, lnCountRead, lnCountTotal, lnResult
	STORE 0 TO lnBuffer, lnCountRead, lnCountTotal

	WAIT WINDOW "Requesting data..." NOWAIT
	lnResult = NetServerEnum(0, 101, @lnBuffer, MAX_PREFERRED_LENGTH,;
		@lnCountRead, @lnCountTotal, lnServerType, 0, 0)
	WAIT CLEAR
	
	IF lnResult <> 0
	*  87 = The parameter is incorrect
	* 234 = More data is available
		? "Error code:", lnResult
	ELSE
		LOCAL lcBuffer, lnBufLen, lnEntry, lnPlatformId, lnNamePtr,;
			lnMajorVer, lnMinorVer, lnSofttype, lnMemoPtr,;
			lcServerName, lcServerMemo
	
		* creating resulting cursor
		CREATE CURSOR csResult (platformid N(12), servername C(30),;
			majorver N(12), minorver N(12), softtype N(12), comment C(250))

		* copying the resulting array of SERVER_INFO_101 structures
		* to a VFP string
		lnBufLen = lnCountRead * SINFO_101_SIZE
		lcBuffer = Repli(Chr(0), lnBufLen)
		= Heap2String(@lcBuffer, lnBuffer, lnBufLen)

		* scanning resulting array
		FOR lnEntry = 1 TO lnCountRead
			lcServerInfo = SUBSTR(lcBuffer,;
				(lnEntry-1)*SINFO_101_SIZE+1, SINFO_101_SIZE)

			lnPlatformId = buf2dword(SUBSTR(lcServerInfo,  1,4))
			lnNamePtr    = buf2dword(SUBSTR(lcServerInfo,  5,4))
			lnMajorVer   = buf2dword(SUBSTR(lcServerInfo,  9,4))
			lnMinorVer   = buf2dword(SUBSTR(lcServerInfo, 13,4))
			lnSofttype   = buf2dword(SUBSTR(lcServerInfo, 17,4))
			lnMemoPtr    = buf2dword(SUBSTR(lcServerInfo, 21,4))

			lcServerName = GetStrFromMem(lnNamePtr)
			lcServerMemo = GetStrFromMem(lnMemoPtr)
			WAIT WINDOW lcServerName NOWAIT

			INSERT INTO csResult VALUES (lnPlatformId, lcServerName,;
				lnMajorVer, lnMinorVer, lnSofttype, lcServerMemo)
		ENDFOR
		WAIT CLEAR
	ENDIF
	
	* releasing the memory block allocated regardless of the result
	* by OS within NetServerEnum call
	= NetApiBufferFree(lnBuffer)
	
	IF USED("csResult")
		SELECT csResult
		GO TOP
		BROWSE NORMAL NOWAIT
	ENDIF
RETURN

FUNCTION GetStrFromMem(lnMemBlock)
* converting memory allocated Unicode string to a VFP string
#DEFINE StrBufferLength 250
	LOCAL lcBuffer
	lcBuffer = SPACE(StrBufferLength)
	= Heap2String(@lcBuffer, lnMemBlock, StrBufferLength)
	lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0)+Chr(0),lcBuffer)-1)
RETURN STRTRAN(lcBuffer, Chr(0),"")

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE declare
	DECLARE INTEGER NetServerEnum IN netapi32;
		INTEGER servername, INTEGER level, INTEGER @ bufptr,;
		INTEGER prefmaxlen, INTEGER @ entriesread, INTEGER @ totalentries,;
		INTEGER servertype, INTEGER domain, INTEGER resume_handle

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE RtlMoveMemory IN kernel32 As Heap2String;
		STRING @ Destination, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetServerEnum](../libraries/netapi32/NetServerEnum.md)  
