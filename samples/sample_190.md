[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Open and close a Simple MAPI Session

## Code:
```foxpro  
DO declare

#DEFINE MAPI_LOGON_UI 1
#DEFINE MAPI_NEW_SESSION 2
#DEFINE MAPI_FORCE_DOWNLOAD 0x1000
#DEFINE MAPI_PASSWORD_UI 0x20000

#DEFINE SUCCESS_SUCCESS 0
#DEFINE MAPI_E_USER_ABORT 1
#DEFINE MAPI_E_FAILURE 2
#DEFINE MAPI_E_LOGIN_FAILURE 3
#DEFINE MAPI_E_INSUFFICIENT_MEMORY 5
#DEFINE MAPI_E_TOO_MANY_SESSIONS 8

	LOCAL lnResult, hSession, lcStoredPath
	lcStoredPath = SYS(5) + SYS(2003)
	hSession = 0

	lnResult = MAPILogon(0, "", "",;
		BITOR(MAPI_LOGON_UI, MAPI_NEW_SESSION),;
		0, @hSession)

	IF lnResult = SUCCESS_SUCCESS
		? "MAPI Session handle:", hSession
		= MAPILogoff(hSession, 0,0,0)
	ELSE
		? "Not logged:", lnResult
	ENDIF

	SET DEFAULT TO (m.lcStoredPath)

PROCEDURE declare
	DECLARE INTEGER MAPILogon IN mapi32;
		INTEGER ulUIParam, STRING lpszProfileName,;
		STRING lpszPassword, INTEGER flFlags,;
		INTEGER ulReserved, INTEGER @lplhSession

	DECLARE INTEGER MAPILogoff IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam,;
		INTEGER flFlags, INTEGER ulReserved  
```  
***  


## Listed functions:
[MAPILogoff](../libraries/mapi32/MAPILogoff.md)  
[MAPILogon](../libraries/mapi32/MAPILogon.md)  

## Comment:
Notice the saving and restoring of active directory.  
  
***  

