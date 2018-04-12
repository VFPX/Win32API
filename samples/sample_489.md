[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to block the PrintScreen key

## Short description:
The PrintScreen key sends to the Clipboard either whole screen or just the active window (if pressed together with ALT key). To prevent windows of your application to be captured and printed by users through pressing this key, use RegisterHotKey API function. Still this solution does not provide absolute protection. A determined user may use third-party screen capturing utility that is not associated with the PrintScreen key and the Clipboard.   
***  


## Before you begin:
The PrintScreen key sends to the Clipboard either whole screen or just the active window (if pressed together with ALT key). To prevent windows of your application to be captured and printed by users through pressing this key, use RegisterHotKey API function.  

Still this solution does not provide absolute protection, if there is such a thing :). A determined user may use third-party screen capturing utility that is not associated with the PrintScreen key and the Clipboard.   

See also:

* [How to block the ALT+TAB shortcut](sample_432.md)  
* [How to disable the Windows Clipboard (requires VFP9)](sample_488.md)  
* [Preventing users from accessing the Windows Desktop and from switching to other applications](sample_492.md)  
* [Capturing keyboard activity of another application using the Raw Input API](sample_572.md)  

  
***  


## Code:
```foxpro  
LOCAL oForm
oForm = CREATEOBJECT("TForm")
oForm.Show(1)
* end of main

DEFINE CLASS Tform As Form
#DEFINE MOD_ALT 1
#DEFINE MOD_CONTROL 2
#DEFINE MOD_SHIFT 4
#DEFINE MOD_WIN 8

#DEFINE GWL_WNDPROC -4
#DEFINE WM_HOTKEY 0x312
#DEFINE VK_PRINTSCREEN 0x2c
#DEFINE ID_PRINTSCREEN 0x500  && range from 0x0000 through 0xBFFF

PROTECTED hWindow, hOrigProc
	hWindow=0
	hOrigProc=0
	Caption="Blocking PrintScreen key"
	Width=300
	Height=150
	AutoCenter=.T.

	ADD OBJECT chBlock As CheckBox WITH;
	Left=90, Top=50, BackStyle=0, AutoSize=.T.,;
	Caption="Blocking PrintScreen key"

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	THIS.ReleasePrintScreen

PROCEDURE chBlock.Click
	ThisForm.ReleasePrintScreen
	IF THIS.Value = 1
		_cliptext=""  && just in case :)
		ThisForm.HookPrintScreen
	ENDIF
	
PROCEDURE HookPrintScreen
* after this procedure the FoxPro form is notified
* each time the PrintScreen key is pressed alone
* or in combination with other keys

	THIS.hWindow = GetFocus()

	* store the address of the original window procedure
	* to be used in OnPrintScreen method
	THIS.hOrigProc = GetWindowLong(THIS.hWindow, GWL_WNDPROC)

	* link WM_HOTKEY window message to a method
	IF VERSION(5) >= 900
		= BINDEVENT(THIS.hWindow, WM_HOTKEY,;
			THIS, "OnPrintScreen")
	ENDIF

	* register PrintScreen key with all possible
	* combinations of modifiers: CONTROL, ALT, SHIFT, WIN
	* see MOD_ constants above
	LOCAL nIndex
	FOR nIndex=0 TO 15
		= RegisterHotKey(THIS.hWindow, ID_PRINTSCREEN+nIndex,;
			nIndex, VK_PRINTSCREEN)
	NEXT

PROCEDURE ReleasePrintScreen
	= UNBINDEVENTS(THIS)
	
	* unregister hot keys
	IF THIS.hWindow <> 0
		LOCAL nIndex
		FOR nIndex=0 TO 15
			= UnregisterHotKey(THIS.hWindow,;
				ID_PRINTSCREEN+nIndex)
		NEXT
	ENDIF

PROTECTED PROCEDURE OnPrintScreen(hWindow as Integer,;
	nMsgID as Integer, wParam as Integer, lParam as Integer)
* requires VFP9, otherwise ignored
* note that input parameters are predefined and should not be changed
* see WindowProc function for details

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID=WM_HOTKEY
	* just a visual indication; place your code here
		ACTIVATE SCREEN
		? "KeyID=" + TRANSFORM(wParam) + ", " +;
			 "VirtKey=" + TRANSFORM(BITRSHIFT(BITAND(;
			 	lParam,0xffff0000),16),"@0") +;
			 ", KeyMod=" + TRANSFORM(BITAND(lParam,0xffff))
		
	OTHERWISE
	* pass control to the original window procedure
		nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
			m.nMsgID, m.wParam, m.lParam)
	ENDCASE
RETURN nReturn

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER RegisterHotKey IN user32;
		INTEGER hWnd, INTEGER id,;
		INTEGER fsModifiers, INTEGER vk

	DECLARE INTEGER UnregisterHotKey IN user32;
		INTEGER hWnd, INTEGER id

	DECLARE INTEGER CallWindowProc IN user32;
		INTEGER lpPrevWndFunc, INTEGER hWindow, LONG Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWnd, INTEGER nIndex

ENDDEFINE  
```  
***  


## Listed functions:
[CallWindowProc](../libraries/user32/CallWindowProc.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[RegisterHotKey](../libraries/user32/RegisterHotKey.md)  
[UnregisterHotKey](../libraries/user32/UnregisterHotKey.md)  
[WindowProc](../libraries/kernel32/WindowProc.md)  

## Comment:
Under VFP8 the code works in a bit limited way. It does disable the PrintScreen key, but the OnPrintScreen method of the form can not be binded to the WM_HOTKEY notification.  
  
* * *  
Read article [Disabling Print Screen, Calling Derived Destructors, and More](http://www.dotnetspark.com/links/2457-c-work-disabling-print-screen-calling-derived.aspx) by Paul DiLascia published in Nov.2005 MSDN Magazine.  
  
```txt
#DEFINE IDHOT_SNAPDESKTOP -2  
#DEFINE IDHOT_SNAPWINDOW -1
```
***  

