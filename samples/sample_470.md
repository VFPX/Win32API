[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to run FoxPro application under different user name (impersonating user)

## Short description:
This example shows how to switch to another domain user within FoxPro application. It can be used for providing limited access to network resources (files, printers) for network users.  
***  


## Before you begin:
Replace domain, user and password with valid names.  
  
***  


## Code:
```foxpro  
#DEFINE LOGON32_LOGON_INTERACTIVE 2
#DEFINE LOGON32_PROVIDER_DEFAULT  0
DO decl

	? "Regular user:", SYS(0)

	LOCAL hToken, cUser, cDomain, cPwd
	hToken=0

	cDomain="MYDOMAIN"
	cUser="DataUser"

*!*		cDomain=""
*!*		cUser="DataUser@MYDOMAIN"

	cPwd="DataUserPwd"

	IF LogonUser(cUser, cDomain, cPwd, LOGON32_LOGON_INTERACTIVE,;
		LOGON32_PROVIDER_DEFAULT, @hToken) = 0
		? "LogonUser failed with error:", GetLastError()
		RETURN .F.
	ENDIF
	
	IF ImpersonateLoggedOnUser(hToken) = 0
		? "ImpersonateLoggedOnUser failed with error:", GetLastError()
		= CloseHandle(hToken)
		RETURN .F.
	ENDIF

	? "Impersonated user:", SYS(0)

	= CloseHandle(hToken)
	= RevertToSelf()
* end of main

PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER RevertToSelf IN advapi32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER ImpersonateLoggedOnUser IN advapi32 INTEGER hToken

	DECLARE INTEGER LogonUser IN advapi32;
		STRING lpszUsername, STRING lpszDomain,;
		STRING lpszPassword, INTEGER dwLogonType,;
		INTEGER dwLogonProvider, INTEGER @phToken  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[ImpersonateLoggedOnUser](../libraries/advapi32/ImpersonateLoggedOnUser.md)  
[LogonUser](../libraries/advapi32/LogonUser.md)  
[RevertToSelf](../libraries/advapi32/RevertToSelf.md)  

## Comment:
Links:  
* <a href="http://fox.wikis.com/wc.dll?Wiki~RunAsAnotherUser">Run As Another User</a> on FoxPro Wiki  

***  

