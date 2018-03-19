[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to activate Windows Calculator

## Before you begin:
This code sample explains how to programmatically open an instance of Windows Calculator.  

![](../images/wincalculator.png)  
  
***  


## Code:
```foxpro  
PUBLIC frm
frm = CreateObject("Tform")
frm.Visible = .T.

DEFINE CLASS Tform As Form
#DEFINE WM_QUIT 18
#DEFINE SW_SHOWNORMAL 1
	Width=400
	Height=200
	Caption="Activate Windows Calculator"
	
	ADD OBJECT cmdShow As CommandButton WITH;
		Caption="Show Calc", Height=24, Width=100,;
		Top=5, Left=10

	ADD OBJECT cmdHide As CommandButton WITH;
		Caption="Hide Calc", Height=24, Width=100,;
		Top=5, Left=112

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	THIS._hide

PROCEDURE cmdShow.Click
	ThisForm._show

PROCEDURE cmdHide.Click
	ThisForm._hide

PROCEDURE _show
	LOCAL hWindow
	hWindow = FindWindow(Null, "Calculator")

	IF IsWindow(hWindow)=0
		= WinExec("calc.exe", SW_SHOWNORMAL)
		DOEVENTS
		hWindow = FindWindow(Null, "Calculator")
*		= SetParent(hWindow, _vfp.HWnd)
	ENDIF

	IF IsWindow(hWindow) <> 0
		= SetForegroundWindow(hWindow)
*		= SetParent(hWindow, _vfp.HWnd)
		THIS.PasteNumber(PI())
	ENDIF

PROCEDURE _hide
	LOCAL hWindow
	hWindow = FindWindow(Null, "Calculator")
	IF IsWindow(hWindow) <> 0
		= PostMessage(hWindow, WM_QUIT, 0,0)
	ENDIF

PROCEDURE PasteNumber(cNumber)
#DEFINE WM_KEYDOWN 0x0100
#DEFINE WM_KEYUP 0x0101
#DEFINE VK_CONTROL 0x11
#DEFINE KEYEVENTF_EXTENDEDKEY 1
#DEFINE KEYEVENTF_KEYUP 2

	LOCAL hWindow
	hWindow = FindWindow(Null, "Calculator")

	IF hWindow <> 0
		* stores the number in the Clipboard
		STORE TRANSFORM(m.cNumber) TO _cliptext
		
		* makes Calculator the foreground window
		= SetForegroundWindow(hWindow)

		* simulates CTRL+V keystroke
		= keybd_event(VK_CONTROL, 0, 0, 0)
		= keybd_event(VkKeyScan(ASC("V")), 0, 0, 0)
		= keybd_event(VkKeyScan(ASC("V")), 0, KEYEVENTF_KEYUP, 0)
		= keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0)
	ENDIF

PROTECTED PROCEDURE declare
	DECLARE INTEGER SetForegroundWindow IN user32;
		INTEGER hWindow

	DECLARE INTEGER IsWindow IN user32 INTEGER hWindow

	DECLARE INTEGER FindWindow IN user32;
		STRING lpClassName, STRING lpWindowName

	DECLARE INTEGER WinExec IN kernel32;
		STRING lpCmdLine, INTEGER nCmdShow

	DECLARE INTEGER PostMessage IN user32;
		INTEGER hWindow, INTEGER Msg,;
		STRING @wParam, INTEGER lParam

	DECLARE keybd_event IN user32;
		SHORT bVk, SHORT bScan, INTEGER dwFlags,;
		INTEGER dwExtraInfo

	DECLARE SHORT VkKeyScan IN user32 INTEGER ch

	DECLARE INTEGER SetParent IN user32;
		INTEGER hWndChild,;
		INTEGER hWndNewParent

ENDDEFINE  
```  
***  


## Listed functions:
[FindWindow](../libraries/user32/FindWindow.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[PostMessage](../libraries/user32/PostMessage.md)  
[SetForegroundWindow](../libraries/user32/SetForegroundWindow.md)  
[SetParent](../libraries/user32/SetParent.md)  
[VkKeyScan](../libraries/user32/VkKeyScan.md)  
[WinExec](../libraries/kernel32/WinExec.md)  
[keybd_event](../libraries/user32/keybd_event.md)  

## Comment:
Btw, you can use the SetParent function to make the main VFP window (_screen.hWnd or _vfp.hWnd) the parent window for the Calculator. In that case the calculator window becomes confined in the main VFP window.  
  
***  

