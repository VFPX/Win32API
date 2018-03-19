[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Locking the workstation

## Before you begin:
The LockWorkStation function has the same result as pressing Ctrl+Alt+Del and clicking Lock Workstation. To unlock the workstation, the user must log in.  

The code sample shows how to link code execution to the Lock and Unlock events (requires VFP9).  

  
***  


## Code:
```foxpro  
LOCAL oForm As Tform
oForm=CREATEOBJECT("Tform")
oForm.Show(1)
* end of main

DEFINE CLASS Tform As Form
#DEFINE NOTIFY_FOR_THIS_SESSION 0
#DEFINE NOTIFY_FOR_ALL_SESSIONS 1
#DEFINE WM_WTSSESSION_CHANGE 0x02b1
#DEFINE WTS_SESSION_LOCK 7
#DEFINE WTS_SESSION_UNLOCK 8
#DEFINE GWL_WNDPROC -4

PROTECTED hOrigProc
	hOrigProc=0

	Width=500
	Height=300
	Autocenter=.T.
	
	ADD OBJECT SessionNotify As TSessionNotify
	ADD OBJECT cmd As CommandButton WITH Left=210,;
		Top=240, Width=120, Height=27, Caption="Lock Station"

PROCEDURE Destroy
	THIS.ReleaseBinding

PROCEDURE cmd.Click
	ThisForm.LockStation

PROCEDURE ReleaseBinding
	= UNBINDEVENTS(THIS.HWnd)
	THIS.SessionNotify.ClearNotification

PROCEDURE LockStation
	THIS.ReleaseBinding
	THIS.hOrigProc = GetWindowLong(THIS.HWnd, GWL_WNDPROC)

	IF LockWorkStation()=0
		LOCAL nError
		nError = GetLastError()
		= MESSAGEBOX("The LockWorkStation() failed     " + CHR(13) +;
			"with error code " + TRANSFORM(nError))
		RETURN
	ENDIF

	IF VERSION(5) >= 900
		THIS.SessionNotify.SetNotification(THIS.HWnd)
		= BINDEVENT(THIS.HWnd, WM_WTSSESSION_CHANGE, THIS, "WindowProc")
	ENDIF

PROCEDURE OnSessionLock
* this code executes upon locking a session
* at this point do not request user response
* and do not call any time-consuming routines
	ACTIVATE SCREEN
	? "The workstation has been locked at", DATETIME()

PROCEDURE OnSessionUnlock
* this code executes when a session has been unlocked
	= MESSAGEBOX("The workstation has just been unlocked!     " + CHR(13) +;
		TRANSFORM(DATETIME()), 48, SYS(0))

PROTECTED PROCEDURE WindowProc(hWindow as Integer,;
	nMsgID as Integer, wParam as Integer, lParam as Integer)
* requires VFP9, otherwise ignored

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID=WM_WTSSESSION_CHANGE
		DO CASE
		CASE wParam=WTS_SESSION_LOCK
			THIS.OnSessionLock

		CASE wParam=WTS_SESSION_UNLOCK
			THIS.OnSessionUnlock

		OTHERWISE
			ACTIVATE SCREEN
			? DATETIME(), "WM_WTSSESSION_CHANGE: " +;
				"wParam=" + TRANSFORM(wParam,"@0") +;
				", lParam=" + TRANSFORM(lParam,"@0")
		ENDCASE

	OTHERWISE
	* pass control to the original window procedure
		nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
			m.nMsgID, m.wParam, m.lParam)
	ENDCASE
RETURN nReturn
ENDDEFINE

DEFINE CLASS TSessionNotify As Custom
PROTECTED hWindow
	hWindow=0
	Visible=.F.

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	THIS.ClearNotification

PROCEDURE ClearNotification
	IF THIS.hWindow <> 0
		= WTSUnRegisterSessionNotification(THIS.hWindow)
		THIS.hWindow=0
	ENDIF

PROCEDURE SetNotification(hWindow)
	THIS.ClearNotification

	LOCAL nResult
	nResult = WTSRegisterSessionNotification(;
		hWindow, NOTIFY_FOR_ALL_SESSIONS)

	IF nResult <> 0
		THIS.hWindow=m.hWindow
	ENDIF

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER LockWorkStation IN user32

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

	DECLARE INTEGER WTSRegisterSessionNotification IN Wtsapi32;
		INTEGER hWindow, LONG dwFlags

	DECLARE INTEGER WTSUnRegisterSessionNotification IN wtsapi32;
		INTEGER hWindow

ENDDEFINE  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[LockWorkStation](../libraries/user32/LockWorkStation.md)  
[WTSRegisterSessionNotification](../libraries/wtsapi32/WTSRegisterSessionNotification.md)  
[WTSUnRegisterSessionNotification](../libraries/wtsapi32/WTSUnRegisterSessionNotification.md)  

## Comment:
The LockWorkStation function is callable only by processes running on the interactive desktop. In addition, the user must be logged on, and the workstation cannot already be locked.  
  
To receive notification when the user logs in, use the WTSRegisterSessionNotification function to receive WM_WTSSESSION_CHANGE messages.  
  
* * *  
Feb.2, 2009: code sample rewritten.  
  
***  

