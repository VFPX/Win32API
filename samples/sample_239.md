[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining a handle to the desktop associated with the calling thread

## Code:
```foxpro  
#DEFINE UOI_FLAGS    1
#DEFINE UOI_NAME     2
#DEFINE UOI_TYPE     3
#DEFINE UOI_USER_SID 4

DO declare

LOCAL lnThreadId, hDesktop, lcSid
lnThreadId = GetCurrentThreadId()
hDesktop = GetThreadDesktop(lnThreadId)

? "Object type:", GetObjString(hDesktop, UOI_TYPE)
? "Object name:", GetObjString(hDesktop, UOI_NAME)

* obtain the SID (security identifier) structure
* that identifies the user currently associated
* with the desktop

lcSid = GetObjData(hDesktop, UOI_USER_SID)
? "SID length:", GetLengthSid(lcSid)
? "SID is valid:", Iif(IsValidSid(lcSid)=0, "No","Yes")

FUNCTION GetObjString(hDesktop, lnIndex)
	LOCAL lcBuffer, lnBufsize
	lnBufsize = 1024
	lcBuffer = Repli(Chr(0), lnBufsize)
	IF GetUserObjectInformation(hDesktop, lnIndex,;
		@lcBuffer, lnBufsize, @lnBufsize) <> 0
		RETURN LEFT(lcBuffer, lnBufsize-1)
	ENDIF
RETURN ""

FUNCTION GetObjData(hDesktop, lnIndex)
	LOCAL lcBuffer, lnBufsize
	lnBufsize = 1024
	lcBuffer = Repli(Chr(0), lnBufsize)
	IF GetUserObjectInformation(hDesktop, lnIndex,;
		@lcBuffer, lnBufsize, @lnBufsize) <> 0
		RETURN LEFT(lcBuffer, lnBufsize)
	ENDIF
RETURN ""

PROCEDURE declare
	DECLARE INTEGER GetThreadDesktop IN user32 INTEGER dwThreadId
	DECLARE INTEGER GetCurrentThreadId IN kernel32
	DECLARE INTEGER IsValidSid IN advapi32 STRING pSid
	DECLARE INTEGER GetLengthSid IN advapi32 STRING pSid

	DECLARE INTEGER GetUserObjectInformation IN user32;
		INTEGER hObj, INTEGER nIndex, STRING @pvInfo,;
		INTEGER nLength, INTEGER @lpnLengthNeeded  
```  
***  


## Listed functions:
[GetCurrentThreadId](../libraries/kernel32/GetCurrentThreadId.md)  
[GetLengthSid](../libraries/advapi32/GetLengthSid.md)  
[GetThreadDesktop](../libraries/user32/GetThreadDesktop.md)  
[GetUserObjectInformation](../libraries/user32/GetUserObjectInformation.md)  
[IsValidSid](../libraries/advapi32/IsValidSid.md)  
