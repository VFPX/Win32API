[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Clipping mouse cursor area



## Before you begin:
By clicking on the **Clip** button you are confining the mouse cursor to the rectangle of the form.  
To restore the previous state click on the **Restore** button or move the form.  

***  


## Code:
```foxpro  
PUBLIC frm
frm = CreateObject("TForm")
frm.Visible = .T.

DEFINE CLASS TForm As Form
PROTECTED mClip
	MaxButton=.F.
	MinButton=.F.
	Width=500
	Height=250
	Caption = "Clipping mouse cursor area"
	BorderStyle=2
	AutoCenter=.T.

	ADD OBJECT cmdClip As TCommand WITH Caption="Clip"
	ADD OBJECT cmdRestore As TCommand WITH Caption="Restore"

PROCEDURE Init
 	THIS.declare
	* save initial clipping area
	lpRect = REPLICATE(Chr(0), 16)
	= GetClipCursor(@lpRect)
	THIS.mClip = m.lpRect
	THIS.Resize

PROCEDURE Destroy
	THIS.RestoreInitStatus

PROCEDURE Resize
	lnTop = MAX(5, THIS.Height - THIS.cmdClip.Height - 5)
	STORE lnTop TO THIS.cmdClip.Top, THIS.cmdRestore.Top
	THIS.cmdRestore.Left = THIS.Width - THIS.cmdRestore.Width - 10
	THIS.cmdClip.Left = THIS.cmdRestore.Left - THIS.cmdClip.Width - 2

PROCEDURE clip
* locks the cursor inside the form
	MOUSE AT THIS.top, THIS.left PIXELS  && put cursor inside the form
	* give VFP a time slice for updating mouse position in its internal data
	= INKEY(0.1)

	lpPoint = REPLICATE(Chr(0), 8)	&& allocate space for POINT structure
	= GetCursorPos(@lpPoint)  && retrieve absolute mouse position

	LOCAL absX, absY, lcCaptionHeight, lcFrameWidth,;
		lcFrameHeight, lcRect

	absX = ThisForm.buf2dword(SUBSTR(lpPoint, 1,4))
	absY = ThisForm.buf2dword(SUBSTR(lpPoint, 5,4))

	* retrieve some sizes to be used in calculating the area
	lcCaptionHeight=GetSystemMetrics(4)  && size of normal caption area
	lcFrameWidth=GetSystemMetrics(32)  && resiz.window frame width
	lcFrameHeight=GetSystemMetrics(33)  && resiz.window frame height

	lcRect = REPLI(Chr(0), 16)	&& allocate space for RECT structure
	* resize the RECT using the form position, and size
	THIS.num2rect(absX, absY, absX + THIS.Width + lcFrameWidth,;
		absY + THIS.Height + lcCaptionHeight + lcFrameHeight, @lcRect)

	= ClipCursor(lcRect)  && locked!

PROCEDURE RestoreInitStatus
	= ClipCursor(THIS.mClip)

PROCEDURE cmdClip.Click
	ThisForm.clip

PROCEDURE cmdRestore.Click
	ThisForm.RestoreInitStatus

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE num2rect(lnLeft, lnTop, lnRight, lnBottom, lcBuffer)
	lcBuffer = THIS.num2dword(lnLeft) + THIS.num2dword(lnTop)+;
		THIS.num2dword(lnRight) + THIS.num2dword(lnBottom)

PROCEDURE declare
	DECLARE INTEGER ClipCursor IN user32 STRING lpRect
	DECLARE INTEGER GetCursorPos IN user32 STRING @lpPoint
	DECLARE INTEGER GetClipCursor IN user32 STRING @lpRect
	DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex

ENDDEFINE

DEFINE CLASS TCommand As CommandButton
	Width=60
	Height=25
ENDDEFINE  
```  
***  


## Listed functions:
[ClipCursor](../libraries/user32/ClipCursor.md)  
[GetClipCursor](../libraries/user32/GetClipCursor.md)  
[GetCursorPos](../libraries/user32/GetCursorPos.md)  
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  
