[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Bitmap Class for Visual FoxPro application

## Before you begin:
This class loads bitmap from a disk file providing some basic functionality, which includes drawing the bitmap on a device context and copying it to the Windows Clipboard.  

See also:

* [Storing screen shot of a form to bitmap file](sample_187.md)  
* [GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF) ](sample_454.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a bitmap file](sample_211.md)  

  
***  


## Code:
```foxpro  
LOCAL obj

* provide valid bitmap file
obj = CreateObject("Tbitmap", "myfile.bmp")

IF TYPE("obj") = "O"
	* bitmap main properties available
*	? "Bitmap handle:", obj.hBitmap
*	? "Width:", obj.bmpwidth
*	? "Height:", obj.bmpheight
	
	* drawing the bitmap as is
*	obj.RenderToDC (0, 100,300, 0,0)

	* scaling 25%
	obj.RenderToDC (0, 100,300, obj.bmpwidth/4, obj.bmpheight/4)
	
	* copying to the Clipboard
	obj.RenderToClip
ENDIF

DEFINE CLASS Tbitmap As Custom
	hBitmap=0
	hDC=0
	filename=""
	bmpwidth=0
	bmpheight=0

PROCEDURE Init (lcFilename)
	THIS.decl
	IF Not FILE(lcFilename) Or NOT THIS.LoadBitmap(lcFilename)
		RETURN .F.
	ENDIF

PROCEDURE Destroy
	THIS.ReleaseBitmap

PROTECTED PROCEDURE ReleaseBitmap
	= DeleteObject(THIS.hBitmap)
	= DeleteDC(THIS.hDC)

PROTECTED PROCEDURE LoadBitmap (lcFilename)
#DEFINE IMAGE_BITMAP     0
#DEFINE LR_LOADFROMFILE  16
#DEFINE BITMAP_STRU_SIZE   24

	THIS.filename = FULLPATH(lcFilename)
	THIS.hBitmap = LoadImage(0, lcFilename, IMAGE_BITMAP,;
		0,0, LR_LOADFROMFILE)

	IF THIS.hBitmap = 0
		RETURN .F.
	ENDIF
	
	LOCAL hWindow, hDC, lnOrigWidth, lnOrigHeight, lcBuffer
	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	STORE 0 TO lnOrigWidth, lnOrigHeight
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)

	IF GetObjectA(THIS.hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		lnOrigWidth = THIS.buf2dword (SUBSTR(lcBuffer, 5,4))
		lnOrigHeight = THIS.buf2dword (SUBSTR(lcBuffer, 9,4))
	ENDIF

	THIS.bmpwidth = lnOrigWidth
	THIS.bmpheight = lnOrigHeight

	THIS.hDC = CreateCompatibleDC(m.hDC)
	= DeleteObject(SelectObject(THIS.hDC, THIS.hBitmap))
	= ReleaseDC(hWindow, hDC)

PROCEDURE RenderToDC (hDC, lnLeft, lnTop, lnWidth, lnHeight)
* draw the bitmap on a given device context
#DEFINE SRCCOPY  13369376
	LOCAL hWindow
	IF TYPE("m.hDC") <> "N" Or m.hDC=0
	* use VFP main window as a target if no DC is provided
		 hWindow = GetActiveWindow()
		 hDC = GetWindowDC(hWindow)
	ELSE
		hWindow = 0
	ENDIF

	lnWidth = Iif(TYPE("lnWidth")<>"N" Or lnWidth=0, THIS.bmpwidth, lnWidth)
	lnHeight = Iif(TYPE("lnHeight")<>"N" Or lnHeight=0, THIS.bmpheight, lnHeight)

	= StretchBlt (m.hDC, lnLeft, lnTop, lnWidth, lnHeight,;
		THIS.hDC, 0,0, THIS.bmpwidth, THIS.bmpheight,;
		SRCCOPY)

	IF hWindow <> 0
		= ReleaseDC(hWindow, hDC)
	ENDIF

PROCEDURE RenderToClip
* copy the bitmap to the Windows Clipboard
#DEFINE CF_BITMAP    2
	LOCAL hWindow, hDC
	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	= OpenClipboard(hWindow)
	= EmptyClipboard()
	= SetClipboardData (CF_BITMAP, THIS.hBitmap)
	= CloseClipboard()
	= ReleaseDC(hWindow, hDC)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER EmptyClipboard  IN user32
	DECLARE INTEGER SetClipboardData IN user32 INTEGER wFormat, INTEGER hMem

	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject

	DECLARE INTEGER LoadImage IN user32;
		INTEGER hinst, STRING lpszName, INTEGER uType,;
		INTEGER cxDesired, INTEGER cyDesired, INTEGER fuLoad

	DECLARE INTEGER StretchBlt IN gdi32;
		INTEGER hdcDest, INTEGER nXOriginDest, INTEGER nYOriginDest,;
		INTEGER nWidthDest, INTEGER nHeightDest,;
		INTEGER hdcSrc, INTEGER nXOriginSrc, INTEGER nYOriginSrc,;
		INTEGER nWidthSrc, INTEGER nHeightSrc, INTEGER dwRop
ENDDEFINE  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EmptyClipboard](../libraries/user32/EmptyClipboard.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[LoadBitmap](../libraries/user32/LoadBitmap.md)  
[LoadImage](../libraries/user32/LoadImage.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetClipboardData](../libraries/user32/SetClipboardData.md)  
[StretchBlt](../libraries/gdi32/StretchBlt.md)  

## Comment:
More functionality like printing and saving the scaled image to another file can be added to this class in a short time from code examples already included in this reference.  
  
The native FoxPro function **LoadPicture** returns valid bitmap handle when applied to bitmap files (GIF and JPEG files also):  
  
```foxpro
obj = LoadPicture("mybitmap.bmp")  
? "Bitmap handle:", obj.handle
```

Actually LoadPicture() returns an object with properties *Handle, Height, hPal, Type,*and *Width*.  
  
Also it has a single method *Render* called with parameters (VB syntax)
```vbnet
hdc As Long, x As Long, y As Long,   
cx As Long, cy As Long,  
xSrc As OLE_XPOS_HIMETRIC, ySrc As OLE_YPOS_HIMETRIC,  
cxSrc As OLE_XSIZE_HIMETRIC, cySrc As OLE_YSIZE_HIMETRIC,  
prcWBounds As Any
```
  
  
  
***  

