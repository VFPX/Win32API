[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using an Event Object. Part B: running an application responding to events

## Before you begin:
Compile this code into a separate executable and test with an executable created from the [Part A](sample_148.md) of this example. This is the name of the Event Object, that links two parts.  

Start Part A executable prior to the Part B.  
  
***  

## Code:
```foxpro  
PUBLIC frm, lcEventName
lcEventName = "TimeToGoHomeNotice"

frm = CreateObject ("Tform", lcEventName)
IF TYPE ("frm") = "O"
	frm.Visible = .T.
	READ EVENTS
ENDIF

DEFINE CLASS Tform As Form
#DEFINE watchingInterval  500

	Width=400
	Height=150
	Caption="Responding to events"
	BackColor=Rgb(230,250,230)
	AutoCenter=.T.
	hEvent=0
	
	ADD OBJECT tm As Timer WITH Interval=0
	
PROCEDURE  Init (lcName)
	DO decl

	_SCREEN.WindowState = 2
	_SCREEN.Caption = "Event Client"
	
	IF Not THIS.checkEvent(lcName)
		= MessageB ("Unable to locate the event: " + lcName)
		RETURN .F.
	ENDIF
	THIS.tm.Interval = watchingInterval

PROCEDURE  Destroy
	QUIT

PROCEDURE  tm.Timer
	IF ThisForm._signaled()
		ThisForm._notify
	ENDIF

PROCEDURE  checkEvent (lcName)
#DEFINE STANDARD_RIGHTS_REQUIRED  0xF0000
#DEFINE SYNCHRONIZE  0x100000

* STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 0x03
#DEFINE EVENT_ALL_ACCESS 0x1F0003

	THIS.hEvent = OpenEvent (EVENT_ALL_ACCESS, 0, lcName)
RETURN  Not (THIS.hEvent = 0)

PROCEDURE  _notify
#DEFINE SW_NORMAL  1
#DEFINE SW_SHOWMAXIMIZED 3

	* make this window active
	_SCREEN.WindowState = 1
	_SCREEN.WindowState = 2

	= MessageB ("Wake Up! It is time to go home.")
	THIS.tm.Interval = watchingInterval

PROCEDURE  _signaled
#DEFINE INFINITE  0xffffffff
#DEFINE WAIT_OBJECT_0           0

	LOCAL dwWaitResult
	dwWaitResult = WaitForSingleObject (THIS.hEvent, 0)

	IF dwWaitResult = WAIT_OBJECT_0
		= ResetEvent (THIS.hEvent)
		THIS.tm.Interval = 0
		RETURN .T.
	ENDIF
RETURN .F.

ENDDEFINE

PROCEDURE  decl
	DECLARE INTEGER OpenEvent IN kernel32;
		INTEGER dwDesiredAccess,;
		INTEGER bInheritHandle,;
		STRING  lpName

	DECLARE INTEGER ResetEvent IN kernel32 INTEGER hEvent

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle,;
		INTEGER dwMilliseconds  
```  
***  


## Listed functions:
[OpenEvent](../libraries/kernel32/OpenEvent.md)  
[ResetEvent](../libraries/kernel32/ResetEvent.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  
