[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Running a regular FoxPro form while main VFP window is minimized

## Before you begin:
This code changes a parent window for the given form to the Windows Desktop.  
  
***  


## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("Tform")
objForm.Visible = .T.

DEFINE CLASS Tform As Form
AutoCenter=.T.
PROTECTED formstatus

PROCEDURE  Init
	THIS.formstatus = 0

PROCEDURE  Activate
	IF THIS.formstatus = 1
		RETURN
	ENDIF

	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER SetParent IN user32;
		INTEGER hWndChild, INTEGER hWndNewParent

	LOCAL hForm, hDesktop
	hDesktop = GetDesktopWindow()
	hForm = GetFocus()

	* if successfully changing the parent window for this form
	* then minimizing the main VFP window

	IF SetParent (hForm, hDesktop) <> 0
		THIS.formstatus = 1
		_SCREEN.WindowState = 1
	ENDIF
	
ENDDEFINE  
```  
***  


## Listed functions:
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[SetParent](../libraries/user32/SetParent.md)  

## Comment:
It makes the form less dependent on the main VFP window. Its icon even appears on the Windows toolbar.   
  
As I can see some more adjustments should be done to the form through the SetWindowLong function, since it is not possible to put it on top when it is hidden by other windows.  
  
***  

