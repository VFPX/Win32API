[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to prevent users from accessing the Windows Desktop and from switching to other applications

## Short description:
Sometimes you may need a computer with a single application running on it, and with all other applications and resources hidden from users. An example, Indigo Book Store customers can only search books when using public computers in the store.
  
***  


## Before you begin:
Sometimes you may need a computer with a single application running on it, and with all other applications and resources hidden from users. An example, Indigo Book Store customers can only search books when using public computers in the store.  

The following items should be concealed:  
* Windows Taskbar and Start Menu  
* Task Manager  
* CTRL+ALT+DEL  
* ALT+TAB  
* CTRL+ESC  
* both Windows keys  
* right click on the Windows Desktop  
* all icons on the desktop  
* ...  

An article [Lock Windows Desktop](https://www.codeproject.com/kb/winsdk/antoniowinlock.aspx?msg=2415660) written by *Antonio Feijao* describes several techniques of restricting users from accessing the desktop and running other applications. 

The one that switches to a new desktop seems to be efficient, easy to understand and can be accomplished in just FoxPro code with no external libraries other than WinAPI.   

Use the following code to test the AppLauncher class:  
```foxpro
LOCAL obj, ex As Exception  
TRY  
	obj = CREATEOBJECT("AppLauncher")  
	WITH obj  
		.StartProcessInNewDesktop(;  
		"C:\Program Files\Internet Explorer\iexplore.exe",;  
		 "https://www.levelextreme.com")  

		IF .errorno <> 0  
			? .errorno, .message  
		ENDIF  
	ENDWITH  

CATCH TO ex  
	? ex.ErrorNo, ex.Message  
ENDTRY
```

An Internet Explorer window will appear inside a new desktop. ALT+TAB, CTRL+ESC and CTRL+ALT+DEL keys are disabled. The Windows Taskbar and Start Menu are not visible. Close IE window to get back to the default Windows Desktop.  

Requires Win XP/NT/2K, VFP8.  

See also:

* [How to block the ALT+TAB and ALT+ESC](sample_432.md)  
* [How to block the PrintScreen key](sample_489.md)  
* [Using a Semaphore object to prevent VFP application from running more than one instance](sample_147.md)  
* [How to start the screen saver and how to find whether the screen saver is active](sample_196.md)  
* [How to disable the Windows Clipboard (requires VFP9)](sample_488.md)  
* [Capturing keyboard activity of another application using the Raw Input API](sample_572.md)  

  
***  


## Code:
```foxpro  
#DEFINE START_INFO_SIZE  68
#DEFINE DESKTOP_SWITCHDESKTOP 0x0100
#DEFINE GENERIC_ALL 0x10000000
#DEFINE INFINITE  0xFFFFFFFF

DEFINE CLASS AppLauncher As Session
PROTECTED hProcess, hOrgThread, hOrgInput, hNewDesktop, newdesktop
	hProcess=0
	hOrgThread=0
	hOrgInput=0
	hNewDesktop=0
	newdesktop=""
	errorno=0
	message=""

PROCEDURE Init
	THIS.declare
	
PROCEDURE StartProcessInNewDesktop(cApplication As String,;
	cCommandLine As String, cStartIn As String, nTimeout As Number)
* INPUT PARAMETERS
* cApplication -- the module to execute
* cCommandLine -- the command line to execute
* cStartIn -- current directory for the process
* nTimeout -- time-out interval, in milliseconds

	THIS.ClearErrorState

	IF VARTYPE(m.cStartIn) <> "C" OR EMPTY(cStartIn)
		cStartIn = SYS(5) + SYS(2003)
	ENDIF

	IF VARTYPE(nTimeout) <> "N" OR nTimeout <= 0
		nTimeout=INFINITE
	ENDIF

	IF NOT THIS.SwitchToNewDesktop()
		RETURN
	ENDIF

	LOCAL ex As Exception
	TRY
		LOCAL oDesktop As PChar, cProcInfo, cStartInfo, nResult
		THIS.hProcess=0
		oDesktop = CREATEOBJECT("PChar", THIS.newdesktop)
		cProcInfo = REPLICATE(CHR(0),16)
		cStartInfo = PADR(num2dword(START_INFO_SIZE) +;
			num2dword(0) + num2dword(oDesktop.GetAddr()),;
			START_INFO_SIZE, Chr(0))

		IF NOT EMPTY(m.cCommandLine)
			cCommandLine = " " + ALLTRIM(m.cCommandLine)
		ENDIF

		nResult = CreateProcess(cApplication, cCommandLine,;
			0,0,0,0,0, m.cStartIn, @cStartInfo, @cProcInfo)

		IF nResult = 0
			THIS.errorno = GetLastError()
			THIS.message = "CreateProcess function failed."
		ELSE
			THIS.hProcess = buf2dword(SUBSTR(m.cProcInfo, 1,4))
			= WaitForSingleObject(THIS.hProcess, m.nTimeout)
			DOEVENTS
			= TerminateProcess(THIS.hProcess, 0)
			= CloseHandle(THIS.hProcess)
		ENDIF
	CATCH TO ex
		THIS.errorno = ex.ErrorNo
		THIS.message = ex.Message
	ENDTRY
	
	THIS.hProcess=0
	THIS.RestoreOrgDesktop

PROTECTED PROCEDURE SwitchToNewDesktop
* creates new desktop and switches to it
	LOCAL nResult
	THIS.newdesktop = "desktop_" + SUBSTR(SYS(2015), 3)
	THIS.hOrgThread = GetThreadDesktop(GetCurrentThreadId())
	THIS.hOrgInput = OpenInputDesktop(0,0, DESKTOP_SWITCHDESKTOP);

	THIS.hNewDesktop = CreateDesktop(THIS.newdesktop,;
		0,0,0, GENERIC_ALL, 0)
	= SetThreadDesktop(THIS.hNewDesktop)
	nResult = SwitchDesktop(THIS.hNewDesktop)

	IF nResult = 0
		THIS.errorno = GetLastError()
		THIS.message = "SwitchDesktop function failed."
	ENDIF
RETURN (nResult <> 0)

PROTECTED PROCEDURE RestoreOrgDesktop
* restores original desktop
	IF THIS.hOrgInput <> 0
		= CloseDesktop(THIS.hNewDesktop)
		= SwitchDesktop(THIS.hOrgInput)
		= SetThreadDesktop(THIS.hOrgThread)
		= CloseDesktop(THIS.hOrgInput)
		THIS.hOrgInput=0
	ENDIF

PROTECTED PROCEDURE ClearErrorState
	THIS.errorno = 0
	THIS.message = ""

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetThreadDesktop IN user32 LONG dwThreadId
	DECLARE INTEGER SetThreadDesktop IN user32 INTEGER hDesktop
	DECLARE INTEGER SwitchDesktop IN user32 INTEGER hDesktop
	DECLARE INTEGER CloseDesktop IN user32 INTEGER hDesktop
	DECLARE INTEGER GetCurrentThreadId IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER TerminateProcess IN kernel32;
		INTEGER hProcess, INTEGER uExitCode

	DECLARE INTEGER CreateProcess IN kernel32;
		STRING lpApplicationName, STRING lpCommandLine,;
		INTEGER lpProcessAttr, INTEGER lpThreadAttr,;
		INTEGER bInheritHandles, INTEGER dwCreationFlags,;
		INTEGER lpEnvironment, STRING lpCurrentDirectory,;
		STRING @lpStartupInfo, STRING @lpProcessInformation

	DECLARE INTEGER OpenInputDesktop IN user32;
		LONG dwFlags, INTEGER fInherit, INTEGER dwDesiredAccess

	DECLARE INTEGER CreateDesktop IN user32;
		STRING lpszDesktop, INTEGER lpszDevice, INTEGER pDevmode,;
		LONG dwFlags, INTEGER dwDesiredAccess, INTEGER lpsa

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds

ENDDEFINE

********************* library functions **********************
FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

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
```  
***  


## Listed functions:
[CloseDesktop](../libraries/user32/CloseDesktop.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateDesktop](../libraries/user32/CreateDesktop.md)  
[CreateProcess](../libraries/kernel32/CreateProcess.md)  
[GetCurrentThreadId](../libraries/kernel32/GetCurrentThreadId.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetThreadDesktop](../libraries/user32/GetThreadDesktop.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[OpenInputDesktop](../libraries/user32/OpenInputDesktop.md)  
[SetThreadDesktop](../libraries/user32/SetThreadDesktop.md)  
[SwitchDesktop](../libraries/user32/SwitchDesktop.md)  
[TerminateProcess](../libraries/kernel32/TerminateProcess.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

## Comment:
To implement this technique, create a launcher -- a small VFP application that starts the main executable by calling the CreateProcess API function.  
  
Name of the new desktop is assigned to *lpDesktop* member of the STARTUPINFO structure that used with the CreateProcess&nbsp;call. As the result, the main application runs inside a separate desktop, which is absolutely empty.  
  
The WaitForSingleObject function returns, when the main application is closed by user. Also this function returns when the time-out interval elapses, unless *dwMilliseconds* is INFINITE.  
  
* * *  
A window station is a securable object that is associated with a process, and contains a clipboard, an atom table, and one or more desktop objects.   
  
The interactive window station, *WinSta0*, is the only window station that can display a user interface or receive user input. It is assigned to the logon session of the interactive user, and contains the keyboard, mouse, and display device. All other window stations are noninteractive, which means they cannot display a user interface or receive user input.  
  
A desktop is a securable object contained within a window station. A desktop has a logical display surface and contains user interface objects such as windows, menus, and hooks.  
  
* * *  
C++ code shows how to enumerate window stations and window desktops. The enumerations are based on callback functions and for that reason can not be programmed directly in VFP code.  

![](../images/winstations.png)  

***  

