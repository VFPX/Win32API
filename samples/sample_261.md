[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Scanning the hierarchy of child windows down from the main VFP window

## Before you begin:
This code returns some interesting information about windows residing inside the main VFP window.  
  
***  


## Code:
```foxpro  
DO declare

* resulting cursor stores handle, parent handle,
* caption, rectangle, and style for enumerated windows
CREATE CURSOR csResult (winhandle N(12), parentwin N(12), winlevel N(5),;
	winclass C(30), wintitle C(50), wrleft N(12), wrtop N(12),;
	wrright N(12), wrbottom N(12), winwidth N(5), winheight N(5),;
	winstyle N(12), winexstyle N(12))

LOCAL hAppWindow, loWindow

hAppWindow = GetActiveWindow()  && main VFP window
*hAppWindow = _screen.HWnd
*hAppWindow = FindWindow("Shell_TrayWnd", Null)
*hAppWindow = FindWindow("AdobeAcrobat", Null)
*hAppWindow = FindWindow(Null, "Calculator")

IF hAppWindow = 0 OR IsWindow(hAppWindow)=0
	= MESSAGEBOX("Invalid Window Handle")
	RETURN
ENDIF

loWindow = CreateObject("Twindow", hAppWindow, 0,0)

SELECT * FROM csResult ORDER BY winlevel, parentwin
* end of main

DEFINE CLASS Twindow As Custom
* this class restores window parameters using recursion
* for all levels of child windows starting from a given window
#DEFINE GW_HWNDNEXT   2
#DEFINE GW_CHILD      5

PROTECTED WinCaption, WinClass, hWindow, hParent, lvl

PROCEDURE Init(lnHandle, lnParent, lnLevel)
	IF lnHandle = 0
		RETURN .F.
	ENDIF

	THIS.lvl = lnLevel
	THIS.hWindow = lnHandle
	THIS.hParent = lnParent
	THIS.WinCaption = GetWinText(lnHandle)
	THIS.WinClass = GetWinCLass(lnHandle)
	THIS.SaveWinInfo

	LOCAL hChild, oChild, hNext, oNext
	hChild = GetWindow(THIS.hWindow, GW_CHILD)
	oChild = CreateObject("Twindow", hChild, THIS.hWindow, THIS.lvl+1)

	IF lnParent <> 0
		hNext = GetWindow(THIS.hWindow, GW_HWNDNEXT)
		oNext = CreateObject("Twindow", hNext, THIS.hParent, THIS.lvl)
	ENDIF

PROCEDURE SaveWinInfo
	INSERT INTO csResult (winhandle, parentwin, winlevel, wintitle, winclass);
	VALUES (THIS.hWindow, THIS.hParent, THIS.lvl, THIS.WinCaption, THIS.WinClass)
	
*| typedef struct tagWINDOWINFO {
*|     DWORD cbSize;            0:4
*|     RECT  rcWindow;          4:16
*|     RECT  rcClient;         20:16
*|     DWORD dwStyle;          36:4
*|     DWORD dwExStyle;        40:4
*|     DWORD dwWindowStatus;   44:4
*|     UINT  cxWindowBorders;  48:4
*|     UINT  cyWindowBorders;  52:4
*|     ATOM  atomWindowType;   56:2
*|     WORD  wCreatorVersion;  58:2
*| } WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO; total=60 bytes
#DEFINE WINDOWINFO_SIZE  60

	LOCAL lcBuffer, lnResult
	lcBuffer = Chr(WINDOWINFO_SIZE) +;
		Repli(Chr(0), WINDOWINFO_SIZE-1)

	lnResult = GetWindowInfo(THIS.hWindow, @lcBuffer)
	
	UPDATE csResult SET;
		wrleft = buf2dword(SUBS(lcBuffer, 5,4)),;
		wrtop  = buf2dword(SUBS(lcBuffer, 9,4)),;
		wrright = buf2dword(SUBS(lcBuffer, 13,4)),;
		wrbottom = buf2dword(SUBS(lcBuffer, 17,4)),;
		winstyle = buf2dword(SUBS(lcBuffer, 37,4)),;
		winexstyle = buf2dword(SUBS(lcBuffer, 41,4)),;
		winwidth  = wrright-wrleft+1,;
		winheight = wrbottom-wrtop+1;
	WHERE csResult.winhandle = THIS.hWindow
ENDDEFINE

FUNCTION GetWinText(hWindow)
* returns window title bar text -- Win9*/Me/XP/2000
	LOCAL lcBuffer, lnResult
	lcBuffer = Space(250)
	lnResult = GetWindowText(hWindow, @lcBuffer, Len(lcBuffer))
RETURN Left(lcBuffer, lnResult)

FUNCTION GetWinClass(hWindow)
* returns window class
	LOCAL lcBuffer, lnResult
	lcBuffer = Space(250)
	lnResult = RealGetWindowClass(hWindow, @lcBuffer, Len(lcBuffer))
RETURN Left(lcBuffer, lnResult)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer,1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer,2,1)),  8)+;
	BitLShift(Asc(SUBSTR(lcBuffer,3,1)), 16)+;
	BitLShift(Asc(SUBSTR(lcBuffer,4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindow IN user32 INTEGER hwnd, INTEGER wFlag
	DECLARE INTEGER GetWindowInfo IN user32 INTEGER hwnd, STRING @pwi
	DECLARE INTEGER IsWindow IN user32 INTEGER hWindow

	DECLARE INTEGER RealGetWindowClass IN user32;
		INTEGER hWindow, STRING @pszType, INTEGER cchType

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch

	DECLARE INTEGER InternalGetWindowText IN user32;
		INTEGER hWnd, STRING @lpString, INTEGER nMaxCount

	DECLARE INTEGER FindWindow IN user32;
		STRING lpClassName, STRING lpWindowName  
```  
***  


## Listed functions:
[FindWindow](../libraries/user32/FindWindow.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[GetWindowInfo](../libraries/user32/GetWindowInfo.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[InternalGetWindowText](../libraries/user32/InternalGetWindowText.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[RealGetWindowClass](../libraries/user32/RealGetWindowClass.md)  

## Comment:
Starting from the main VFP window this code recursively scans all levels of child windows.  
  
Test this code having various combinations of  VFP forms and tool windows running. Note a difference when VFP forms contain any ActiveX controls. ActiveX controls are windows, that is not true for VFP native controls.  
  
By the way, this is how a window handle to the Command window can be obtained. Evidently more can be done with sending various messages to inner windows and reaching their parameters directly through Win32 functions.  
  
Try to start scanning not from the main VFP window, but from the Windows Taskbar:  
  
```dos
hAppWindow = FindWindow("Shell_TrayWnd", Null)
```
  
  
Where *Shell_TrayWnd* is Window class name for the Taskbar.  
  
***  

