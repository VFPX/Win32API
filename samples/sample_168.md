[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating connections made to a shared resource for the local computer (WinNT only)

## Before you begin:
By now I have not tested this example, because "Admin or server, print, or comm operator group membership is required to successfully execute the NetConnectionEnum function" -- MSDN.  

Whoever  could test it, please send me a message if any corrections are needed.  
  
***  


## Code:
```foxpro  
#DEFINE NERR_Success           0
#DEFINE MAX_PREFERRED_LENGTH  -1
#DEFINE INFOSTRU_SIZE         28  && bytes

*| typedef struct _CONNECTION_INFO_1 {
*|   DWORD     coni1_id;
*|   DWORD     coni1_type;
*|   DWORD     coni1_num_opens;
*|   DWORD     coni1_num_users;
*|   DWORD     coni1_time;
*|   LPWSTR    coni1_username;
*|   LPWSTR    coni1_netname;
*| } CONNECTION_INFO_1, *PCONNECTION_INFO_1, *LPCONNECTION_INFO_1;

DO decl

	LOCAL lnResult, lcResName, lnBuffer, lnEntriesRead,;
		lnTotalEntries, lnResumeHandle

	STORE 0 TO lnBuffer, lnEntriesRead, lnTotalEntries, lnResumeHandle

	* enter valid resource name: shared name or computer name
	lcResName = "\\MYCOMPUTER"
	
	lnResult = NetConnectionEnum (0,lcResName, 1,;
		@lnBuffer, MAX_PREFERRED_LENGTH,;
		@lnEntriesRead, @lnTotalEntries,;
		@lnResumeHandle)

	IF lnResult <> NERR_Success
		*  5 - access is denied
		* 87 - parameter is incorrect
		? "Error code:", lnResult
	ELSE
		LOCAL lnEntry, lnBufLen, lcBuffer, lcConInfo
		lnBufLen = lnEntriesRead * INFOSTRU_SIZE
		lcBuffer = Repli (Chr(0), lnBufLen)
		= Heap2String (@lcBuffer, lnBuffer, lnBufLen)
		
		* resulting cursor
		CREATE CURSOR csResult (;
			conid N(16), contype N(16), conopens N(16), conusers N(16),;
			contime N(16), username C(50), netname C(100))
			
		LOCAL conid, contype, conopens, conusers, contime,;
			usernamePtr, netnamePtr, username, netname
		
		* scanning returned entries
		FOR lnEntry = 1 TO lnEntriesRead
			* copying the UserInfo structure to a VFP string
			lcConInfo = SUBSTR (lcBuffer,;
				(lnEntry-1)*INFOSTRU_SIZE+1, INFOSTRU_SIZE)

			conid       = buf2dword (SUBSTR(lcConInfo,  1,4))
			contype     = buf2dword (SUBSTR(lcConInfo,  5,4))
			conopens    = buf2dword (SUBSTR(lcConInfo,  9,4))
			conusers    = buf2dword (SUBSTR(lcConInfo, 13,4))
			contime     = buf2dword (SUBSTR(lcConInfo, 17,4))
			usernamePtr = buf2dword (SUBSTR(lcConInfo, 21,4))
			netnamePtr  = buf2dword (SUBSTR(lcConInfo, 25,4))

			username = getStrFromMem (usernamePtr)
			netname  = getStrFromMem (netnamePtr)
			
			INSERT INTO csResult FROM MEMVAR
		ENDFOR
	ENDIF

	* this buffer is allocated by the system and must be freed
	= NetApiBufferFree (lnBuffer)
RETURN  && main

FUNCTION  getStrFromMem (lnMemBlock)
* converting allocated in memory Unicode string to a VFP string
#DEFINE StrBufferLength   250
	LOCAL lcBuffer
	lcBuffer = SPACE(StrBufferLength)
	= Heap2String (@lcBuffer, lnMemBlock, StrBufferLength)
	lcBuffer = SUBSTR (lcBuffer, 1, AT(Chr(0)+Chr(0),lcBuffer)-1)
RETURN  STRTRAN(lcBuffer, Chr(0),"")

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	   Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	   Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	   Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE RtlMoveMemory IN kernel32 As Heap2String;
		STRING @ Destination, INTEGER Source, INTEGER nLength

	DECLARE INTEGER NetConnectionEnum IN netapi32;
		INTEGER servername, STRING  qualifier,;
		INTEGER level, INTEGER @bufptr, INTEGER prefmaxlen,;
		INTEGER @entriesread, INTEGER @totalentries,;
		INTEGER @resume_handle  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetConnectionEnum](../libraries/netapi32/NetConnectionEnum.md)  


***  

