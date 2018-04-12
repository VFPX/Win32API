[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving configuration information for the specified server (Win2000/XP)

## Before you begin:
Check similar example [Retrieving configuration information for the specified workstation (Win2000/XP)](sample_436.md).  
  
***  


## Code:
```foxpro  
DO decl

PRIVATE hBuffer, cServer
hBuffer = 0

* use Null as server name for local computer
*cServer = Null

* Windows NT: server name must begin with \\
* check with and without Unicode conversion
*cServer = STRCONV("\\MYSERVER"+CHR(0), 5)

* Windows XP
cServer = STRCONV("MYSERVER"+CHR(0), 5)

nResult = NetServerGetInfo(cServer, 101, @hBuffer)
IF nResult <> 0
*   53 = ERROR_BAD_NETPATH
*  123 = ERROR_INVALID_NAME
* 1113 = ERROR_NO_UNICODE_TRANSLATION
	? "Error code:", nResult
ELSE
	DO ParseSrvInfo
	= NetApiBufferFree(hBuffer)
ENDIF
* end of main

PROCEDURE ParseSrvInfo
*|typedef struct _SERVER_INFO_101 {
*|  DWORD sv101_platform_id;
*|  LPWSTR sv101_name;
*|  DWORD sv101_version_major;
*|  DWORD sv101_version_minor;
*|  DWORD sv101_type;
*|  LPWSTR sv101_comment;
*|} SERVER_INFO_101, *PSERVER_INFO_101, *LPSERVER_INFO_101;

	LOCAL nBufsize, cBuffer

	* copying memory buffer to FoxPro string
	nBufsize = 0
	= NetApiBufferSize(hBuffer, @nBufsize)
	cBuffer = Repli(Chr(0), nBufsize)
	= CopyMemory(@cBuffer, hBuffer, nBufsize)
	
	LOCAL nPlatformId, nVerMajor, nVerMinor, nSoftType,;
		nNamePtr, nCommentPtr, cName, cComment

	nPlatformId = buf2dword(SUBSTR(cBuffer, 1,4))
	nNamePtr = buf2dword(SUBSTR(cBuffer, 5,4))
	nVerMajor = buf2dword(SUBSTR(cBuffer, 9,4))
	nVerMinor = buf2dword(SUBSTR(cBuffer, 13,4))
	nSoftType = buf2dword(SUBSTR(cBuffer, 17,4))
	nCommentPtr = buf2dword(SUBSTR(cBuffer, 21,4))

	cName = GetStr(cBuffer, nNamePtr-hBuffer+1, nBufsize)
	cComment = GetStr(cBuffer, nCommentPtr-hBuffer+1, nBufsize)
	
	? "Platform ID:", nPlatformId
	? "Major version:", nVerMajor
	? "Minor version:", nVerMinor
	? "Software type:", nSoftType
	? "Server name:", cName
	? "Description:", cComment

FUNCTION GetStr(cBuffer, nOffs, nMaxOffs)
	LOCAL cResult, ch
	cResult = ""
	DO WHILE nOffs < nMaxOffs
		ch = SUBSTR(cBuffer, nOffs, 2)
		IF ch = Chr(0)+Chr(0)
			EXIT
		ENDIF
		cResult = cResult + LEFT(ch,1)
		nOffs = nOffs + 2
	ENDDO
RETURN cResult

PROCEDURE decl
	DECLARE INTEGER NetServerGetInfo IN netapi32;
		STRING servername, INTEGER lvl, INTEGER @bufptr

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetServerGetInfo](../libraries/netapi32/NetServerGetInfo.md)  
