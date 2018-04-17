[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to suspend or hibernate your system

## Before you begin:
Before testing this code make sure all important documents and applications on local computer are closed. This code suspends the system and wakes it up in about 30 seconds using the WaitableTimer object.   

See also:

* [How to initiate System shutdown (WinNT only)](sample_122.md)  
* [Closing Windows](sample_036.md)  
* [Restarting Windows](sample_361.md)  
* [Enabling the SE_SHUTDOWN_NAME privilege for the application](sample_552.md)  
  
***  


## Code:
```foxpro  
#DEFINE ES_CONTINUOUS 0x80000000
#DEFINE ES_DISPLAY_REQUIRED 2
#DEFINE ES_SYSTEM_REQUIRED 1

DO declare

IF IsPwrSuspendAllowed() = 0
	= MESSAGEBOX("This computer does not support " +;
		"sleep states.     ", 64)
	RETURN
ENDIF

* Parameters:
* suspend/hibernate
* request each running application
* keep wake events enabled

LOCAL nSuspendMode, nForceCritical, nDisableWake
nSuspendMode=0  && 0=suspend, 1=hibernate
nForceCritical=0 && broadcasts WM_POWERBROADCAST messages
nDisableWake=0  && system wake events enabled

IF MESSAGEBOX("The system is about to enter " +;
	IIF(nSuspendMode=0, "suspend (sleep)", "hibernation") +;
	" state.     " + CHR(13) + CHR(13) +;
	"Press Yes to proceed.", 48+4+256,;
	"Preparing to " + IIF(nSuspendMode=0, "Stand By", "Hibernate") + " ...") = 6

	* the WaitableTimer object is created and set to wake up the system
	* in about 30 seconds after entering the suspended state
	LOCAL oTimer As WaitableTimer
	oTimer = CREATEOBJECT("WaitableTimer")
	oTimer.SetDueTime(DATETIME() + 30)

	= SetSuspendState(nSuspendMode,;
		nForceCritical, nDisableWake)

	oTimer.NotifySystem
ENDIF
* end of main

DEFINE CLASS WaitableTimer As Session
PROTECTED hTimer
	hTimer=0

PROCEDURE Init()
	THIS.hTimer = CreateWaitableTimer(0, 1, NULL)

PROCEDURE Destroy
	THIS.ReleaseTimer

PROCEDURE ReleaseTimer
	IF THIS.hTimer <> 0
		= CloseHandle(THIS.hTimer)
		THIS.hTimer=0
	ENDIF

PROCEDURE SetDueTime(tTime As Datetime)
#DEFINE FILETIME_SIZE 8
	LOCAL cSystemtime, cLocalFiletime, cFiletime
	cSystemtime = THIS.DatetimeToSystemtime(m.tTime)
	STORE REPLICATE(CHR(0), FILETIME_SIZE) TO cLocalFiletime, cFiletime

	= SystemTimeToFileTime(cSystemtime, @cLocalFiletime)
	= LocalFileTimeToFileTime(cLocalFiletime, @cFiletime)
	= SetWaitableTimer(THIS.hTimer, @cFiletime, 0,0,0,1)

FUNCTION DatetimeToSystemtime(tTime As Datetime) As String
RETURN num2word(YEAR(m.tTime)) +;
		num2word(MONTH(m.tTime)) +;
		num2word(DOW(m.tTime)-1) +;
		num2word(DAY(m.tTime)) +;
		num2word(HOUR(m.tTime)) +;
		num2word(MINUTE(m.tTime)) +;
		num2word(SEC(m.tTime)) +;
		num2word(0)

PROCEDURE NotifySystem()
* emulates user input
	= SetThreadExecutionState(BITOR(ES_SYSTEM_REQUIRED, ES_DISPLAY_REQUIRED))
*	= SetThreadExecutionState(ES_DISPLAY_REQUIRED)
	DOEVENTS

ENDDEFINE

PROCEDURE declare
	DECLARE INTEGER GetLocalTime IN kernel32 STRING @lpSystemTime
	DECLARE INTEGER SetThreadExecutionState IN kernel32 INTEGER esFlags
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER IsPwrSuspendAllowed IN powrprof

	DECLARE INTEGER SetSuspendState IN powrprof;
		INTEGER Hibernate, INTEGER ForceCritical, INTEGER DisableWakeEvent

	DECLARE INTEGER SystemTimeToFileTime IN kernel32;
		STRING lpSYSTEMTIME,;
		STRING @FILETIME

	DECLARE INTEGER LocalFileTimeToFileTime IN kernel32;
		STRING LOCALFILETIME,;
		STRING @FILETIME

	DECLARE INTEGER CreateWaitableTimer IN kernel32;
		INTEGER lpTimerAttrib, INTEGER bManualReset, STRING lpTimerName

	DECLARE INTEGER SetWaitableTimer IN kernel32;
		INTEGER hTimer, STRING @pDueTime, LONG lPeriod,;
		INTEGER pfnCompletionRoutine, INTEGER lpArgToCompletionRoutine,;
		INTEGER fResume

	DECLARE INTEGER OpenWaitableTimer IN kernel32;
		LONG dwDesiredAccess, INTEGER bInheritHandle, STRING lpTimerName

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateWaitableTimer](../libraries/kernel32/CreateWaitableTimer.md)  
[GetLocalTime](../libraries/kernel32/GetLocalTime.md)  
[IsPwrSuspendAllowed](../libraries/powrprof/IsPwrSuspendAllowed.md)  
[LocalFileTimeToFileTime](../libraries/kernel32/LocalFileTimeToFileTime.md)  
[OpenWaitableTimer](../libraries/kernel32/OpenWaitableTimer.md)  
[SetSuspendState](../libraries/powrprof/SetSuspendState.md)  
[SetThreadExecutionState](../libraries/kernel32/SetThreadExecutionState.md)  
[SetWaitableTimer](../libraries/kernel32/SetWaitableTimer.md)  
[SystemTimeToFileTime](../libraries/kernel32/SystemTimeToFileTime.md)  

## Comment:
An application may use SetSuspendState to transition the system from the working state to the standby (sleep), or optionally, hibernate (S4) state. This function is similar to the SetSystemPowerState function. The calling process must have the SE_SHUTDOWN_NAME privilege.  
  
To prevent the user from putting the computer in standby mode, the application must deny the PBT_APMQUERYSUSPEND event.  
  
 
  
***  

