[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to drag a Form not using its Titlebar or Caption

## Before you begin:
Drag the form with a mouse holding at any point in the client area of the form, not just the title of the form. The form can be dragged using its client area even if the Movable property set to False.  

See also:

* [Round FoxPro form](sample_143.md)  
* [Tracking mouse movement to detect when to start dragging](sample_281.md)  
* [Dragging files from Explorer window and dropping them on FoxPro control](sample_323.md)  
  
***  


## Code:
```foxpro  
LOCAL oForm
oForm = CREATEOBJECT("Tform")
oForm.Visible=.T.
READ EVENTS

DEFINE CLASS Tform As Form
	Caption="Left-click inside the form and drag"
	Autocenter=.T.

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	CLEAR EVENTS

PROCEDURE MouseDown
LPARAMETERS nButton, nShift, nXCoord, nYCoord
#DEFINE WM_NULL 0
#DEFINE WM_SYSCOMMAND 0x0112
#DEFINE WM_LBUTTONUP 0x0202
#DEFINE MOUSE_MOVE 0xf012

	IF nButton = 1
		LOCAL hWindow
		hWindow = THIS.HWnd && GetFocus()

		= ReleaseCapture()

		= SendMessage(hWindow, WM_SYSCOMMAND,;
			MOUSE_MOVE, WM_NULL)

		= SendMessage(hWindow, WM_LBUTTONUP, 0, 0)
	ENDIF

PROCEDURE declare
	DECLARE INTEGER ReleaseCapture IN user32
	DECLARE INTEGER GetFocus IN user32

	DECLARE INTEGER SendMessage IN user32;
		INTEGER hWindow, INTEGER Msg,;
		INTEGER wParam, INTEGER lParam

ENDDEFINE  
```  
***  


## Listed functions:
[GetFocus](../libraries/user32/GetFocus.md)  
[ReleaseCapture](../libraries/user32/ReleaseCapture.md)  
[SendMessage](../libraries/user32/SendMessage.md)  

## Comment:
 
  
This behaviour can also be implemented by intercepting and processing [WM_NCHITTEST](https://msdn.microsoft.com/en-us/library/ms645618%28v=VS.85%29.aspx?f=255&MSPPError=-2147217396) windows messages sent to the form. If the cursor is inside the client area, return HTCAPTION (2) instead of HTCLIENT (1).   
  
Note that for top-level forms (ShowWindow=2), the first parameter in WM_NCHITTEST handling BINDEVENT call should not be ThisForm.HWnd, but the window handle of the inner window.  
  
***  

