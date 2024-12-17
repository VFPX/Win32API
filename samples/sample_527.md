[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to make a VFP form fading out when released (GDI+ version)

## Short description:
When a VFP form is released, usually it disappears immediately. Wouldn't it be nice to have the form slowly (or less slowly) fading out?

An obvious way of doing that is covering the form with another window, which holds the image of the original form. Once covered, the original form disappears. After that the covering window gradually changes its opacity (alpha channel) from opaque (255) to completely transparent (0).  
***  


## Before you begin:
When a VFP form is released, usually it disappears immediately. Wouldn't it be nice to have a form slowly (or less slowly) fading out?  

An obvious way of doing that is covering the form with another window, which holds the image of the original form. Once covered, the original form disappears. After that the covering window gradually changes its opacity (alpha channel) from opaque (255) to completely transparent (0).  

The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file. GDI+ routines are used to save the image of the original form then drawing it on the covering window.   

See also:

* [How to make a VFP form fading out when released (GDI version)](sample_528.md)  
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
	Caption="Test form"
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
#DEFINE WS_DISABLED 0x08000000
#DEFINE WS_EX_LAYERED 0x80000
#DEFINE WS_EX_NOACTIVATE 0x8000000
#DEFINE SM_CYCAPTION 4
#DEFINE SM_CXFRAME 32
#DEFINE SM_CYFRAME 33
#DEFINE LWA_ALPHA 2
#DEFINE GWL_EXSTYLE -20
#DEFINE GWL_STYLE -16
#DEFINE TIMER_INTERVAL 10
#DEFINE ALPHA_MIN_VALUE 4
#DEFINE ALPHA_DECREASE_BY 4

	Visible=.F.
	fadingwindows=NULL
	gdiplus=NULL
	ADD OBJECT Timer1 As Timer

PROCEDURE Init
	SET PROCEDURE TO gdiplus ADDITIVE
	THIS.gdiplus = CREATEOBJECT("gdiplusinit")
	THIS.declare
	THIS.fadingwindows = CREATEOBJECT("Collection")

PROCEDURE Destroy
	THIS.Timer1.Interval=0
	IF VARTYPE(THIS.fadingwindows) = "O"
		DO WHILE THIS.fadingwindows.Count > 0
			THIS.fadingwindows.Remove(1)
		ENDDO
	ENDIF
	THIS.gdiplus=NULL

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
		IF fw.DrawBackground <= ALPHA_MIN_VALUE
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
	DECLARE INTEGER IsWindow IN user32 INTEGER hWindow
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex
	DECLARE INTEGER GetWindowLong IN user32 INTEGER hWindow, INTEGER nIndex

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

ENDDEFINE

DEFINE CLASS FadingWindow As Session
	hOrigWindow=0 && HWND of the original form
	hCoverWindow=0 && HWND of the covering window
	* coordinates of the original form
	winleft=0
	wintop=0
	winwidth=0
	winheight=0
	* coordinates of the covering window
	cwinleft=0
	cwintop=0
	cwinwidth=0
	cwinheight=0

	origbmp=NULL  && gdi+ bitmap storing the form's image
	hgraphics=NULL && gdi+ graphics object
	alphachannel=0xff  && alpha channel value

PROCEDURE Init(hOrigWindow As Integer)
	THIS.hOrigWindow = m.hOrigWindow
	IF IsWindow(THIS.hOrigWindow) = 0
		RETURN .F.
	ENDIF
	THIS.CopyWinImage
	THIS.CreateCoveringWindow

PROCEDURE Destroy
	IF NOT ISNULL(THIS.hGraphics)
		THIS.hGraphics=NULL
	ENDIF
	THIS.DestroyCoverWindow
	THIS.origbmp=NULL

PROCEDURE DestroyCoverWindow
	IF THIS.hCoverWindow <> 0
		IF IsWindow(THIS.hCoverWindow) <> 0
			= DestroyWindow(THIS.hCoverWindow)
		ENDIF
		THIS.hCoverWindow=0
	ENDIF

PROTECTED PROCEDURE CopyWinImage
* copies the image of the original form to gdi+ bitmap
	LOCAL hdc
	hdc = GetWindowDC(THIS.hOrigWindow)

	WITH THIS
		.GetWinRect
		.origbmp = CREATEOBJECT("gdibitmap", .winwidth, .winheight)
		WITH .origbmp
			.graphics.GetDC
			= BitBlt(.graphics.hdc, 0,0, .imgwidth, .imgheight,;
				m.hdc, 0,0, SRCCOPY)
			.graphics.ReleaseDC
		ENDWITH
		= ReleaseDC(.hOrigWindow, m.hdc)
	ENDWITH

PROTECTED PROCEDURE CreateCoveringWindow
	LOCAL nExStyle, cClass, nStyle, hParent, nCaptionHeight,;
		nFrameWidth, nFrameHeight, x1, y1, x2, y2, hRgnBase

	hParent = application.hWnd && _screen.HWnd
	cClass = THIS.GetWinClass(m.hParent) && to be continued
	nStyle = WS_VISIBLE
	nExStyle = BITOR(WS_EX_NOACTIVATE, WS_EX_LAYERED)

	nCaptionHeight = GetSystemMetrics(SM_CYCAPTION)
	nFrameWidth = GetSystemMetrics(SM_CXFRAME)
	nFrameHeight = GetSystemMetrics(SM_CYFRAME)

	THIS.cwinleft=THIS.winleft-m.nFrameWidth
	THIS.cwintop=THIS.wintop-m.nFrameHeight-m.nCaptionHeight
	THIS.cwinwidth=THIS.winwidth+m.nFrameWidth*2
	THIS.cwinheight=THIS.winheight+m.nCaptionHeight+m.nFrameHeight*2

	THIS.hCoverWindow = CreateWindowEx(nExStyle, cClass, NULL, nStyle,;
		THIS.cwinleft, THIS.cwintop, THIS.cwinwidth, THIS.cwinheight,;
		hParent, 0,0,0)

	IF THIS.hCoverWindow = 0
		RETURN .F.
	ENDIF

	* cut the caption and the frame off the covering window
	* by creating and applying a rectangular frame
	x1 = nFrameWidth
	y1 = nFrameHeight+nCaptionHeight
	x2 = THIS.cwinwidth-nFrameWidth
	y2 = THIS.cwinheight-nFrameHeight

	hRgnBase = CreateRectRgn(x1, y1, x2, y2)
	= SetWindowRgn(THIS.hCoverWindow, m.hRgnBase, 1)
	= DeleteObject(m.hRgnBase)

	* use HWND of the covering window for creating
	* GDI+ graphics object
	THIS.hGraphics = CREATEOBJECT("graphics", THIS.hCoverWindow)

PROCEDURE DrawBackground
* draws the image of the original form on the covering window
* at the same time increasing its transparency
	IF THIS.alphachannel > ALPHA_MIN_VALUE
		THIS.alphachannel = THIS.alphachannel - ALPHA_DECREASE_BY
	ENDIF
	= SetLayeredWindowAttributes(THIS.hCoverWindow, 0,;
		THIS.alphachannel, LWA_ALPHA)
	THIS.hGraphics.drawimage(THIS.origbmp,;
		1, 1, THIS.winwidth, THIS.winheight)
RETURN THIS.alphachannel

PROTECTED PROCEDURE GetWinClass(hParent)
	LOCAL cClass, nSize
	cClass = REPLICATE(CHR(0), 250)
	nSize = RealGetWindowClass(hParent, @cClass , Len(cClass ))
RETURN STRTRAN(SUBSTR(cClass, 1, nSize), CHR(0),"")

PROTECTED PROCEDURE GetWinRect
	LOCAL oRect As Rect, cBuffer
	oRect = CREATEOBJECT("Rect", 0,0,0,0)
	cBuffer = oRect.ToString()
	= GetWindowRect(THIS.hOrigWindow, @cBuffer)
	oRect.FromString1(m.cBuffer)
	
	WITH THIS
		.winleft = oRect.rleft
		.wintop = oRect.rtop
		.winwidth = oRect.rwidth
		.winheight = oRect.rheight
	ENDWITH

ENDDEFINE  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CreateRectRgn](../libraries/gdi32/CreateRectRgn.md)  
[CreateWindowEx](../libraries/user32/CreateWindowEx.md)  
[DestroyWindow](../libraries/user32/DestroyWindow.md)  
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[RealGetWindowClass](../libraries/user32/RealGetWindowClass.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SetLayeredWindowAttributes](../libraries/user32/SetLayeredWindowAttributes.md)  
[SetWindowLong](../libraries/user32/SetWindowLong.md)  
[SetWindowRgn](../libraries/user32/SetWindowRgn.md)  

## Comment:
So the succession of events should be as follows:  
  
1. form's Destroy event occurs  
1. form's image is copied into a memory object (within the Destroy, the form and all controls are still visible, though some doubts exist about PageFrame control and ActiveX controls)  
1. a cover window is created and placed exactly on the same spot where the original VFP form is  
1. a timer is turned on and gradually changes the opacity of the covering window from 255 to 0By the first tick of the timer the original form does not exist anymore, the Destroy has completed its job.   
  
Certainly, the timer and an object responsible for performing steps 2 to 4 must reside outside of the form. That probably can be a master form or _SCREEN container.  
  
This approach works with all VFP forms, with top-level as well as with child ones. Here is a code that has to be called in the form's Destroy event

```foxpro
IF VARTYPE(_screen.FormFader1) <> "O"  
	_screen.AddObject("FormFader1", "FormFader")  
ENDIF  
_screen.FormFader1.FadeWindow(ThisForm)
```
  
At the moment when the covering window appears and the original form disappears, the former stays blank for a very small fraction of time. It is barely noticeable, but is still an issue I will be working on.  
  
Links to similar solutions:  
* <a href="http://www.ml-consult.co.uk/foxst-40.htm">Add a fading effect to your forms</a> by <a href="http://fox.wikis.com/wc.dll?Wiki~MikeLewis~People">Mike Lewis</a>  
* [How to create a fading .Net form](https://www.codeproject.com/Articles/4122/How-to-create-a-fading-form) on The Code Project 
  
***  

