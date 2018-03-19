[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Animating a transition of the VFP form (a wire-frame rectangle)

## Before you begin:
A modest sort of animation comparing to what Vista and Mac OS provide.  

See also:

* [How to make a VFP form fading out when released](sample_527.md)  
  
***  


## Code:
```foxpro  
DO declare
#DEFINE IDANI_OPEN    1
#DEFINE IDANI_CLOSE   2
#DEFINE IDANI_CAPTION 3

PUBLIC objForm
objForm = CreateObject("TForm")
objForm.Visible = .T.

DEFINE CLASS TForm As Form
	BackColor = RGB(157,185,200)
	Width=450
	Height=200
	Caption = "Animating a wire-frame rectangle aroung the form"
	
	PROTECTED left0, top0, width0, height0

	ADD OBJECT cmdA AS CommandButton WITH;
	Left=10, Top=15, Width=60, Height=24, Caption="A",;
	Enabled=.T.

	ADD OBJECT cmdB AS CommandButton WITH;
	Left=72, Top=15, Width=60, Height=24, Caption="B",;
	Enabled=.F.
	
	ADD OBJECT chAnim As CheckBox WITH;
	Left=12, Top=45, Caption="Animation On",;
	AutoSize=.T., BackStyle=0, Value=.T.

PROCEDURE  Init
	THIS.left0 = THIS.Left
	THIS.top0 = THIS.top
	THIS.width0 = THIS.width
	THIS.height0 = THIS.Height

PROCEDURE  AnimateMove (lcMode)
	LOCAL hWindow, lcFrom, lcTo, lnLeft0, lnTop0,;
		lnWidth0, lnHeight0, lnLeft1, lnTop1,;
		lnWidth1, lnHeight1, lnFlags

	hWindow = GetFocus()

	lnLeft0 = THIS.Left
	lnTop0 = THIS.top
	lnWidth0 = THIS.width
	lnHeight0 = THIS.Height

	IF lcMode = "A"
		lnLeft1 = 500
		lnTop1 = 400
		lnWidth1 = 250
		lnHeight1 = 150
		lnFlags = BitOr(IDANI_OPEN, IDANI_CAPTION)
	ELSE
		lnLeft1 = THIS.left0
		lnTop1 = THIS.top0
		lnWidth1 = THIS.width0
		lnHeight1 = THIS.height0
		lnFlags = BitOr(IDANI_CLOSE, IDANI_CAPTION)
	ENDIF

	lcFrom = num2dword(lnLeft0) + num2dword(lnTop0) +;
		num2dword(lnLeft0+lnWidth0-1) + num2dword(lnHeight0+lnTop0-1)

	lcTo  = num2dword(lnLeft1) + num2dword(lnTop1) +;
		num2dword(lnWidth1+lnLeft1-1) + num2dword(lnHeight1+lnTop1-1)

	IF ThisForm.chAnim.Value
		= DrawAnimatedRects (hWindow, lnFlags, @lcFrom, @lcTo)
	ENDIF

	THIS.move (lnLeft1, lnTop1, lnWidth1, lnHeight1)

	ThisForm.cmdA.Enabled = ThisForm.cmdB.Enabled
	ThisForm.cmdB.Enabled = !ThisForm.cmdB.Enabled

PROCEDURE  cmdA.Click
	ThisForm.AnimateMove(THIS.Caption)

PROCEDURE  cmdB.Click
	ThisForm.AnimateMove(THIS.Caption)

ENDDEFINE

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE  declare
	DECLARE INTEGER GetFocus IN user32

	DECLARE INTEGER DrawAnimatedRects IN user32;
		INTEGER hwnd, INTEGER idAni,;
		STRING @lprcFrom, STRING @lprcTo  
```  
***  


## Listed functions:
[DrawAnimatedRects](../libraries/user32/DrawAnimatedRects.md)  
[GetFocus](../libraries/user32/GetFocus.md)  

## Comment:
Two RECT structures are passed to the DrawAnimatedRects function: one for the initial position of the form, and another for the position the form to be moved to.   
  
The animation is applied just before moving the form to a new destination. That makes the transition smooth and elegant. Meanwhile you can try to put the animation on and off to feel the difference.  
  
***  

