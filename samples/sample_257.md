[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Disabling drawing in the VFP form

## Code:
```foxpro  
DO decl

PUBLIC objForm
objForm = CreateObject("TForm")
objForm.Visible = .T.

DEFINE CLASS TForm As FORM
	Caption = "Disabling drawing in the form"
	Width=400
	Height=250
	AutoCenter = .T.

	ADD OBJECT cmdLock As CommandButton WITH;
	Left=10, Top=15, Width=80, Height=24,;
	Caption="Lock"

	ADD OBJECT cmdMsg As CommandButton WITH;
	Left=92, Top=15, Width=80, Height=24,;
	Caption="Test"

PROCEDURE  LockForm
	LOCAL hWindow

	* obtaining a window handle for the form
	hWindow = GetFocus()

	* disabling the form moving
	* since when the form is moved the VFP unlock
	* its window automatically
	ThisForm.Movable = .F.

	* locking the window
	= LockWindowUpdate(hWindow)

PROCEDURE  cmdLock.Click
	ThisForm.LockForm

PROCEDURE  cmdMsg.Click
	= MessageB ("Test Message")
ENDDEFINE

PROCEDURE  decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER LockWindowUpdate IN user32 INTEGER hWndLock  
```  
***  


## Listed functions:
[GetFocus](../libraries/user32/GetFocus.md)  
[LockWindowUpdate](../libraries/user32/LockWindowUpdate.md)  

## Comment:
When the drawing is disabled, whatever you do with controls on this form, you still have its image unchanged. You can still close this form by clicking on the Close button, which image will not change during the click.  
  
This behaviour could possibly be useful for windowing controls (controls with window handles, as OLE controls) to disable their visual update for the time of performing some operations on them, like adding rows etc. Though this is only my assumption, needs to be tested.  
  
And one more interesting thing to test: trying to draw within a locked window.  
  
***  

