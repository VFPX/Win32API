[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using IsChild() for testing ThisForm.ShowWindow property

## Before you begin:
Push the button to display the Parent-Child state for the form.  
  
***  


## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("Tform")
objForm.Visible = .T.

DEFINE CLASS Tform As FORM
Autocenter = .T.
*ShowWindow = 0  && a child form placed in the main VFP window
*ShowWindow = 1  && a child form of the active top-level form
ShowWindow = 2  && a top-level form in which child forms can be placed

ADD OBJECT cmd As CommandButton WITH;
LEFT=10, TOP=10, WIDTH=80, HEIGHT=24, CAPTION="Diag"

PROCEDURE  Load
	THIS.decl

PROCEDURE  cmd.Click
	LOCAL lcMsg
	IF IsChild (GetActiveWindow(), GetFocus()) = 1
		lcMsg = "This form is a child window to the main VFP window"
	ELSE
		lcMsg = "This form is NOT a child window to the main VFP window"
	ENDIF
	= MessageB ("ThisForm.ShowWindow=" +;
		LTRIM(STR(ThisForm.ShowWindow)) + Chr(13) + lcMsg)

PROCEDURE  decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER IsChild IN user32 INTEGER hWndParent, INTEGER hwnd

ENDDEFINE  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[IsChild](../libraries/user32/IsChild.md)  

## Comment:
This example shows that the ShowWindow property of the form ***really affects*** the Parent-Child relationship between the form and the main VFP window.   
  
Among other consequences of this statement there is the one: *you can not successfully apply the Win32 SetMenu function to a form with its ShowWindow property other than 2.*  
  
***  

