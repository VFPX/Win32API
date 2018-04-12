[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Splash Screen for the VFP application

## Before you begin:
The splash screen object hides your VFP application window, disables user input and displays series of text messages while some initialization or maintenance procedures running on the background.  

Download this bitmap [splash.bmp](../images/splash.bmp) or test this example with any other valid bitmap file. 

![](../images/splash.bmp)
  
***  


## Code:
```foxpro  
LOCAL obj As AppSplash
obj = CreateObject("AppSplash", "splash.bmp")

IF TYPE("obj") = "O"
	obj.ShowSplash
	obj=NULL
	_screen.WindowState = 2
ENDIF
* end of main

* a subclass is created to add user-defined functionality
DEFINE CLASS AppSplash As Tsplash
PROCEDURE RunUDFs
* simulating application activity
* in real situation replace INKEYs with your procedures
	THIS.DisplayText ("Connecting to news server...", 20,20)
	= INKEY(1)
	THIS.DisplayText ("Retrieving weather forecast...", 20,20)
	= INKEY(2)
	THIS.DisplayText ("Testing data integrity...", 20,20)
	= INKEY(1)
	
	FOR ii=1 TO 2
		THIS.DisplayText ("Reindexing...", 20,20)
		= INKEY(1)
		THIS.DisplayText ("Packing...", 20,20)
		= INKEY(2)
	ENDFOR

	THIS.DisplayText ("Please wait...", 20,20)
	= INKEY(3)
	THIS.DisplayText ("Done!", 20,20)
	= INKEY(1)
RETURN
ENDDEFINE

DEFINE CLASS Tsplash As Custom
	hWindow=0  && splash window handle
	hDC=0      && splash window device context
	hMemDC=0   && memory device context
	hBitmap=0  && bitmap handle
	hFont=0    && font handle
	width=0    && bitmap width
	height=0   && bitmap height

PROCEDURE Init(lcBitmap)
	THIS.declare

	If Not THIS.LoadBitmap(lcBitmap)
		RETURN .F.
	ENDIF
	
	* maximizing application window
	* before creating a child window
	_screen.WindowState = 2

	IF Not THIS.CreateWindow()
		THIS.ClearObjects
		RETURN .F.
	ENDIF

	* blocking keyboard and mouse input
	= BlockInput(1)
RETURN
	
PROCEDURE Destroy
	THIS.ClearObjects
	_screen.WindowState = 2
	= BlockInput(0)  && enabling user input

PROCEDURE ClearObjects
	= DeleteDC(THIS.hMemDC)
	= DeleteObject(THIS.hFont)
	= DeleteObject(THIS.hBitmap)
	= ReleaseDC(THIS.hWindow, THIS.hDC)
	= DestroyWindow(THIS.hWindow)

PROCEDURE LoadBitmap(lcBitmap)
#DEFINE IMAGE_BITMAP     0
#DEFINE LR_LOADFROMFILE  16

	IF Not FILE(lcBitmap)
		RETURN
	ENDIF

	THIS.hBitmap = LoadImage (0, lcBitmap,;
		IMAGE_BITMAP, 0,0, LR_LOADFROMFILE)

	IF THIS.hBitmap <> 0
		LOCAL lnWidth, lnHeight
		STORE 0 TO lnWidth, lnHeight
		= GetBitmapSize (THIS.hBitmap, @lnWidth, @lnHeight)

		THIS.width = lnWidth
		THIS.height = lnHeight
	ENDIF
RETURN (THIS.hBitmap<>0)

PROCEDURE CreateWindow
#DEFINE WS_EX_TOPMOST       8
#DEFINE FW_NORMAL           400
#DEFINE ANSI_CHARSET        0
#DEFINE OUT_OUTLINE_PRECIS  8
#DEFINE CLIP_STROKE_PRECIS  2
#DEFINE PROOF_QUALITY       2
#DEFINE DEFAULT_PITCH       0
#DEFINE TRANSPARENT         1

	LOCAL hParent, lcClass, lnSize
	hParent = GetActiveWindow()
	lcClass = SPACE(250)
	lnSize = RealGetWindowClass(hParent, @lcClass , Len(lcClass ))
	lcClass = STRTRAN(SUBSTR(lcClass, 1,lnSize), Chr(0),"")

	THIS.hWindow = CreateWindowEx (WS_EX_TOPMOST, lcClass, "",;
		0, 0, 0, THIS.width, THIS.height, hParent, 0, 0, 0)
	THIS.hDC = GetWindowDC(THIS.hWindow)

	THIS.hMemDC = CreateCompatibleDC(THIS.hDC)
	= DeleteObject(SelectObject(THIS.hMemDC, THIS.hBitmap))

	THIS.hFont = CreateFont(16,0, 0,0, FW_NORMAL, 0,0,0,;
		ANSI_CHARSET, OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
		PROOF_QUALITY, DEFAULT_PITCH, "Verdana")

	= DeleteObject (SelectObject(THIS.hDC, THIS.hFont))
	= SetTextColor(THIS.hDC, RGB(40,40,40))
	= SetBkMode(THIS.hDC, TRANSPARENT)
RETURN (THIS.hWindow<>0)

PROCEDURE DisplayText (lcText, lnX, lnY)
	THIS.DisplayBitmap  && redraw bitmap
	= TextOut (THIS.hDC, lnX, lnY, lcText, Len(lcText))
RETURN

PROCEDURE DisplayBitmap
#DEFINE SRCCOPY  13369376
	= BitBlt (THIS.hDC, 0,0, THIS.width,THIS.height,;
		THIS.hMemDC, 0,0, SRCCOPY)
RETURN

PROCEDURE ShowSplash
#DEFINE SM_CXSCREEN  0
#DEFINE SM_CYSCREEN  1
#DEFINE SW_NORMAL    1

	LOCAL lnScrWidth, lnScrHeight
	lnScrWidth = GetSystemMetrics(SM_CXSCREEN)
	lnScrHeight = GetSystemMetrics(SM_CYSCREEN)

	* centering splash window, it is still hidden
	= MoveWindow (THIS.hWindow,;
		(lnScrWidth-THIS.Width)/2, (lnScrHeight-THIS.height)/2,;
		THIS.Width, THIS.height, 1)
		
	_screen.WindowState = 1  && minimizing application window
	= ShowWindowA (THIS.hWindow, SW_NORMAL)
	THIS.DisplayBitmap
	THIS.RunUDFs  && starting user-defined procedures
RETURN

PROCEDURE RunUDFs
* a virtual method provides user-defined functionality
* for sub-classes of this class
RETURN

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER DestroyWindow IN user32 INTEGER hWnd
	DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER dc
	DECLARE INTEGER SetTextColor IN gdi32 INTEGER hdc, INTEGER crColor
	DECLARE INTEGER SetBkMode IN gdi32 INTEGER hdc, INTEGER iBkMode
	DECLARE INTEGER BlockInput IN user32 INTEGER fBlockIt

	DECLARE INTEGER ShowWindow IN user32 AS ShowWindowA;
		INTEGER hwnd, INTEGER nCmdShow

	DECLARE INTEGER LoadImage IN user32;
		INTEGER hinst, STRING lpszName, INTEGER uType,;
		INTEGER cxDesired, INTEGER cyDesired, INTEGER fuLoad

	DECLARE INTEGER RealGetWindowClass IN user32;
		INTEGER hwnd, STRING @pszType, INTEGER cchType

	DECLARE INTEGER CreateWindowEx IN user32;
		INTEGER dwExStyle, STRING lpClassName, STRING lpWindowName,;
		INTEGER dwStyle, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hWndParent,;
		INTEGER hMenu, INTEGER hInstance, INTEGER lpParam

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

	DECLARE INTEGER MoveWindow IN user32;
		INTEGER hWnd, INTEGER X, INTEGER Y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER bRepaint

	DECLARE INTEGER CreateFont IN gdi32;
		INTEGER nHeight, INTEGER nWidth,;
		INTEGER nEscapement, INTEGER nOrientation,;
		INTEGER fnWeight, INTEGER fdwItalic,;
		INTEGER fdwUnderline, INTEGER fdwStrikeOut,;
		INTEGER fdwCharSet, INTEGER fdwOutputPrecision,;
		INTEGER fdwClipPrecision, INTEGER fdwQuality,;
		INTEGER fdwPitchAndFamily, STRING lpszFace

	DECLARE INTEGER TextOut IN gdi32;
		INTEGER hdc, INTEGER x, INTEGER y,;
		STRING  lpString, INTEGER nCount
ENDDEFINE

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION GetBitmapSize (hBitmap, lnWidth, lnHeight)
#DEFINE BITMAP_STRU_SIZE   24
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)

	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	IF GetObjectA(hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		lnWidth  = buf2dword (SUBSTR(lcBuffer, 5,4))
		lnHeight = buf2dword (SUBSTR(lcBuffer, 9,4))
   	ENDIF  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[BlockInput](../libraries/user32/BlockInput.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[CreateFont](../libraries/gdi32/CreateFont.md)  
[CreateWindowEx](../libraries/user32/CreateWindowEx.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[DestroyWindow](../libraries/user32/DestroyWindow.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[LoadImage](../libraries/user32/LoadImage.md)  
[MoveWindow](../libraries/user32/MoveWindow.md)  
[RealGetWindowClass](../libraries/user32/RealGetWindowClass.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetBkMode](../libraries/gdi32/SetBkMode.md)  
[SetTextColor](../libraries/gdi32/SetTextColor.md)  
[ShowWindow](../libraries/user32/ShowWindow.md)  
[TextOut](../libraries/gdi32/TextOut.md)  
