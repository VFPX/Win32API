[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Adding and deleting User Accounts

## Short description:
FoxPro class UserAccount wraps NetUserAdd, NetUserDel, NetUserGetInfo and NetUserSetInfo API calls to add, delete and modify user accounts on a server.  
***  


## Before you begin:
The class below wraps NetUserAdd, NetUserDel, NetUserGetInfo and NetUserSetInfo API calls with methods that can add, delete and modify user accounts on a server.  

Use another example, [Obtaining information about all user accounts on a server](sample_249.md), to review the user accounts.  
  
***  


## Code:
```foxpro  
DEFINE CLASS UserAccount As Session
#DEFINE NERR_Success 0
#DEFINE USER_PRIV_GUEST 0
#DEFINE USER_PRIV_USER 1
#DEFINE USER_PRIV_ADMIN 2

PROTECTED servername, username, password, passwordage,;
	userprivlevel, homedir, comment, flags, scriptpath
	servername=""
	username=""
	password=""
	passwordage=0
	userprivlevel=0
	homedir=""
	comment=""
	flags=0
	scriptpath=""
	errorcode=0

PROCEDURE Init(cServer, cUsername)
	THIS.declare
	IF VARTYPE(cServer)="C" AND NOT EMPTY(cServer)
		THIS.servername = m.cServer
	ELSE
		THIS.servername = GETENV("COMPUTERNAME")
	ENDIF
	THIS.username = m.cUsername
	
	* retrieves user account information (if any)
	THIS.UserGetInfo

PROCEDURE GetServername
RETURN THIS.servername

PROCEDURE GetUsername
RETURN THIS.username

PROCEDURE GetPassword
RETURN THIS.password

PROCEDURE GetPasswordAge
RETURN THIS.passwordage

PROCEDURE GetUserPrivLevel
RETURN THIS.userprivlevel

PROCEDURE GetHomedir
RETURN THIS.homedir

PROCEDURE GetComment
RETURN THIS.comment

PROCEDURE GetFlags
RETURN THIS.flags

PROCEDURE GetScriptPath
RETURN THIS.scriptpath

PROCEDURE SetPassword(cValue)
RETURN THIS.UserSetStringProperty(cValue, 1003)

PROCEDURE SetUserPrivLevel(vValue)
RETURN THIS.UserSetDwordProperty(vValue, 1005)

PROCEDURE SetHomedir(cValue)
RETURN THIS.UserSetStringProperty(cValue, 1006)

PROCEDURE SetComment(cValue)
RETURN THIS.UserSetStringProperty(cValue, 1007)

PROCEDURE SetFlags(vValue)
RETURN THIS.UserSetDwordProperty(vValue, 1008)

PROCEDURE SetScriptPath(cValue)
RETURN THIS.UserSetStringProperty(cValue, 1009)

PROCEDURE UserAdd
	LOCAL cBuffer, oUsername, oPwd, oHomedir,;
		oComment, oScriptpath

	oUsername = CREATEOBJECT("PChar",;
		THIS.ToUnicode(THIS.username))

	cBuffer = num2dword(oUsername.GetAddr()) +;
		num2dword(0) + num2dword(0) +;
		num2dword(USER_PRIV_USER) +;
		num2dword(0) + num2dword(0) +;
		num2dword(0) + num2dword(0)

	THIS.errorcode = NetUserAdd(;
		THIS.ToUnicode(THIS.servername),;
		1, @cBuffer, 0)

	IF THIS.errorcode = NERR_Success
		THIS.UserGetInfo
	ENDIF
RETURN (THIS.errorcode=NERR_Success)

PROCEDURE UserDel
	THIS.errorcode = NetUserDel(;
		THIS.ToUnicode(THIS.servername),;
		THIS.ToUnicode(THIS.username))
RETURN (THIS.errorcode=NERR_Success)

FUNCTION UserExists
RETURN THIS.UserGetInfo()

PROCEDURE UserGetInfo
	LOCAL hBuffer
	hBuffer=0

	THIS.errorcode = NetUserGetInfo(;
		THIS.ToUnicode(THIS.servername),;
		THIS.ToUnicode(THIS.username), 1, @hBuffer)

	IF THIS.errorcode = NERR_Success
		THIS.ParseUserInfo(hBuffer)
	ENDIF
	= NetApiBufferFree(hBuffer)
RETURN (THIS.errorcode=NERR_Success)

PROCEDURE ParseUserInfo(hBuffer)
	LOCAL nBufsize, cBuffer, nOffs

	nBufsize=0
	THIS.errorcode = NetApiBufferSize(hBuffer, @nBufsize)
	IF THIS.errorcode <> NERR_Success
		RETURN
	ENDIF

	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, hBuffer, nBufsize)
	
	THIS.username = THIS.ReadString(@cBuffer,;
		buf2dword(SUBSTR(cBuffer, 1,4))-hBuffer+1)

	THIS.password = THIS.ReadString(@cBuffer,;
		buf2dword(SUBSTR(cBuffer, 5,4))-hBuffer+1)

	THIS.passwordage = buf2dword(SUBSTR(cBuffer, 9,4))
	THIS.userprivlevel = buf2dword(SUBSTR(cBuffer, 13,4))

	THIS.homedir = THIS.ReadString(@cBuffer,;
		buf2dword(SUBSTR(cBuffer, 17,4))-hBuffer+1)

	THIS.comment = THIS.ReadString(@cBuffer,;
		buf2dword(SUBSTR(cBuffer, 21,4))-hBuffer+1)

	THIS.flags = buf2dword(SUBSTR(cBuffer, 25,4))

	THIS.scriptpath = THIS.ReadString(@cBuffer,;
		buf2dword(SUBSTR(cBuffer, 29,4))-hBuffer+1)

PROCEDURE ReadString(cBuffer, nOffs)
* reads Unicode string from the string buffer at given offset
	IF nOffs <= 0
		RETURN ""
	ENDIF

	LOCAL cResult, cDuo
	cResult = ""
	DO WHILE BETWEEN(nOffs, 1, LEN(cBuffer))
		cDuo = SUBSTR(cBuffer, nOffs, 2)
		IF cDuo = CHR(0)+CHR(0)
			EXIT
		ELSE
			cResult = cResult + cDuo
			nOffs = nOffs + 2
		ENDIF
	ENDDO
RETURN THIS.FromUnicode(cResult)

PROTECTED PROCEDURE UserSetProperty(cBuffer, nLevel)
	THIS.errorcode = NetUserSetInfo(;
		THIS.ToUnicode(THIS.servername),;
		THIS.ToUnicode(THIS.username),;
		m.nLevel, @cBuffer, 0)

	IF THIS.errorcode = NERR_Success
		THIS.UserGetInfo
	ENDIF
RETURN (THIS.errorcode=NERR_Success)

PROTECTED PROCEDURE UserSetStringProperty(cValue, nLevel)
	LOCAL oBuffer
	oBuffer = CREATEOBJECT("PChar",;
		THIS.ToUnicode(cValue))
RETURN THIS.UserSetProperty(num2dword(oBuffer.GetAddr()), nLevel)

PROTECTED PROCEDURE UserSetDwordProperty(nValue, nLevel)
RETURN THIS.UserSetProperty(num2dword(m.nValue), nLevel)

FUNCTION ToUnicode(cStr)
RETURN STRCONV(cStr+CHR(0),5)

FUNCTION FromUnicode(cStr)
RETURN STRCONV(cStr, 6)

PROCEDURE declare
	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLen

	DECLARE INTEGER NetUserAdd IN netapi32;
		STRING servername, INTEGER lvl,;
		STRING @buf, INTEGER parm_err

	DECLARE INTEGER NetUserSetInfo IN netapi32;
		STRING servername, STRING username,;
		INTEGER lvl, STRING @buf, INTEGER parm_err

	DECLARE INTEGER NetUserGetInfo IN netapi32;
		STRING servername, STRING username,;
		INTEGER lvl, INTEGER @bufptr

	DECLARE INTEGER NetUserDel IN netapi32;
		STRING servername, STRING username

ENDDEFINE

DEFINE CLASS PChar As Custom
PROTECTED hMem

PROCEDURE Init(lcString)
	THIS.hMem = 0
	THIS.setValue (lcString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION GetValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize  && returns allocated memory size (string length)
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue (lcString) && assigns new string value
#DEFINE GMEM_FIXED   0
	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE  && pchar

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetUserAdd](../libraries/netapi32/NetUserAdd.md)  
[NetUserDel](../libraries/netapi32/NetUserDel.md)  
[NetUserGetInfo](../libraries/netapi32/NetUserGetInfo.md)  
[NetUserSetInfo](../libraries/netapi32/NetUserSetInfo.md)  

## Comment:
In VFP versions 3 to 6 you may have to declare RtlMoveMemory as MemToStr and StrToMem not once but every time you call this function with either interface. Newer VFP versions allow at least two API declarations exist simultaneously.  
  
Use this program code to test the class. Replace "MyServer" with an empty string to access user accounts on the local computer.  

```foxpro
#DEFINE ERROR_ACCESS_DENIED 5  
#DEFINE ERROR_BAD_NETPATH 53  
#DEFINE NERR_UserNotFound 2221  
#DEFINE NERR_UserExists 2224  
  
LOCAL oUser As UserAccount  
oUser = CREATEOBJECT("UserAccount", "MyServer", "FoxApp")  
  
DO CASE  
  
CASE oUser.errorcode = 0  
	= MESSAGEBOX("User account " + oUser.GetUsername() +;  
		" exists on " + oUser.GetServername() + ".     ",;  
		64, VERSION())  
  
CASE oUser.errorcode = ERROR_BAD_NETPATH  
	= MESSAGEBOX("Server " + oUser.GetServername() +;  
		" not found or can not be accessed.     ",;  
		48, VERSION())  
  
CASE oUser.errorcode = ERROR_ACCESS_DENIED  
	= MESSAGEBOX("Access denied to Network " +;  
		"Management Functions on " +;  
		oUser.GetServername() +;  
		".     ", 48, VERSION())  
  
CASE oUser.errorcode = NERR_UserNotFound  
	nSelect = MESSAGEBOX("User account " +;  
		oUser.GetUsername() +;  
		" not found on " + oUser.GetServername() + ".     " +;  
		CHR(13)+CHR(13) +;  
		"Do you want to add this account?     ",;  
		32+4+256, VERSION())  
  
	IF nSelect = 6  
		IF oUser.UserAdd()  
			= MESSAGEBOX("User account " +;  
				oUser.GetUsername() +;  
				" added on " +;  
				oUser.GetServername() + ".     ",;  
				64, VERSION())  
		ELSE  
			= MESSAGEBOX("Method UserAdd " +;  
				"failed with error code " +;  
				TRANSFORM(oUser.errorcode) + ".     ",;  
				48, VERSION())  
		ENDIF  
	ENDIF  
ENDCASE  
  
IF oUser.UserExists()  
	oUser.SetComment("Temporary account. Delete after the testing.")  
*	oUser.UserDel  
ENDIF
```

* * *  
Read an article <a href="http://support.microsoft.com/default.aspx?scid=kb;en-us;306273">HOW TO: Add a User to the Local System by Using Directory Services and Visual C# .NET</a> on Microsoft Help and Support web site.  
  
***  

