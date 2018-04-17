[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Terminating all running applications from a VFP program

## Before you begin:
Handle this code ***carefully***, because it terminates the running applications regardless of their state, unsaved data, I/O streams etc.  

See also:

* [Enumerating Processes -- WinNT](sample_162.md)  
* [Enumerating Processes -- Win9*/Me](sample_164.md)  

  
***  


## Code:
```foxpro  
#DEFINE GW_HWNDFIRST 0
#DEFINE GW_HWNDLAST 1
#DEFINE GW_HWNDNEXT 2
#DEFINE WM_QUIT 18
#DEFINE WM_SYSCOMMAND 0x0112
#DEFINE SC_CLOSE 0xf060
#DEFINE PROCESS_TERMINATE 1

DO declare

* Handle this code carefully, since it terminates all running applications
* regardless of their state, unsaved data, I/O streams etc.

LOCAL hWinActive, hWindow, cWinText, hWinCount, nWinIndex
hWinActive = GetActiveWindow()
hWindow = -1
hWinCount = 0

DO WHILE hWindow <> GetWindow(hWinActive, GW_HWNDLAST)
	IF hWindow = -1
		hWindow = GetWindow(hWinActive, GW_HWNDFIRST)
	ELSE
		hWindow = GetWindow(hWindow, GW_HWNDNEXT)
	ENDIF

	IF IsWindow(hWindow) <> 0 And IsWindowVisible(hWindow) <> 0;
		AND GetWindowTextLength(hWindow) > 0;
		AND GetParent(hWindow)=0

		cWinText = GetWinText(hWindow)

		* storing suitable window handles to an array
		IF hWindow <> hWinActive And Not "Program Manager" $ cWinText
			hWinCount = hWinCount + 1
			DIMEN arrWin[hWinCount, 2]
			arrWin[hWinCount, 1] = hWindow
			arrWin[hWinCount, 2] = cWinText
		ENDIF
	ENDIF
ENDDO

IF hWinCount = 0
	= MESSAGEBOX("No running applications found")
ELSE
	FOR nWinIndex=1 TO hWinCount
		? ">>", arrWin[nWinIndex, 2]

	* open the following line if you want the application to be terminated
	*	= CloseApp(arrWin[nWinIndex, 1])
	ENDFOR
ENDIF
* end of main

FUNCTION CloseApp(hWindow)
	LOCAL hWinProcId, hWinThreadId, hProcess

	* at first, trying the safest way -- sending the WM_QUIT
	* message to the application window

*	= PostMessage(hWindow, WM_QUIT, 0,0)
	* this works better then the command above
	= PostMessage(hWindow, WM_SYSCOMMAND, SC_CLOSE, 0)

	* a short breath for the VFP
	= INKEY(0.1)

	* return successfully if it is not a window handle anymore
	IF IsWindow(hWindow) = 0
		RETURN .T.
	ENDIF

	* if we are here, then the more harsh way has to be used
	* MSND: the TerminateProcess ...an abrupt and crashing halt,
	* preventing some of the usual cleanup from happening... sounds great, eh?

	* retrieving the process and thread Ids for the window
	= GetThreadProcessId(hWindow, @hWinProcId, @hWinThreadId)

	* obtaining the handle to the process enabled for its termination
	hProcess = OpenProcess(PROCESS_TERMINATE, 0, hWinProcId)

	IF hProcess <> 0
		= TerminateProcess(hProcess, 0)
		= CloseHandle(hProcess)
	ENDIF
	* check the OpenThread and TerminateThread as another option
RETURN

FUNCTION GetWinText(hWindow)
	LOCAL lnBufsize, lcBuffer
	lnBufsize = 1024
	lcBuffer = Repli(Chr(0), lnBufsize)
	lnBufsize = GetWindowText(hWindow, @lcBuffer, lnBufsize)
RETURN Iif(lnBufsize=0, "", Left(lcBuffer,lnBufsize))

PROCEDURE GetThreadProcessId(hWindow, hProcId, hThreadId)
	STORE 0 TO hProcId, hThreadId
	hThreadId = GetWindowThreadProcessId(hWindow, @hProcId)
RETURN

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindow IN user32 INTEGER hWindow, INTEGER wFlag
	DECLARE INTEGER IsWindow IN user32 INTEGER hWindow
	DECLARE INTEGER IsWindowVisible IN user32 INTEGER hWindow
	DECLARE INTEGER GetWindowTextLength IN user32 INTEGER hWindow
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetParent IN user32 INTEGER hWindow

	DECLARE SHORT PostMessage IN user32;
		INTEGER hWindow, INTEGER Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hWindow, STRING @lpString, INTEGER cch

	DECLARE INTEGER GetWindowThreadProcessId IN user32;
		INTEGER hWindow, INTEGER @lpdwProcId

	DECLARE INTEGER OpenProcess IN kernel32;
		INTEGER dwDesiredAccess, INTEGER bInheritHandle,;
		INTEGER dwProcId

	DECLARE INTEGER TerminateProcess IN kernel32;
		INTEGER hProcess, INTEGER uExitCode  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetParent](../libraries/user32/GetParent.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[GetWindowTextLength](../libraries/user32/GetWindowTextLength.md)  
[GetWindowThreadProcessId](../libraries/user32/GetWindowThreadProcessId.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[IsWindowVisible](../libraries/user32/IsWindowVisible.md)  
[OpenProcess](../libraries/kernel32/OpenProcess.md)  
[PostMessage](../libraries/user32/PostMessage.md)  
[TerminateProcess](../libraries/kernel32/TerminateProcess.md)  

## Comment:
The GetWindow function is used to obtain handles to all windows siblings to the main VFP window *(having the equal rank)*, excluding the Program Manager window.   
  
Ths PostMessage function called with WM_SYSCOMMAND and SC_CLOSE works more effectively.  
  
That is for sure, the both ways can be of some sort destructive for the application. Especially the TerminateProcess is. Check description for [this function](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686714(v=vs.85).aspx) on the MSDN.  
  
***  

