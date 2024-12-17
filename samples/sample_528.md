[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to make a VFP form fading out when released (GDI version)

## Short description:
When a VFP form is released, usually it disappears immediately. Wouldn't it be nice to have the form slowly (or less slowly) fading out?

An obvious way of doing that is covering the form with another window, which holds the image of the original form. Once covered, the original form disappears. After that the covering window gradually changes its opacity (alpha channel) from opaque (255) to completely transparent (0).  
***  


## Before you begin:
When a VFP form is released, usually it disappears immediately. Wouldn't it be nice to have a form slowly (or less slowly) fading out?  

An obvious way of doing that is covering the form with another window, which holds the image of the original form. Once covered, the original form disappears. After that the covering window gradually changes its opacity (alpha channel) from opaque (255) to completely transparent (0).  

This code sample is based on solely GDI calls, no GDI+ library is required. Beside fading, the form is shrinking too.  

See also:

* [How to make a VFP form fading out when released (GDI+ version)](sample_527.md)  
* [How to draw custom Window Caption on FoxPro form](sample_499.md)  
* [Animating a transition of the VFP form (a wire-frame rectangle)](sample_255.md)  
  
***  


## Code:
```foxpro  
PUBLIC oForm As Tform
oForm = CREATEOBJECT("Tform")
oForm.Visible=.T.
* end of main

DEFINE CLASS Tform As Form
	Width=500
	Height=350
	Caption="Enhancing user interface with GDI API calls"
*	ShowWindow=2
	Autocenter=.T.
	
	ADD OBJECT cmd As CommandButton WITH Left=210, Top=310,;
	Width=80, Height=27, Caption="Close"
	
PROCEDURE cmd.Click
	ThisForm.Release

PROCEDURE Destroy
	IF VARTYPE(_screen.FormFader1) <> "O"
		_screen.AddObject("FormFader1", "FormFader")
	ENDIF
	_screen.FormFader1.FadeWindow(THIS)

ENDDEFINE

DEFINE CLASS FormFader As Container
#DEFINE SRCCOPY 0x00CC0020
#DEFINE DWORD_MAX_VALUE 0xffffffff
#DEFINE WS_VISIBLE 0x10000000
#DEFINE WS_EX_LAYERED 0x80000
#DEFINE WS_EX_NOACTIVATE 0x8000000
#DEFINE SM_CYCAPTION 4
#DEFINE SM_CXFRAME 32
#DEFINE SM_CYFRAME 33
#DEFINE LWA_ALPHA 2
#DEFINE LWA_COLORKEY 1
#DEFINE GWL_EXSTYLE -20
#DEFINE GWL_STYLE -16
#DEFINE TIMER_INTERVAL 20
#DEFINE ALPHA_MIN_VALUE 4
#DEFINE ALPHA_DECREASE_BY 2
#DEFINE BRIGHT_WHITE RGB(255,255,255)
#DEFINE DIMEN_DECREASE_RATIO 0.995

	Visible=.F.
	fadingwindows=NULL
	ADD OBJECT Timer1 As Timer

PROCEDURE Init
	THIS.declare
	THIS.fadingwindows = CREATEOBJECT("Collection")

PROCEDURE Destroy
	THIS.Timer1.Interval=0
	IF VARTYPE(THIS.fadingwindows) = "O"
		DO WHILE THIS.fadingwindows.Count > 0
			THIS.fadingwindows.Remove(1)
		ENDDO
	ENDIF

PROCEDURE FadeWindow(oForm As Form)
	LOCAL fw As FadingWindow
	fw = CREATEOBJECT("FadingWindow", oForm.HWnd)
	THIS.fadingwindows.Add(m.fw)
	THIS.Timer1.Interval=TIMER_INTERVAL

PROCEDURE Timer1.Timer
	THIS.Parent.DrawWindows

PROCEDURE DrawWindows
	LOCAL fw As FadingWindow
	FOR EACH fw IN THIS.fadingwindows
		IF NOT fw.DrawBackground()
			THIS.RemoveWindow(m.fw)
			IF THIS.fadingwindows.Count = 0
				THIS.Timer1.Interval=0
			ENDIF
		ENDIF
	NEXT

PROCEDURE RemoveWindow(fw As FadingWindow)
	LOCAL fw As FadingWindow, nIndex
	WITH THIS.fadingwindows
		FOR nIndex=1 TO .Count
			IF .Item(m.nIndex).hCoverWindow = fw.hCoverWindow
				.Remove[m.nIndex]
				EXIT
			ENDIF
		NEXT
	ENDWITH

PROCEDURE declare
	DECLARE INTEGER DestroyWindow IN user32 INTEGER hWindow
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwindow
	DECLARE INTEGER GetDC IN user32 INTEGER hwindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex
	DECLARE INTEGER GetWindowLong IN user32 INTEGER hWindow, INTEGER nIndex
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObj
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObj
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER CreateSolidBrush IN gdi32 LONG crColor

	DECLARE INTEGER SetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex, INTEGER dwNewLong

	DECLARE INTEGER CreateRectRgn IN gdi32;
		INTEGER nLeftRect, INTEGER nTopRect,;
		INTEGER nRightRect, INTEGER nBottomRect

	DECLARE INTEGER SetWindowRgn IN user32;
		INTEGER hWindow, INTEGER hRgn, SHORT bRedraw

	DECLARE INTEGER RealGetWindowClass IN user32;
		INTEGER hWindow, STRING @pszType, INTEGER cchType

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

	DECLARE INTEGER CreateWindowEx IN user32;
		INTEGER dwExStyle, STRING lpClassName, STRING lpWindowName,;
		INTEGER dwStyle, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent,;
		INTEGER hMenu, INTEGER hInstance, INTEGER lpParam

	DECLARE INTEGER SetLayeredWindowAttributes IN user32;
		INTEGER hWindow, INTEGER crKey,;
		SHORT bAlpha, INTEGER dwFlags

	DECLARE INTEGER StretchBlt IN gdi32;
		INTEGER hdcDest, INTEGER nXOrigDst, INTEGER nYOrigDst,;
		INTEGER nWidthDest, INTEGER nHeightDest,;
		INTEGER hdcSrc, INTEGER nXOrigSrc, INTEGER nYOrigSrc,;
		INTEGER nWidthSrc, INTEGER nHeightSrc, INTEGER dwRop

	DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
		INTEGER hdc, INTEGER nWidth, INTEGER nHeight

	DECLARE INTEGER FillRect IN user32;
		INTEGER hDC, STRING @RECT, INTEGER hBrush

ENDDEFINE

DEFINE CLASS FadingWindow As Session
	hOrigWindow=0 && HWND of the original form
	hCoverWindow=0 && HWND of the covering window
	hCoverDC=0

	winleft=0  && coordinates of the original form
	wintop=0
	winwidth=0
	winheight=0

	cwinleft=0  && coordinates of the covering window
	cwintop=0
	cwinwidth=0
	cwinheight=0
	
	ewinleft=0  && effective coordinates (shrinking)
	ewintop=0
	ewinwidth=0
	ewinheight=0

	alphachannel=0xff  && alpha channel value
	fadingsteps=0
	canvas_form=NULL
	canvas_buffer=NULL

PROCEDURE Init(hOrigWindow As Integer)
	THIS.hOrigWindow = m.hOrigWindow
	THIS.CopyWinImage
	THIS.CreateCoveringWindow

PROCEDURE Destroy
	THIS.DestroyCoverWindow

PROCEDURE DestroyCoverWindow
	IF THIS.hCoverDC <> 0
		= ReleaseDC(THIS.hCoverWindow, THIS.hCoverDC)
		THIS.hCoverDC=0
	ENDIF
	IF THIS.hCoverWindow <> 0
		= DestroyWindow(THIS.hCoverWindow)
		THIS.hCoverWindow=0
	ENDIF

PROTECTED PROCEDURE CopyWinImage
* copies the image of the original form to memory dc
	LOCAL hdc
	hdc = GetWindowDC(THIS.hOrigWindow)

	WITH THIS
		.GetWinRect
		.canvas_form = CREATEOBJECT("GdiCanvas", hdc, .winwidth, .winheight)
		.canvas_form.ClearCanvas
		.canvas_form.CopyFrom(m.hdc, 0, 0)
		.canvas_buffer = CREATEOBJECT("GdiCanvas", hdc, .winwidth, .winheight)
		= ReleaseDC(.hOrigWindow, m.hdc)
	ENDWITH

PROTECTED PROCEDURE CreateCoveringWindow
	LOCAL cClass, hParent, nCaptionHeight,;
		nFrameWidth, nFrameHeight, hRgnBase

	WITH THIS
		hParent = application.hWnd && _screen.HWnd
		cClass = .GetWinClass(m.hParent) && to be continued
		nCaptionHeight = GetSystemMetrics(SM_CYCAPTION)
		nFrameWidth = GetSystemMetrics(SM_CXFRAME)
		nFrameHeight = GetSystemMetrics(SM_CYFRAME)

		.cwinleft=.winleft-m.nFrameWidth
		.cwintop=.wintop-m.nFrameHeight-m.nCaptionHeight
		.cwinwidth=.winwidth+m.nFrameWidth*2
		.cwinheight=.winheight+m.nCaptionHeight+m.nFrameHeight*2

		.hCoverWindow = CreateWindowEx(BITOR(WS_EX_NOACTIVATE, WS_EX_LAYERED),;
			cClass, NULL, WS_VISIBLE, .cwinleft, .cwintop,;
			.cwinwidth, .cwinheight, hParent, 0,0,0)

		IF .hCoverWindow = 0
			RETURN .F.
		ENDIF

		* cut the caption and the frame off the covering window
		* by creating and applying a rectangular region
		hRgnBase = CreateRectRgn(nFrameWidth, nFrameHeight + nCaptionHeight,;
			.cwinwidth - nFrameWidth, .cwinheight - nFrameHeight)

		= SetWindowRgn(.hCoverWindow, m.hRgnBase, 1)
		= DeleteObject(m.hRgnBase)
		.hCoverDC = GetDC(.hCoverWindow)

		.ewinleft = .winleft
		.ewintop = .wintop
		.ewinwidth = .winwidth
		.ewinheight = .winheight
	ENDWITH

PROCEDURE DrawBackground
* draws the image of the original form on the covering window
* at the same time increasing its transparency and shrinking in size
	WITH THIS
		.fadingsteps = .fadingsteps + 1
		.alphachannel = .alphachannel - .fadingsteps * ALPHA_DECREASE_BY

		IF .alphachannel <= ALPHA_MIN_VALUE
			RETURN .F.
		ENDIF

		* set transparency for the covering window
		= SetLayeredWindowAttributes(.hCoverWindow, BRIGHT_WHITE,;
			.alphachannel, LWA_ALPHA+LWA_COLORKEY)

		* shrink the image drawn on the covering window
		.ewinwidth = .ewinwidth * DIMEN_DECREASE_RATIO
		.ewinheight = .ewinheight * DIMEN_DECREASE_RATIO
		.ewinleft = (.winwidth - .ewinwidth)/2
		.ewintop = (.winheight - .ewinheight)/2

		* draw the image of the original form on the buffer
		.canvas_buffer.ClearCanvas
		.canvas_form.CopyTo(.canvas_buffer.hdc, .ewinleft,;
			.ewintop, .ewinwidth, .ewinheight)

		* draw the image from the buffer on the covering window
		.canvas_buffer.CopyTo(.hCoverDC, 1, 1, .winwidth, .winheight)
	ENDWITH

PROTECTED PROCEDURE GetWinClass(hParent)
	LOCAL cClass, nSize
	cClass = REPLICATE(CHR(0), 250)
	nSize = RealGetWindowClass(hParent, @cClass, Len(cClass ))
RETURN STRTRAN(SUBSTR(cClass, 1, nSize), CHR(0),"")

PROTECTED PROCEDURE GetWinRect
	LOCAL cBuffer, nLeft, nTop, nRight, nBottom

	cBuffer = REPLICATE(CHR(0), 16)
	= GetWindowRect(THIS.hOrigWindow, @cBuffer)

	nTop = buf2dword(SUBSTR(cBuffer, 5,4))
	nRight  = buf2dword(SUBSTR(cBuffer, 9,4))
	nBottom = buf2dword(SUBSTR(cBuffer, 13,4))

	nLeft = buf2dword(SUBSTR(cBuffer, 1,4))
	IF nLeft > nRight
		nLeft = nLeft - DWORD_MAX_VALUE
	ENDIF
	IF nTop > nBottom
		nTop = nTop - DWORD_MAX_VALUE
	ENDIF

	WITH THIS
		.winleft = m.nLeft
		.wintop = m.nTop
		.winwidth = m.nRight - m.nLeft + 1
		.winheight = m.nBottom - m.nTop + 1
	ENDWITH

ENDDEFINE

DEFINE CLASS GdiCanvas As Session
* implements compatible device context
PROTECTED canvaswidth, canvasheight
	hdc=0
	hbitmap=0
	hbrush=0

PROCEDURE Init(hBaseDC, nWidth, nHeight)
	WITH THIS
		.canvaswidth = m.nWidth
		.canvasheight = m.nHeight
		.hdc = CreateCompatibleDC(m.hBaseDC)
		.hbitmap = CreateCompatibleBitmap(hBaseDC,;
			.canvaswidth, .canvasheight)
		= DeleteObject(SelectObject(.hdc, .hbitmap))
		.hbrush = CreateSolidBrush(BRIGHT_WHITE)
	ENDWITH

PROCEDURE Destroy
	= DeleteObject(THIS.hbrush)
	IF THIS.hbitmap <> 0
		= DeleteObject(THIS.hbitmap)
		THIS.hbitmap=0
	ENDIF
	IF THIS.hdc <> 0
		= DeleteDC(THIS.hdc)
		THIS.hdc=0
	ENDIF

PROCEDURE ClearCanvas
	LOCAL rect
	rect = num2dword(0) + num2dword(0) + num2dword(THIS.canvaswidth) +;
		num2dword(THIS.canvasheight)
	= FillRect(THIS.hdc, @rect, THIS.hbrush)

PROCEDURE CopyTo(hTargetDC, nLeft, nTop, nWidth, nHeight)
	WITH THIS
		= StretchBlt(m.hTargetDC, nLeft, nTop, nWidth, nHeight,;
			.hdc, 0, 0, .canvaswidth, .canvasheight, SRCCOPY)
	ENDWITH

PROCEDURE CopyFrom(hSourceDC, nLeft, nTop)
	WITH THIS
		= BitBlt(.hdc, 0,0, .canvaswidth, .canvasheight,;
			m.hSourceDC, 0,0, SRCCOPY)
	ENDWITH

ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(nValue)
#DEFINE m0 0x100
#DEFINE m1 0x10000
#DEFINE m2 0x1000000
	IF nValue < 0
		nValue = 0x100000000 + m.nValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(nValue/m2)
	b2 = Int((nValue - b3*m2)/m1)
	b1 = Int((nValue - b3*m2 - b2*m1)/m0)
	b0 = MOD(nValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CreateCompatibleBitmap](../libraries/gdi32/CreateCompatibleBitmap.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[CreateRectRgn](../libraries/gdi32/CreateRectRgn.md)  
[CreateSolidBrush](../libraries/gdi32/CreateSolidBrush.md)  
[CreateWindowEx](../libraries/user32/CreateWindowEx.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[DestroyWindow](../libraries/user32/DestroyWindow.md)  
[FillRect](../libraries/gdi32/FillRect.md)  
[GetDC](../libraries/user32/GetDC.md)  
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[RealGetWindowClass](../libraries/user32/RealGetWindowClass.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetLayeredWindowAttributes](../libraries/user32/SetLayeredWindowAttributes.md)  
[SetWindowLong](../libraries/user32/SetWindowLong.md)  
[SetWindowRgn](../libraries/user32/SetWindowRgn.md)  
[StretchBlt](../libraries/gdi32/StretchBlt.md)  
