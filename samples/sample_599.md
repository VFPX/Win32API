[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: custom control, base class

## Before you begin:
This class is a base for a series of custom VFP controls:  

* [Clock control](sample_597.md)  
* [Slider control](sample_598.md)  
  
***  


## Code:
```foxpro  
DEFINE CLASS GdiplusControl As Container
PROTECTED EventsBound, gdiplus, hWindow, hDC,;
	oFormGraphics, oBackBuffer
	
	EventsBound=.F.
	gdiplus=0
	hWindow=0
	hDC=0
	oFormGraphics=NULL
	oBackBuffer=NULL

	BaseTimerTicks=0
	
	* resolves modal forms redraw issue
	ADD OBJECT BaseTimer as Timer WITH;
	Enabled=.F., Interval=16

PROCEDURE Init
	SET PROCEDURE TO gdiplus ADDITIVE
	WITH THIS
		.declare
		.gdiplus = CREATEOBJECT("gdiplusinit")
	ENDWITH

PROCEDURE BaseTimer.Timer
	WITH THIS.Parent
		.DrawFrame
		THIS.Enabled = .F.
	ENDWITH

PROCEDURE Destroy
	THIS.ClearInstance

PROCEDURE Visible_ASSIGN(vValue)
	THIS.Visible = vValue
	THIS.DrawFrame

PROCEDURE Enabled_ASSIGN(vValue)
	THIS.Enabled = vValue
	THIS.DrawFrame

PROTECTED PROCEDURE ReleaseGdiplusObjects

PROCEDURE ClearInstance
	WITH THIS
		.ReleaseGdiplusObjects
		.ReleaseFrontBuffer
		.oBackBuffer=NULL
		.gdiplus=NULL
	ENDWITH

PROTECTED PROCEDURE ReleaseFrontBuffer
	WITH THIS
		IF .hWindow <> 0 AND .hDC <> 0
			.oFormGraphics=NULL
			= ReleaseDC(.hWindow, .hDC)
			STORE 0 TO .hWindow, .hDC
		ENDIF
	ENDWITH

PROTECTED PROCEDURE InitFrontBuffer
* acquires graphics object of a hosting form
	WITH THIS
		.ReleaseFrontBuffer
		
		IF ThisForm.ShowWindow = 2
		* todo: use inner window ?
			DECLARE INTEGER GetWindow IN user32;
				INTEGER hWindow, INTEGER nMode
			.hWindow = GetWindow(ThisForm.HWnd, 0)
		ELSE
			.hWindow = ThisForm.HWnd
		ENDIF
		
		.hDC = GetDC(.hWindow)
		.oFormGraphics = CREATEOBJECT("graphics", .hDC)
	ENDWITH

PROCEDURE ClearBackBuffer
* possible issue: a complex background
* e.g. a shape behind, background picture
* will not be drawn properly
	WITH THIS.oBackBuffer
		.graphics.FillRectangle(;
			ColorToARGB(THIS.GetAbsoluteBackColor(), 255),;
			THIS.BorderWidth,;
			THIS.BorderWidth,;
			.imgwidth - THIS.BorderWidth * 2 - 1,;
			.imgheight - THIS.BorderWidth * 2 - 1)
	ENDWITH

PROTECTED PROCEDURE BindEvents
	IF THIS.EventsBound OR TYPE("THIS.Parent") <> "O"
		RETURN
	ENDIF

	BINDEVENT(THIS, "Refresh", THIS, "RedrawFrame", 1)
	BINDEVENT(THIS, "UIEnable", THIS, "OnUIEnable", 1)
	
	IF VARTYPE(ThisForm) = "O"
		BINDEVENT(ThisForm, "Paint", THIS, "DrawFrame")
		BINDEVENT(ThisForm, "Moved", THIS, "RedrawFrame")
		BINDEVENT(ThisForm, "Resize", THIS, "OnFormResize", 1)
		BINDEVENT(ThisForm, "GotFocus", THIS, "RedrawFrame")
		BINDEVENT(ThisForm, "Activate", THIS, "RedrawFrame")
		BINDEVENT(ThisForm, "Refresh", THIS, "RedrawFrame")
	ENDIF
	
	DO CASE
	CASE THIS.Parent.BaseClass = "Form"
	
	CASE THIS.Parent.BaseClass = "Container"
		BINDEVENT(THIS.Parent, "Moved", THIS, "RedrawFrame")
		BINDEVENT(THIS.Parent, "Resize", THIS, "RedrawFrame")
		BINDEVENT(THIS.Parent, "GotFocus", THIS, "RedrawFrame")

	CASE THIS.Parent.BaseClass = "Page"
		BINDEVENT(THIS.Parent, "Activate", THIS, "RedrawFrame")
	ENDCASE

	THIS.EventsBound = .T.

PROCEDURE OnFormResize
	IF ThisForm.WindowState = 0
		THIS.BaseTimerTicks = 0
		THIS.BaseTimer.Enabled = .T.
	ENDIF
	THIS.DrawFrame

PROCEDURE declare
	DECLARE INTEGER GetDC IN user32 INTEGER hWindow
	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hWindow, INTEGER dc

PROCEDURE RedrawFrame
	THIS.DrawFrame

PROCEDURE Paint
	THIS.DrawFrame

PROCEDURE OnUIEnable
LPARAMETERS lEnable
	THIS.DrawFrame

PROTECTED PROCEDURE GetAbsoluteBackColor
	IF THIS.BackStyle = 1
		RETURN THIS.BackColor
	ENDIF
	
	LOCAL oParent
	oParent = THIS.Parent
	
	DO WHILE .T.
		IF oParent = ThisForm;
			OR oParent.BackStyle = 1
			RETURN oParent.BackColor
		ENDIF

		oParent = oParent.Parent
	ENDDO
RETURN ThisForm.BackColor

PROTECTED PROCEDURE GetAbsolutePosition
PARAMETERS nAbsX, nAbsY, lVisible, lEnabled
	LOCAL oParent
	nAbsX = THIS.Left
	nAbsY = THIS.Top
	oParent = THIS.Parent
	
	DO WHILE .T.
		IF oParent = ThisForm OR NOT lVisible
			EXIT
		ENDIF

		IF oParent.BaseClass == "Page"
			nAbsX = nAbsX +;
				(oParent.Parent.Width -;
					oParent.Parent.PageWidth)

			nAbsY = nAbsY +;
				(oParent.Parent.Height -;
					oParent.Parent.PageHeight)

			lVisible = lVisible AND;
				oParent.PageOrder = oParent.Parent.ActivePage
		ELSE
			nAbsX = nAbsX + oParent.Left
			nAbsY = nAbsY + oParent.Top
			lVisible = lVisible AND oParent.Visible
		ENDIF
		
		lEnabled = lEnabled AND oParent.Enabled
		oParent = oParent.Parent
	ENDDO

PROTECTED PROCEDURE InitBuffers
	IF VARTYPE(THIS.oBackBuffer) = "O"
		RETURN
	ENDIF

	THIS.InitFrontBuffer()

	* creates the back buffer
	THIS.oBackBuffer = CREATEOBJECT(;
		"gdibitmap", THIS.Width, THIS.Height)
		
	* sets high quality smoothing mode
	THIS.oBackBuffer.graphics.SmoothingMode = 4

PROTECTED PROCEDURE DrawOnBackBuffer(lEnabled as Boolean)

PROCEDURE DrawFrame
	IF VARTYPE(ThisForm) <> "O" OR;
		NOT THIS.Visible
		RETURN
	ENDIF
	
	LOCAL nAbsX, nAbsY, lVisible, lEnabled
	lVisible = THIS.Visible
	lEnabled = THIS.Enabled
	STORE 0 TO nAbsX, nAbsY
	
	THIS.GetAbsolutePosition(;
		@nAbsX, @nAbsY, @lVisible, @lEnabled)
	
	IF NOT lVisible
		RETURN
	ENDIF

	WITH THIS
		.InitBuffers
		
		.DrawOnBackBuffer(.T.)
		
		IF VARTYPE(THIS.oFormGraphics) = "O"
			* copies the back buffer
			* to the front buffer (the form)
			.oFormGraphics.DrawImage(;
				.oBackBuffer,;
				m.nAbsX,;
				m.nAbsY)
		ENDIF
	ENDWITH

FUNCTION buf2word(cBuffer)
RETURN;
	ASC(SUBSTR(cBuffer, 1,1)) + ;
	ASC(SUBSTR(cBuffer, 2,1)) * 256

ENDDEFINE  
```  
***  


## Listed functions:
[GetDC](../libraries/user32/GetDC.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
