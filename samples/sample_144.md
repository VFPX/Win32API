[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a clipping region from the path selected into the device context of a form

## Code:
```foxpro  
PUBLIC frm
frm = CreateObject("Tform")
frm.Visible = .T.

DEFINE CLASS Tform As Form
	Width=700
	Height=250
	Caption="Working with GDI Path and Region"
	mouseX=0
	mouseY=0
	BorderStyle=2
	Backcolor = Rgb (192,192,192)
	hFontHeader=0
	hFontMemo=0
	
	ADD OBJECT txt As TextBox WITH;
		Left=10, Top=THIS.Height-35, Width=140,;
		Height=25, Value="FoxPro"

	ADD OBJECT cmdClip As CommandButton WITH;
		Top=THIS.txt.Top, Left=THIS.txt.Left+THIS.txt.Width+5,;
		Height=THIS.txt.Height, Width=50,;
		Default=.T., Caption="Clip"

	ADD OBJECT chkMode As CheckBox WITH;
		Top=THIS.txt.Top, Left=THIS.cmdClip.Left+THIS.cmdClip.Width+15,;
		Backstyle=0, Autosize=.T., Caption="Invert", Value=.F.

PROCEDURE  Load
	DO decl

PROCEDURE  Init
	THIS.createFont

PROCEDURE  Destroy
	THIS.releaseFont
	
PROCEDURE  DblClick
	THIS.removeRegion

PROCEDURE MouseDown
LPARAMETERS nButton, nShift, nXCoord, nYCoord
* stores cursor absolute position
	IF nButton = 1
		LOCAL lnX, lnY
		= getMousePos (@lnX, @lnY)
		ThisForm.mouseX = lnX
		ThisForm.mouseY = lnY
	ENDIF

PROCEDURE MouseMove
LPARAMETERS nButton, nShift, nXCoord, nYCoord
	IF nButton = 1
		ThisForm._move && moves the form
	ENDIF

PROCEDURE  cmdClip.Click
	ThisForm.clipText

PROCEDURE  createFont
#DEFINE FW_BOLD             700
#DEFINE FW_NORMAL           400
#DEFINE ANSI_CHARSET          0
#DEFINE OUT_OUTLINE_PRECIS    8
#DEFINE CLIP_STROKE_PRECIS    2
#DEFINE PROOF_QUALITY         2
#DEFINE DEFAULT_PITCH         0

	THIS.hFontHeader = CreateFont (;
		100,0, 0,0, FW_BOLD, 0,0,0, ANSI_CHARSET,;
		OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
		PROOF_QUALITY, DEFAULT_PITCH, "Times New Roman")

	THIS.hFontMemo = CreateFont (;
		32,0, 0,0, FW_NORMAL, 0,0,0, ANSI_CHARSET,;
		OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
		PROOF_QUALITY, DEFAULT_PITCH, "Arial")

PROCEDURE  releaseFont
	= DeleteObject (THIS.hFontMemo)
	= DeleteObject (THIS.hFontHeader)

PROCEDURE  clipText
#DEFINE TRANSPARENT  1
#DEFINE OPAQUE       2
#DEFINE RGN_COPY     5
	LOCAL lcText, hwnd, hdc, hStoredFont
	hwnd = GetFocus()
	hdc = GetWindowDC (hwnd)
	
	= BeginPath (hdc)
		hStoredFont = SelectObject (hdc, THIS.hFontHeader)
		= SetBkMode (hdc, Iif(ThisForm.chkMode.Value, OPAQUE,TRANSPARENT))
		THIS._print (hdc, 15,25, " "+ALLTRIM(THIS.txt.Value)+" ")

		= SelectObject (hdc, THIS.hFontMemo)
		= SetBkMode (hdc, OPAQUE)
		THIS._print (hdc, 15,125, " Double click to restore the original view ")
		THIS._print (hdc, 15,160, " The form is still movable ")
	= EndPath (hdc)

	hRgn = PathToRegion (hdc)
	= SetWindowRgn (hwnd, hRgn, 1)

	= SelectObject (hdc, hStoredFont)
	= ReleaseDC (hwnd, hdc)

PROCEDURE  _print (hdc, X,Y, lcText)
	= TextOut (hdc, X,Y, lcText, Len(lcText))

PROCEDURE  removeRegion
	LOCAL hwnd
	hwnd = GetFocus()
	= SetWindowRgn (hwnd, 0, 1)

PROCEDURE _move
	LOCAL lnX, lnY, lnPosX, lnPosY
	= getMousePos (@lnX, @lnY) && gets cursor absolute position

	IF Not (ThisForm.mouseX = lnX And ThisForm.mouseY = lnY)
	* moves the form only if cursor absolute position changed
		lnPosX = ThisForm.Left + (lnX - ThisForm.mouseX)
		lnPosY = ThisForm.Top + (lnY - ThisForm.mouseY)
		ThisForm.Move (lnPosX, lnPosY)
		
		* stores the current
		ThisForm.mouseX = lnX
		ThisForm.mouseY = lnY
	ENDIF

ENDDEFINE

PROCEDURE  decl
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER SelectObject IN gdi32;
			INTEGER hdc, INTEGER hObject

 	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject

	DECLARE INTEGER SetBkMode IN gdi32;
		INTEGER hdc, INTEGER iBkMode

	DECLARE INTEGER TextOut IN gdi32;
		INTEGER hdc, INTEGER x, INTEGER y,;
		STRING  lpString, INTEGER nCount

	DECLARE INTEGER CreateFont IN gdi32;
		INTEGER nHeight, INTEGER nWidth,;
		INTEGER nEscapement, INTEGER nOrientation,;
		INTEGER fnWeight, INTEGER fdwItalic,;
		INTEGER fdwUnderline, INTEGER fdwStrikeOut,;
		INTEGER fdwCharSet,;
		INTEGER fdwOutputPrecision,;
		INTEGER fdwClipPrecision,;
		INTEGER fdwQuality,;
		INTEGER fdwPitchAndFamily,;
		STRING  lpszFace

	DECLARE INTEGER BeginPath IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPath IN gdi32 INTEGER hdc
	DECLARE INTEGER PathToRegion IN gdi32 INTEGER hdc

	DECLARE SetWindowRgn IN user32;
		INTEGER hWnd, INTEGER hRgn, INTEGER bRedraw

	DECLARE INTEGER GetCursorPos IN user32 STRING @ lpPoint

PROCEDURE getMousePos (x, y)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), 8)
	= GetCursorPos (@lcBuffer)
	x = buf2dword(SUBSTR(lcBuffer, 1,4))
	y = buf2dword(SUBSTR(lcBuffer, 5,4))

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
       Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
       Asc(SUBSTR(lcBuffer, 4,1)) * 16777216  
```  
***  


## Listed functions:
[BeginPath](../libraries/gdi32/BeginPath.md)  
[CreateFont](../libraries/gdi32/CreateFont.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EndPath](../libraries/gdi32/EndPath.md)  
[GetCursorPos](../libraries/user32/GetCursorPos.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[PathToRegion](../libraries/gdi32/PathToRegion.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetBkMode](../libraries/gdi32/SetBkMode.md)  
[SetWindowRgn](../libraries/user32/SetWindowRgn.md)  
[TextOut](../libraries/gdi32/TextOut.md)  

## Comment:
The Path-Region transformation allows to clip the form exactly by a text string printed on its device context.  
  
***  

