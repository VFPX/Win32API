[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to enable the SE_SHUTDOWN_NAME privilege for the application

## Short description:
To shut down or to reboot the system (API calls ExitWindowsEx, InitiateShutdown and others) the process must have the SE_SHUTDOWN_NAME privilege (default behaviour on Vista).  
***  


## Before you begin:
To shut down or to reboot the system (API calls ExitWindowsEx, InitiateShutdown and others) the process must have the SE_SHUTDOWN_NAME privilege (default behaviour on Vista).  

![](../images/windowsrestartdialog.png)  

See also: 

* [How to initiate System shutdown](sample_122.md)  
* [Closing Windows](sample_036.md)  
* [Using the RestartDialog function](sample_361.md)  
  
***  


## Code:
```foxpro  
#DEFINE TOKEN_ADJUST_PRIVILEGES 0x0020
#DEFINE TOKEN_QUERY 0x0008
#DEFINE SE_PRIVILEGE_ENABLED 2
#DEFINE SE_SHUTDOWN_NAME "SeShutdownPrivilege"

#DEFINE EWX_SHUTDOWN 1
#DEFINE EWX_REBOOT 2
#DEFINE EWX_FORCE 4
#DEFINE SHTDN_REASON_MAJOR_OPERATINGSYSTEM 0x00020000
#DEFINE SHTDN_REASON_MINOR_UPGRADE 0x00000003
#DEFINE SHTDN_REASON_FLAG_PLANNED 0x80000000

DO declare
IF SetPrivilege(SE_SHUTDOWN_NAME)
*	DO SystemShutdown
ENDIF
* end of main

FUNCTION SetPrivilege(cPrivilegeName As String) As Boolean
	LOCAL hToken, nResult, cPrivilegeLuid

	* opens access token associated with the current process
	hToken=0
	nResult = OpenProcessToken(GetCurrentProcess(),;
		BITOR(TOKEN_ADJUST_PRIVILEGES, TOKEN_QUERY), @hToken)

	IF nResult = 0
		? "OpenProcessToken call failed:", GetLastError()
		RETURN .F.
	ENDIF

	*!*	typedef struct _LUID {
	*!*	  DWORD LowPart;
	*!*	  LONG  HighPart;
	*!*	} LUID, *PLUID
	cPrivilegeLuid = REPLICATE(CHR(0), 8)  && LUID

	* obtaining LUID for the privilege
	nResult = LookupPrivilegeValue(0,;
		m.cPrivilegeName, @cPrivilegeLuid)

	IF nResult=0
		? "LookupPrivilegeValue call failed:", GetLastError()
		= CloseHandle(hToken)
		RETURN .F.
	ENDIF

	LOCAL cTokenPrivileges, nPrivilegeCount

	*!*	typedef struct _TOKEN_PRIVILEGES {
	*!*	  DWORD               PrivilegeCount;
	*!*	  LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
	*!*	} TOKEN_PRIVILEGES

	*!*	typedef struct _LUID_AND_ATTRIBUTES {
	*!*	  LUID  Luid;
	*!*	  DWORD Attributes;
	*!*	} LUID_AND_ATTRIBUTES

	* populating TOKEN_PRIVILEGES structure
	nPrivilegeCount=1
	cTokenPrivileges = num2dword(nPrivilegeCount) +;
		m.cPrivilegeLuid + num2dword(SE_PRIVILEGE_ENABLED)

	* enabling the privilege
	nResult = AdjustTokenPrivileges(hToken, 0,;
		@cTokenPrivileges, 0,0,0)

	IF nResult=0
		? "AdjustTokenPrivileges call failed:", GetLastError()
		RETURN .F.
	ENDIF

	= CloseHandle(hToken)
	* if this point is reached then the process has sufficient privileges
	* to call the ExitWindowsEx or similar API function shutting down
	* or rebooting the system
RETURN .T.

PROCEDURE SystemShutdown
	LOCAL nFlags, nReason

	nFlags = BITOR(EWX_SHUTDOWN, EWX_FORCE)

	nReason = BITOR(SHTDN_REASON_MAJOR_OPERATINGSYSTEM,;
		SHTDN_REASON_MINOR_UPGRADE,;
		SHTDN_REASON_FLAG_PLANNED)

	nResult = ExitWindowsEx(nFlags, nReason)
	IF nResult=0
	* 1314=ERROR_PRIVILEGE_NOT_HELD
		? "ExitWindowsEx call failed:", GetLastError()
	ENDIF
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetCurrentProcess IN kernel32

	DECLARE INTEGER CloseHandle IN kernel32;
		INTEGER hObject

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

	DECLARE INTEGER ExitWindowsEx IN user32;
		INTEGER uFlags, INTEGER dwReserved

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
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
[AdjustTokenPrivileges](../libraries/advapi32/AdjustTokenPrivileges.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[ExitWindowsEx](../libraries/user32/ExitWindowsEx.md)  
[GetCurrentProcess](../libraries/kernel32/GetCurrentProcess.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[LookupPrivilegeValue](../libraries/advapi32/LookupPrivilegeValue.md)  
[OpenProcessToken](../libraries/advapi32/OpenProcessToken.md)  
