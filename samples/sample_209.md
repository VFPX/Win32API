[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving top-child window for the VFP form

## Before you begin:
Push the button on the form to display the top-child window propeties for this form.   

This code demonstrates that the native VFP controls (*ListBox, ComboBox, TextBox, Label, EditBox etc.*) are windowless. They are not windows.  
  
***  


## Code:
```foxpro  
PUBLIC frm
frm = CreateObject("Tform")
frm.Visible = .T.

DEFINE CLASS Tform As Form
Width=400
Height=300
AutoCenter = .T.

	ADD OBJECT lst As ListBox WITH;
		Left=10, Top=10, Width=150, Height=270

	ADD OBJECT lbl As Label WITH;
		Caption="Label1", Left=165, Top=7,;
		AutoSize=.T.

	ADD OBJECT txt As TextBox WITH;
		Left=165, Top=24, Width=220
	
	ADD OBJECT cmb As ComboBox WITH;
		Left=165, Top=70, Width=60

	ADD OBJECT cmd As CommandButton WITH;
		Left=260, Top=70, Height=24, Width=124,;
		Caption="List Child Windows"
	
	ADD OBJECT edt As EditBox WITH;
		Left=165, Top=120, Width=220, Height=60

PROCEDURE Init
	* this ActiveX control is the top-child window for the form
	THIS.AddComCtrl

PROCEDURE AddComCtrl
	THIS.AddObject ("ComCtrl", "OLEControl", "MSComctlLib.TreeCtrl")
	WITH THIS.ComCtrl
		.Left = 165
		.Top = 200
		.Width = 220
		.Height = 70
		
		root = .Nodes.Add(,,"R","Root")
		.Nodes.Add("R", 4, "c1", "Child 1")
		.Nodes.Add("R", 4, "c2", "Child 2")
		.Nodes.Add("R", 4, "c3", "Child 3")
		root.Expanded = .T.

		.Visible = .T.
	ENDWITH

PROCEDURE cmd.Click
	ThisForm.ListChildWindows

PROCEDURE ListChildWindows
#DEFINE GW_HWNDNEXT 2
#DEFINE GW_CHILD 5
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindow IN user32 INTEGER hwnd, INTEGER wFlag
	
	LOCAL hFormWindow, hTopChild
	hFormWindow = GetFocus()
	hTopChild = GetWindow(hFormWindow, GW_CHILD)

	THIS.PrintWinData("This Form:", hFormWindow)
	IF hTopChild <> 0
		THIS.PrintWinData("Top child:", hTopChild)
	ELSE
		ACTI SCREEN
		? "No top child window found"
	ENDIF

FUNCTION PrintWinData(lcTitle, hWindow)
	LOCAL lcCaption, lnWinLeft, lnWinTop, lnWinRight, lnWinBottom
	lcCaption = THIS.GetWindowCaption(hWindow)
	STORE 0 TO lnWinLeft, lnWinTop, lnWinRight, lnWinBottom
	THIS.GetDim(hWindow, @lnWinLeft, @lnWinTop, @lnWinRight, @lnWinBottom)

	ACTI SCREEN
	? lcTitle, "Left:", lnWinLeft, "Top:", lnWinTop,;
		"Right:", lnWinRight, "Bottom:", lnWinBottom,;
		"Caption:", lcCaption

FUNCTION GetWindowCaption(hWindow)
	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch
	LOCAL lnLength, lcText
	lcText = SPACE(250)
	lnLength = GetWindowText(hWindow, @lcText, Len(lcText))
RETURN Iif(lnLength>0, Left(lcText, lnLength), "#empty#")

FUNCTION GetDim(hWindow, lnWinLeft, lnWinTop, lnWinRight, lnWinBottom)
	DECLARE SHORT GetWindowRect IN user32 INTEGER hwnd, STRING @ lpRect
    LOCAL lcBuffer
    lcBuffer = REPLI(Chr(0), 16)
    = GetWindowRect(hWindow, @lcBuffer)
	lnWinLeft = buf2dword(SUBSTR(lcBuffer, 1,4))
	lnWinTop = buf2dword(SUBSTR(lcBuffer, 5,4))
	lnWinRight = buf2dword(SUBSTR(lcBuffer, 9,4))
	lnWinBottom = buf2dword(SUBSTR(lcBuffer, 13,4))
ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216  
```  
***  


## Listed functions:
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  

## Comment:
Only if an ActiveX control is added to the form (ThisForm.ComCtrl in this example), it appears to be the top-child window for the form.  
  
This is interesting: the VFP form with ThisForm.ShowWindow=2 has a top-child window inside even with no controls added to it. It looks like its client area is this top-child window.  
  
***  

