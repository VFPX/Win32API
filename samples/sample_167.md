[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving information about all users currently logged on to the workstation (WinNT only)

## Code:
```foxpro  
DO declare

*| typedef struct _WKSTA_USER_INFO_1 {
*|   LPWSTR    wkui1_username;
*|   LPWSTR    wkui1_logon_domain;
*|   LPWSTR    wkui1_oth_domains;
*|   LPWSTR    wkui1_logon_server;  16 bytes
*| }WKSTA_USER_INFO_1, *PWKSTA_USER_INFO_1, *LPWKSTA_USER_INFO_1;

#DEFINE USERINFO_1_SIZE  16
#DEFINE MAX_PREFERRED_LENGTH -1

LOCAL lnResult, lnBuffer, lnEntriesRead, lnTotalEntries, lnResumeHandle
STORE 0 TO lnBuffer, lnEntriesRead, lnTotalEntries, lnResumeHandle

lnResult = NetWkstaUserEnum(0, 1, @lnBuffer, MAX_PREFERRED_LENGTH,;
	@lnEntriesRead, @lnTotalEntries, @lnResumeHandle)

IF lnResult <> 0
* 53 = The network path was not found
	? "Error code:", lnResult
ELSE
	LOCAL lnEntry, lnBufLen, lcBuffer, lpwstrUsername,;
		lpwstrLogon_domain, lpwstrOth_domains, lpwstrLogon_server,;
		lcUsername, lcLogon_domain, lcOth_domains, lcLogon_server

	lnBufLen = lnEntriesRead * USERINFO_1_SIZE
	lcBuffer = Repli(Chr(0), lnBufLen)
	= Heap2String(@lcBuffer, lnBuffer, lnBufLen)
	
	* resulting cursor
	CREATE CURSOR csResult (username C(30), logon_domain C(30),;
		oth_domains C(30), logon_server C(30))

	* scannig returned entries - UserInfo structures
    FOR lnEntry = 1 TO lnEntriesRead
    	* copying the UserInfo structure to a VFP string
		lcUserInfo = SUBSTR(lcBuffer,;
			(lnEntry-1)*USERINFO_1_SIZE+1, USERINFO_1_SIZE)

		* retrieving pointers to Unicode strings
		lpwstrUsername     = buf2dword(SUBSTR(lcUserInfo,  1,4))
		lpwstrLogon_domain = buf2dword(SUBSTR(lcUserInfo,  5,4))
		lpwstrOth_domains  = buf2dword(SUBSTR(lcUserInfo,  9,4))
		lpwstrLogon_server = buf2dword(SUBSTR(lcUserInfo, 13,4))
		
		* copying data from pointers to VFP strings
		lcUsername     = GetStrFromMem(lpwstrUsername)
		lcLogon_domain = GetStrFromMem(lpwstrLogon_domain)
		lcOth_domains  = GetStrFromMem(lpwstrOth_domains)
		lcLogon_server = GetStrFromMem(lpwstrLogon_server)

		INSERT INTO csResult VALUES (;
			lcUsername, lcLogon_domain, lcOth_domains, lcLogon_server)
	ENDFOR
ENDIF

* this buffer is allocated by the system and must be freed
= NetApiBufferFree(lnBuffer)

IF USED("csResult")
	SELECT csResult
	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF

FUNCTION GetStrFromMem(lnMemBlock)
* converting allocated in memory Unicode string to a VFP string
#DEFINE StrBufferLength 250
	LOCAL lcBuffer
	lcBuffer = SPACE(StrBufferLength)
	= Heap2String(@lcBuffer, lnMemBlock, StrBufferLength)
	lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0)+Chr(0),lcBuffer)-1)
RETURN  STRTRAN(lcBuffer, Chr(0),"")

PROCEDURE declare
	DECLARE INTEGER NetWkstaUserEnum IN netapi32;
		INTEGER servername, INTEGER level, INTEGER @ bufptr,;
		INTEGER prefmaxlen, INTEGER @entriesread,;
		INTEGER @totalentries, INTEGER @resumehandle

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE RtlMoveMemory IN kernel32 As Heap2String;
		STRING @ Destination, INTEGER Source, INTEGER nLength

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
       Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
       Asc(SUBSTR(lcBuffer, 4,1)) * 16777216  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetWkstaUserEnum](../libraries/netapi32/NetWkstaUserEnum.md)  
