[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Monitoring changes in a directory

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
Imagine that an application needs to be notified upon file changes in a particular directory: files added or deleted, changed, or accessed. The ChangeNotification function is an answer.   

After starting this code sample, try to add, change or delete files in the target directory (must be valid path). Create a FoxPro table in it and operate with its records.  

See also::

<!-- Anatoliy -->
* [FileSystemWatcher ActiveX Control for Visual FoxPro](?solution=8)   
* [Monitoring changes occurring within a directory](sample_400.md)  
* [Enumerating files opened on the network](sample_121.md)  
  
***  


## Code:
```foxpro  
PUBLIC oForm
oForm = CREATEOBJECT("Tform", SYS(2023)) && watching TEMP dir
oForm.Visible = .T.
* end of main

DEFINE CLASS Tform As Form
#DEFINE FILE_NOTIFY_CHANGE_FILE_NAME 1
#DEFINE FILE_NOTIFY_CHANGE_DIR_NAME 2
#DEFINE FILE_NOTIFY_CHANGE_ATTRIBUTES 4
#DEFINE FILE_NOTIFY_CHANGE_SIZE 8
#DEFINE FILE_NOTIFY_CHANGE_LAST_WRITE 16
#DEFINE FILE_NOTIFY_CHANGE_LAST_ACCESS 32
#DEFINE FILE_NOTIFY_CHANGE_CREATION 64
#DEFINE FILE_NOTIFY_CHANGE_SECURITY 128
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE WAIT_OBJECT_0 0
#DEFINE WATCHING_INTERVAL 1000  && milliseconds

PROTECTED hNotify, PathBeingWatched

	Width=400
	Height=150
	MaxButton=.F.
	BorderStyle=2
	AutoCenter=.T.
	Caption="Watching directory"

	hNotify=INVALID_HANDLE_VALUE
	PathBeingWatched=""
	
	ADD OBJECT lblTarget As Label WITH Left=10, Top=7, Autosize=.T.
	ADD OBJECT tm As Timer WITH Interval=0

	ADD OBJECT lblAlert As Label WITH Left=10, Top=30,;
	Autosize=.T., Caption="Notification:"

FUNCTION Init(cPath)
	THIS.declare
	THIS.PathBeingWatched = FULLPATH(m.cPath)

	IF Not THIS.StartWatching()
		= MESSAGEBOX("Notification handle error.")
		RETURN .F.
	ENDIF

PROCEDURE Destroy
	THIS.StopWatching

PROTECTED FUNCTION StartWatching
	LOCAL lResult

	* no subdirs watched
	THIS.hNotify = FindFirstChangeNotification(;
		THIS.PathBeingWatched, 0,;
		FILE_NOTIFY_CHANGE_FILE_NAME +;
		FILE_NOTIFY_CHANGE_LAST_WRITE )

	lResult = (THIS.hNotify <> INVALID_HANDLE_VALUE)

	IF lResult
		THIS.lblTarget.Caption = "Watched: " +;
			THIS.PathBeingWatched
		THIS.tm.Interval = WATCHING_INTERVAL
	ENDIF
RETURN  lResult

PROTECTED PROCEDURE ContinueWatching
	IF FindNextChangeNotification(THIS.hNotify) = 0
		THIS.StopWatching
		= MESSAGEBOX("Request error.")
		THIS.Release
	ENDIF
	THIS.tm.Interval = WATCHING_INTERVAL

PROTECTED FUNCTION StopWatching
	THIS.tm.Interval = 0
	IF THIS.hNotify <> INVALID_HANDLE_VALUE
		= FindCloseChangeNotification(THIS.hNotify)
	ENDIF

FUNCTION _signaled		&& returns signaled state
RETURN (WaitForSingleObject(THIS.hNotify, 0) = WAIT_OBJECT_0)

PROCEDURE _notify		&& triggered on event
	LOCAL cMessage
	cMessage = "Notification: " + TTOC(DATETIME())
	THIS.lblAlert.Caption = cMessage
	ACTIVATE SCREEN
	? cMessage
	THIS.ContinueWatching

PROCEDURE tm.Timer
	IF ThisForm._signaled()
		ThisForm._notify
	ENDIF

PROTECTED PROCEDURE declare
	DECLARE SHORT FindNextChangeNotification IN kernel32;
		INTEGER hChangeHandle

	DECLARE SHORT FindCloseChangeNotification IN kernel32;
		INTEGER hChangeHandle

	DECLARE INTEGER FindFirstChangeNotification IN kernel32;
		STRING lpPathName, INTEGER bWatchSubtree,;
		INTEGER dwNotifyFilter

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds

ENDDEFINE  
```  
***  


## Listed functions:
[FindCloseChangeNotification](../libraries/kernel32/FindCloseChangeNotification.md)  
[FindFirstChangeNotification](../libraries/kernel32/FindFirstChangeNotification.md)  
[FindNextChangeNotification](../libraries/kernel32/FindNextChangeNotification.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  
