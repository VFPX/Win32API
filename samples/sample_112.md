[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Drawing standard Windows icons

## Before you begin:
![](../images/stdicons.png)  
See also:

* [Displaying the associated icons and descriptions for files and folders](sample_530.md)  
* [How to view icons stored in executable files](sample_113.md)  
* [Drawing Windows frame controls](sample_254.md)  
* [Drawing Windows predefined bitmaps](sample_253.md)  
  
***  


## Code:
```foxpro  
PUBLIC frm
frm = CREATEOBJECT("Tform")
frm.Visible = .T.
* end of main

DEFINE CLASS Tform As Form
* Icon Ids
#DEFINE IDI_APPLICATION  32512
#DEFINE IDI_ASTERISK  32516
#DEFINE IDI_ERROR  32513
#DEFINE IDI_EXCLAMATION  32515
#DEFINE IDI_HAND  IDI_ERROR
#DEFINE IDI_INFORMATION  IDI_ASTERISK
#DEFINE IDI_QUESTION  32514
#DEFINE IDI_WARNING  IDI_EXCLAMATION
#DEFINE IDI_WINLOGO  32517

	Width=400
	Height=130
	AutoCenter = .T.
	Caption = " Drawing standard Windows Icons"

	ADD OBJECT cmd As CommandButton WITH;
		Caption="Draw", Width=80, Height=27

PROCEDURE Init
	THIS.declare
	THIS.Resize

PROCEDURE Resize
	WITH THIS.cmd
		.Left = Int((ThisForm.Width - .Width)/2)
		.Top = THIS.Height - .Height - 20
	ENDWITH
	ThisForm.DrawIcons

PROCEDURE DrawIcons
	THIS._draw(IDI_APPLICATION, 20,20)
	THIS._draw(IDI_HAND, 60,20)
	THIS._draw(IDI_QUESTION, 100,20)
	THIS._draw(IDI_EXCLAMATION, 140,20)
	THIS._draw(IDI_ASTERISK, 180,20)
	THIS._draw(IDI_WINLOGO, 220,20)
	THIS._draw(IDI_WARNING, 260,20)
	THIS._draw(IDI_ERROR, 300,20)
	THIS._draw(IDI_INFORMATION, 340,20)

PROTECTED PROCEDURE _draw(lnIconId, X,Y)
	LOCAL hWindow, hdc, hicon
	hWindow = THIS.HWnd && GetFocus() for older VFP versions

	hdc = GetDC(hWindow)

	hicon = LoadIcon(0, lnIconId)
	IF hicon <> 0
		= DrawIcon(hdc, X,Y, hicon)
	ENDIF
	= ReleaseDC(hWindow, hdc)

PROCEDURE declare
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetDC IN user32 INTEGER hWindow

	DECLARE INTEGER LoadIcon IN user32;
		INTEGER hInstance, INTEGER lpIconName

	DECLARE SHORT DrawIcon IN user32;
		INTEGER hDC, INTEGER X, INTEGER Y, INTEGER hIcon

	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hWindow, INTEGER hdc

PROCEDURE Paint
	ThisForm.DrawIcons

PROCEDURE Moved
	ThisForm.DrawIcons

PROCEDURE cmd.Click
	ThisForm.DrawIcons

ENDDEFINE  
```  
***  


## Listed functions:
[DrawIcon](../libraries/user32/DrawIcon.md)  
[GetDC](../libraries/user32/GetDC.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[LoadIcon](../libraries/user32/LoadIcon.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  

## Comment:
Since the icons are displayed not via native VFP controls, the Resize, Paint and Moved methods of the form need to be instructed to redraw the icons. Otherwise the icons would be wiped out when, for example, the form after having been partially moved beyond the main VFP window then is moved within.  
  
***  

