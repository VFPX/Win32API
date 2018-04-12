[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving configuration information for the specified workstation (Win2000/XP)

## Before you begin:
Check similar example [Retrieving configuration information for the specified server (Win2000/XP)](sample_425.md).  
  
***  


## Code:
```foxpro  
#DEFINE NERR_Success 0
DO decl

PRIVATE hBuffer, cBuffer
LOCAL cServer, nLevel, nResult, nBufsize
*cServer = Null
*cServer = STRCONV("MYSERVER"+CHR(0), 5)  && sufficient access level
nLevel=102
hBuffer=0

nResult = NetWkstaGetInfo(cServer, nLevel, @hBuffer)
IF nResult <> NERR_Success
* 5=ERROR_ACCESS_DENIED
* 53=ERROR_BAD_NETPATH
	? "Error code:", nResult
	RETURN
ENDIF

nBufsize=0
= NetApiBufferSize(hBuffer, @nBufsize)

cBuffer = REPLICATE(CHR(0), nBufsize)
= CopyMemory(@cBuffer, hBuffer, nBufsize)

*|typedef struct _WKSTA_INFO_102 {
*|  DWORD wki102_platform_id;      0:4
*|  LMSTR wki102_computername;     4:4
*|  LMSTR wki102_langroup;         8:4
*|  DWORD wki102_ver_major;       12:4
*|  DWORD wki102_ver_minor;       16:4
*|  LMSTR wki102_lanroot;         20:4
*|  DWORD wki102_logged_on_users; 24:4
*|} WKSTA_INFO_102,... total bytes 28

CREATE CURSOR cs (prm C(30), vlu C(100))

nPlatformId = buf2dword(SUBSTR(cBuffer, 1,4))
INSERT INTO cs VALUES ("Platform ID", LTRIM(STR(nPlatformId)))
= NetApiBufferFree(hBuffer)

cComputerName = GetStr(5)
INSERT INTO cs VALUES ("Computer name", m.cComputerName)

cLangroup = GetStr(9)
INSERT INTO cs VALUES ("LAN Group", m.cLangroup)

nVerMajor = buf2dword(SUBSTR(cBuffer, 13,4))
INSERT INTO cs VALUES ("OS major version", LTRIM(STR(m.nVerMajor)))

nVerMinor = buf2dword(SUBSTR(cBuffer, 17,4))
INSERT INTO cs VALUES ("OS minor version", LTRIM(STR(m.nVerMinor)))

cLangroot = GetStr(21)
INSERT INTO cs VALUES ("LANMAN directory", m.cLangroot)

nLogged = buf2dword(SUBSTR(cBuffer, 25,4))
INSERT INTO cs VALUES ("Logged users", LTRIM(STR(m.nLogged)))

*SELECT 0
*CREATE CURSOR cc (ch C(1), asc I)
*FOR ii=1 TO LEN(cBuffer)
*	ch = SUBSTR(cBuffer, ii,1)
*	INSERT INTO cc VALUES (m.ch, ASC(m.ch))
*ENDFOR

SELECT cs
GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION GetStr(nOffs)
	LOCAL nPtr, cStr, ch
	nPtr = buf2dword(SUBSTR(cBuffer, nOffs,4)) - hBuffer + 1
	cStr = ""
	DO WHILE nPtr < LEN(cBuffer)
		ch = SUBSTR(cBuffer, nPtr, 2)
		IF ch = CHR(0)+CHR(0)
			EXIT
		ENDIF
		cStr = cStr + m.ch
		nPtr = nPtr + 2
	ENDDO
	cStr = STRTRAN(cStr, CHR(0), "")
RETURN cStr

PROCEDURE decl

	DECLARE INTEGER NetWkstaGetInfo IN netapi32;
		STRING servername, LONG lvl, INTEGER @bufptr

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @dst, INTEGER src, INTEGER bufsize

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetWkstaGetInfo](../libraries/netapi32/NetWkstaGetInfo.md)  
