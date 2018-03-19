[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating network sessions established on a server

## Before you begin:
See also:

* [Enumerating global and local group accounts on a server (WinNT/XP/2K)](sample_411.md)  
* [Enumerating files opened on the network](sample_121.md)  
* [Obtaining names of local and global groups for current user (WinNT/XP/2K)](sample_431.md)  
* [How to enumerate, add and delete shares on the local computer (WinNT/XP)](sample_351.md)  
* [How to enumerate logon sessions on local computer](sample_591.md)  
  
***  


## Code:
```foxpro  
#DEFINE MAX_PREFERRED_LENGTH -1
#DEFINE NERR_Success 0
#DEFINE SESSION_INFO_10_SIZE 16
DO declare

*!*	typedef struct _SESSION_INFO_10 {
*!*	  LPWSTR sesi10_cname;
*!*	  LPWSTR sesi10_username;
*!*	  DWORD sesi10_time;
*!*	  DWORD sesi10_idle_time;
*!*	} SESSION_INFO_10, *PSESSION_INFO_10, *LPSESSION_INFO_10;

CREATE CURSOR csSessions (computername C(32), username C(32),;
	activetime I, idletime I)

LOCAL cServer, nLevel, hBuffer, nRead, nTotal, nResume,;
	nBufsize, cBuffer, cSessionInfo, nIndex,;
	nActiveTime, nIdleTime, hComputerName, hUserName,;
	cComputerName, cUserName

cServer=""  && local computer
nLevel=10
STORE 0 TO hBuffer, nRead, nTotal, nResume, nResult

nResult = NetSessionEnum(ToUnicode(cServer), NULL, NULL,;
	nLevel, @hBuffer, MAX_PREFERRED_LENGTH,;
	@nRead, @nTotal, @nResume)

DO CASE
CASE nResult <> NERR_Success
	= MESSAGEBOX("NetSessionEnum failed with error code: " +;
		LTRIM(STR(nResult)) + "     ", 48, "Enumerating Sessions")

CASE nRead = 0
	= MESSAGEBOX("No sessions found.     ", 64,;
		"Enumerating Sessions")

OTHERWISE
	nBufsize = GetBufsize(hBuffer)
	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, hBuffer, nBufsize)

	FOR nIndex=0 TO nRead-1
		cSessionInfo = SUBSTR(cBuffer,;
			nIndex*SESSION_INFO_10_SIZE+1,;
			SESSION_INFO_10_SIZE)

		hComputerName = buf2dword(SUBSTR(cSessionInfo, 1, 4))
		cComputerName = GetStr(cBuffer, hBuffer, hComputerName)
		hUserName = buf2dword(SUBSTR(cSessionInfo, 5, 4))
		cUserName = GetStr(cBuffer, hBuffer, hUserName)

		nActiveTime = buf2dword(SUBSTR(cSessionInfo, 9, 4))
		nIdleTime = buf2dword(SUBSTR(cSessionInfo, 13, 4))
		
		INSERT INTO csSessions VALUES (cComputerName, cUserName,;
			nActiveTime, nIdleTime)
	NEXT
ENDCASE

= NetApiBufferFree(hBuffer)
SELECT csSessions
IF RECCOUNT() > 0
	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF
* end of main

FUNCTION GetStr(cBuffer, hBuffer, hAddr)
	IF hAddr = 0
		RETURN ""
	ENDIF

	LOCAL nOffset, ch, cResult
	nOffset = hAddr - hBuffer + 1
	cResult=""
	
	FOR nOffset=nOffset TO LEN(cBuffer) STEP 2
		ch = SUBSTR(cBuffer, nOffset, 2)
		IF m.ch = CHR(0)+CHR(0)
			EXIT
		ENDIF
		cResult = cResult + m.ch
	NEXT
RETURN STRCONV(cResult,6)

FUNCTION GetBufsize(hBuffer)
	LOCAL nBufsize
	nBufsize=0
	= NetApiBufferSize(hBuffer, @nBufsize)
RETURN nBufsize

FUNCTION ToUnicode(cStr)
RETURN STRCONV(cStr+Chr(0),5)

PROCEDURE declare
	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE INTEGER NetSessionEnum IN Netapi32;
		STRING servername, STRING UncClientName, STRING username,;
		LONG lvl, INTEGER @bufptr, LONG prefmaxlen,;
		LONG @entriesread, LONG @totalentries, LONG @resume_handle

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLen

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetSessionEnum](../libraries/netapi32/NetSessionEnum.md)  
