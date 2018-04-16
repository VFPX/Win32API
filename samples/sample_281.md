[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Tracking mouse movement to detect when to start dragging

## Before you begin:
See also:

* [How to drag a Form not using its Titlebar or Caption](sample_195.md)  
* [Dragging files from Explorer window and dropping them on FoxPro control](sample_323.md)  

  
***  


## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("TForm")
objForm.Visible = .T.

DEFINE CLASS TForm As Form
	Width=400
	Height=200
	Autocenter=.T.

PROCEDURE  Load
	THIS.decl
	
PROCEDURE  MouseDown
LPARAMETERS nButton, nShift, nXCoord, nYCoord

	* testing the mouse key state
	IF nButton <> 1
		RETURN
	ENDIF
	
	LOCAL lcCursorPos, hWindow
	
	* window handle for this form
	hWindow = GetFocus()

	* reading cursor position
	lcCursorPos = Repli(Chr(0), 8)
	= GetCursorPos(lcCursorPos)
	
	* Attention: at the next line the execution is stopped until
	* the mouse button released or the cursor moved out
	* the drag-free rectangle centered on the current cursor position
	* with sides defined by the system

	* the width and height of this rectangle returned by the GetSystemMetrics
	* function called with the correspondent SM_CXDRAG or SM_CYDRAG parameters

	IF DragDetect(hWindow, @lcCursorPos) <> 0
	* user moved the mouse outside of the drag rectangle
	* while holding down the left button
		ACTI SCREEN
		? "Drag detected"
	ELSE
		ACTI SCREEN
		? "Mouse key released without dragging"
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetCursorPos IN user32 STRING @lpPoint

	DECLARE INTEGER DragDetect IN user32;
		INTEGER hwnd, STRING @pt
ENDDEFINE  
```  
***  


## Listed functions:
[DragDetect](../libraries/user32/DragDetect.md)  
[GetCursorPos](../libraries/user32/GetCursorPos.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  

## Comment:
The DragDetect function captures the mouse and tracks its movement until the user releases the left mouse button, presses the ESC key, or moves the mouse outside the drag rectangle around the specified point.  
  
To obtain the width and height for this rectangle call the GetSystemMetrics function with the SM_CXDRAG and SM_CYDRAG values as a parameter.  
```txt
#DEFINE SM_CXDRAG  68  
#DEFINE SM_CYDRAG  69
```
  
***  

