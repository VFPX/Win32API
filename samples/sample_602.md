[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to load a user profile

## Before you begin:
Shows how to load user profile data by calling LoadUserProfile Win32 function.  
  
***  


## Code:
```foxpro  
LOCAL oUser as LogonUserHelper
oUser = CREATEOBJECT("LogonUserHelper", "", "MyUserName", "MyUserPwd")
oUser.LoadUserProfile()

DEFINE CLASS LogonUserHelper as Custom
#DEFINE LOGON32_LOGON_INTERACTIVE  2
#DEFINE LOGON32_PROVIDER_DEFAULT   0
#DEFINE TOKEN_ADJUST_PRIVILEGES 0x0020
#DEFINE TOKEN_QUERY 0x0008
#DEFINE SE_PRIVILEGE_ENABLED 2

#DEFINE SE_BACKUP_NAME "SeBackupPrivilege"
#DEFINE SE_RESTORE_NAME "SeRestorePrivilege"

HIDDEN UserToken, UserName, ProfileHandle
	UserToken = 0 && impersonation token
	ProfileHandle = 0

PROCEDURE Init(cDomain as string, cUsr as String, cPwd as String)
	THIS.declare

	LOCAL nToken, nResult
	nToken = 0

	nResult = LogonUser(cUsr, cDomain, cPwd,;
		LOGON32_LOGON_INTERACTIVE,;
		LOGON32_PROVIDER_DEFAULT,;
		@nToken)
	
	IF m.nResult = 0
	*   87 = ERROR_INVALID_PARAMETER
	* 1326 = ERROR_LOGON_FAILURE
		= MESSAGEBOX("Call to LogonUser failed: " +;
			TRANSFORM(GetLastError()))
		RETURN .F.
	ENDIF
	
	THIS.UserToken = m.nToken
	THIS.UserName = m.cUsr
	THIS.AdjustTokenPrivileges

PROCEDURE Destroy
	THIS.UnloadUserProfile
	THIS.ReleaseUserToken

PROCEDURE GetUserToken
RETURN THIS.UserToken

PROCEDURE GetProfileHandle
RETURN THIS.ProfileHandle

PROCEDURE ReleaseUserToken
	IF THIS.UserToken <> 0
		= CloseHandle(THIS.UserToken)
		THIS.UserToken = 0
		? "User token released"
	ENDIF

PROCEDURE UnloadUserProfile
	IF THIS.ProfileHandle = 0
		RETURN .T.
	ENDIF
	
	IF UnloadUserProfile(THIS.UserToken, THIS.ProfileHandle) <> 0
		? "User profile unloaded"
		THIS.ProfileHandle = 0
		RETURN .T.
	ENDIF
RETURN .F.

PROCEDURE AdjustTokenPrivilege(cPrivilege as String)
	LOCAL cGuid, cTokenPrivileges, hToken, nResult

	cGuid = REPLICATE(CHR(0), 8)
	= LookupPrivilegeValue(0, m.cPrivilege, @cGuid)

	cTokenPrivileges = num2dword(1) +;
		m.cGuid + num2dword(SE_PRIVILEGE_ENABLED)
	
	hToken=0

	= OpenProcessToken(GetCurrentProcess(),;
		BITOR(TOKEN_ADJUST_PRIVILEGES, TOKEN_QUERY), @hToken)

	= AdjustTokenPrivileges(;
		m.hToken,;
		0,;
		@cTokenPrivileges,;
		0,0,0)

	nResult = GetLastError()
	IF m.nResult <> 0
	* 6 - ERROR_INVALID_HANDLE
	* 1300 - ERROR_NOT_ALL_ASSIGNED
		? "Call to AdjustTokenPrivileges failed:", m.nResult
	ENDIF

	= CloseHandle(m.hToken)

PROCEDURE AdjustTokenPrivileges
* For LoadUserProfile to succeed
* the calling process must have
* the SE_RESTORE_NAME and SE_BACKUP_NAME privileges.

	THIS.AdjustTokenPrivilege(SE_BACKUP_NAME)
	THIS.AdjustTokenPrivilege(SE_RESTORE_NAME)

PROCEDURE LoadUserProfile() as Number
* Returns 0 if successful, or an error code
* 1314 - ERROR_PRIVILEGE_NOT_HELD

	IF NOT THIS.UnloadUserProfile()
		RETURN -1
	ENDIF
	
	LOCAL oUserName as PChar, nBufsize, cBuffer,;
		oBuffer as PChar

	oUserName = CREATEOBJECT("PChar", THIS.UserName + CHR(0))

	nBufsize = 32
	
	cBuffer = num2dword(m.nBufsize) +;
		num2dword(0) +;
		num2dword(oUserName.getaddr())

	cBuffer = PADR(m.cBuffer, m.nBufsize, CHR(0))
	oBuffer = CREATEOBJECT("PChar", m.cBuffer)

	IF LoadUserProfile(THIS.UserToken, oBuffer.getaddr()) = 0
		RETURN GetLastError()
	ENDIF
	
*!*	typedef struct _PROFILEINFO {
*!*	  DWORD  dwSize;		0:4
*!*	  DWORD  dwFlags;		4:4
*!*	  LPTSTR lpUserName;	8:4
*!*	  LPTSTR lpProfilePath;	12:4
*!*	  LPTSTR lpDefaultPath;	16:4
*!*	  LPTSTR lpServerName;	20:4
*!*	  LPTSTR lpPolicyPath;	24:4
*!*	  HANDLE hProfile;		28:4 && THIS.ProfileHandle
*!*	} PROFILEINFO, *LPPROFILEINFO;
	
	cBuffer = oBuffer.getvalue()
	THIS.ProfileHandle = buf2dword(SUBSTR(m.cBuffer, 29, 4))

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetCurrentProcess IN kernel32

	DECLARE INTEGER LogonUser IN advapi32;
		STRING lpszUsername, STRING lpszDomain,;
		STRING lpszPassword, INTEGER dwLogonType,;
		INTEGER dwLogonProvider, INTEGER @phToken

	DECLARE INTEGER LoadUserProfile IN userenv;
		INTEGER hToken, INTEGER lpProfileInfo

	DECLARE INTEGER UnloadUserProfile IN userenv;
		INTEGER hToken, INTEGER hProfile

	DECLARE INTEGER OpenProcessToken IN advapi32;
		INTEGER ProcessHandle, LONG DesiredAccess,;
		INTEGER @TokenHandle

	DECLARE INTEGER LookupPrivilegeValue IN advapi32;
		INTEGER lpSystemName, STRING lpName,;
		STRING @lpLuid

	DECLARE INTEGER AdjustTokenPrivileges IN advapi32;
		INTEGER TokenHandle, INTEGER DisableAllPrivileges,;
		STRING @NewState, LONG BufferLength,;
		INTEGER PreviousState, INTEGER ReturnLength

ENDDEFINE

DEFINE CLASS PChar As Session
PROTECTED hMem

PROCEDURE Init(lcString)
	THIS.hMem = 0
	THIS.setValue(lcString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr
RETURN THIS.hMem

FUNCTION GetValue
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue(lcString)
#DEFINE GMEM_FIXED 0
#DEFINE GMEM_MOVEABLE 2
#DEFINE GMEM_ZEROINIT 0x0040

	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(0x0040, lnSize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[AdjustTokenPrivileges](../libraries/advapi32/AdjustTokenPrivileges.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetCurrentProcess](../libraries/kernel32/GetCurrentProcess.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[LoadUserProfile](../libraries/userenv/LoadUserProfile.md)  
[LogonUser](../libraries/advapi32/LogonUser.md)  
[LookupPrivilegeValue](../libraries/advapi32/LookupPrivilegeValue.md)  
[OpenProcessToken](../libraries/advapi32/OpenProcessToken.md)  
[UnloadUserProfile](../libraries/userenv/UnloadUserProfile.md)  

## Comment:
To test this code start VFP session as admin. Otherwise the AdjustTokenPrivileges may fail with error 1300 (ERROR_NOT_ALL_ASSIGNED).  
  
***  

