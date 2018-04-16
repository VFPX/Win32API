[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Finding out if the current user is the Guest account

## Short description:
In this code sample, the CurrentUser class wraps call to the NetUserGetInfo that populates USER_INFO_1 structure. The usri1_priv member of this struture indicates if the user account is Guest or Admin.  
***  


## Before you begin:
In the code sample below, the *CurrentUser* class wraps call to the NetUserGetInfo that populates [USER_INFO_1](http://msdn.microsoft.com/en-us/library/aa371109(v=VS.85).aspx) structure for the current user.  

The *usri1_priv* member of this struture indicates if the user account is Guest or Admin.  
  
***  


## Code:
```foxpro  
LOCAL oUser As CurrentUser
oUser = CREATEOBJECT("CurrentUser")
WITH oUser
	? .GetUserName()
	? .IsUserAdmin()
	? .IsUserGuest()
ENDWITH
* end of main

DEFINE CLASS CurrentUser As Session
#DEFINE USER_PRIV_GUEST 0
#DEFINE USER_PRIV_USER 1
#DEFINE USER_PRIV_ADMIN 2

	PROTECTED UserName, UserPrivLevel
	UserName=""
	UserPrivLevel=0

PROCEDURE Init
	THIS.declare
	THIS.GetUserInfo

FUNCTION IsUserAdmin() As Boolean
RETURN (BITAND(THIS.UserPrivLevel,;
	USER_PRIV_ADMIN) <> 0)

FUNCTION IsUserGuest() As Boolean
RETURN (BITAND(THIS.UserPrivLevel,;
	USER_PRIV_GUEST) <> 0)

FUNCTION GetUserName() As String
RETURN THIS.UserName

PROCEDURE GetUserInfo
	LOCAL nUserInfo, nBufSize, cUserInfo
	STORE 0 TO nUserInfo, nBufSize

	WITH THIS
		.UserName=.GetCurrentUserName()

		* USER_INFO_1
		= NetUserGetInfo(NULL, .ToUnicode(.UserName),;
			1, @nUserInfo)
		
		NetApiBufferSize(nUserInfo, @nBufSize)

		cUserInfo = REPLICATE(CHR(0), nBufSize)
		MemToStr(@cUserInfo, nUserInfo, nBufSize)

		* 13=offset to usri1_priv member; 4=DWORD
		.UserPrivLevel = .buf2dword(;
			SUBSTR(m.cUserInfo, 13, 4))
	ENDWITH

PROTECTED FUNCTION GetCurrentUserName() As String
* just an example; parsing SYS(0) would suffice
	LOCAL nBufSize, cUserName
	nBufSize=0
	= GetUserName(NULL, @nBufSize)
	cUserName = REPLICATE(CHR(0), nBufSize)
	= GetUserName(@cUserName, @nBufSize)
RETURN STRTRAN(cUserName, CHR(0), "")

PROTECTED PROCEDURE declare

	DECLARE INTEGER NetUserGetInfo IN netapi32;
		STRING servername, STRING username,;
		INTEGER lvl, INTEGER @bufptr

	DECLARE INTEGER GetUserName IN advapi32;
		STRING @lpBuffer, INTEGER @nSize

	DECLARE INTEGER NetApiBufferFree IN netapi32;
		INTEGER Buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLen

PROTECTED FUNCTION ToUnicode(cStr As String) As String
RETURN STRCONV(m.cStr, 5)

PROTECTED FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

ENDDEFINE  
```  
***  


## Listed functions:
[GetUserName](../libraries/advapi32/GetUserName.md)  
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetUserGetInfo](../libraries/netapi32/NetUserGetInfo.md)  
