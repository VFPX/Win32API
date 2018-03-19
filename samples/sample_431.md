[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining names of local and global groups for current user (WinNT/XP/2K)

## Before you begin:
See also:

* [Enumerating global and local group accounts on a server (WinNT/XP/2K)](sample_411.md)  
* [Enumerating sessions established on a server](sample_505.md)  

  
***  


## Code:
```foxpro  
DO decl

cServer = ""  && empty value means local computer
*cServer = "\\MYSERVER"
cUser = GetUsrName()  && current user

= ListGroups(cServer, cUser)  && local groups
= ListGroups(cServer, cUser, .T.)  && global groups
* end of main

PROCEDURE ListGroups(cServer, cUser, lGlobal)
#DEFINE MAX_PREFERRED_LENGTH -1

	LOCAL hBuffer, nBufsize, nReadCount, nTotalCount, nResult,;
		cBuffer, nIndex, nPtr, nOffs, nLen, cGroup

	STORE 0 TO nReadCount, nTotalCount, hBuffer

	cServer = StrConv(cServer+Chr(0), 5)
	cUser = StrConv(cUser+Chr(0), 5)

	IF lGlobal
		nResult = NetUserGetGroups(cServer, cUser, 0,;
			@hBuffer, MAX_PREFERRED_LENGTH, @nReadCount, @nTotalCount)
	ELSE
		nResult = NetUserGetLocalGroups(cServer, cUser, 0,0,;
			@hBuffer, MAX_PREFERRED_LENGTH, @nReadCount, @nTotalCount)
	ENDIF
	
	IF nResult <> 0 Or hBuffer=0
		= NetApiBufferFree(hBuffer)
		? "Error code:", nResult
		RETURN
	ENDIF

	* size of the buffer allocated by the system
	* GlobalSize on Windows XP returns same result
	nBufsize = 0
	= NetApiBufferSize(hBuffer, @nBufsize)

	* copying data from memory buffer to FoxPro string
	cBuffer = Repli(Chr(0), nBufsize)
	CopyMemory(@cBuffer, hBuffer, nBufsize)

	* scanning group names
	FOR nIndex=1 TO nTotalCount
		* retrieving 4-byte (DWORD) address of Unicode string
		* that specifies the group name
		nPtr = buf2dword(SUBSTR(cBuffer, (nIndex-1)*4+1,4))

		* matching memory addresses to cBuffer string
		nOffs = nPtr - hBuffer + 1
		cGroup = SUBSTR(cBuffer, nOffs)+Chr(0)+Chr(0)
		nLen = AT(Chr(0)+Chr(0), cGroup)
		cGroup = SUBSTR(cGroup, 1, nLen)

		? nIndex, StrConv(cGroup, 6)
	ENDFOR
	= NetApiBufferFree(hBuffer)

FUNCTION GetUsrName
* actually SYS(0) is Ok too :)
	LOCAL cBuffer, nBufsize
	nBufsize = 32
	cBuffer = Repli(Chr(0), nBufsize)
	= GetUserName(@cBuffer, @nBufsize)
RETURN STRTRAN(cBuffer, Chr(0), "")

PROCEDURE decl
	DECLARE INTEGER NetUserGetGroups IN netapi32;
		STRING servername, STRING username, INTEGER lvl,;
		INTEGER @bufptr, INTEGER prefmaxlen,;
		INTEGER @entriesread, INTEGER @totalentries

	DECLARE INTEGER NetUserGetLocalGroups IN netapi32;
		STRING servername, STRING username, INTEGER lvl,;
		INTEGER flgs, INTEGER @bufptr, INTEGER prefmaxlen,;
		INTEGER @entriesread, INTEGER @totalentries

	DECLARE INTEGER GetUserName IN advapi32;
		STRING  @lpBuffer, INTEGER @nSize

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @dst, INTEGER src, INTEGER bufsize

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetUserName](../libraries/advapi32/GetUserName.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetUserGetGroups](../libraries/netapi32/NetUserGetGroups.md)  
[NetUserGetLocalGroups](../libraries/netapi32/NetUserGetLocalGroups.md)  
