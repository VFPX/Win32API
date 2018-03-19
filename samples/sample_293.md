[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Displaying bitmap using the AlphaBlend function

## Before you begin:
The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.  

See also:

* [Bitmap Class for Visual FoxPro application](sample_295.md)  
* [Semi-transparent Form](sample_453.md)  
* [Form Magnifier](sample_414.md)  
* [GDI+: Color Transparency](sample_549.md)  
  
***  


## Code:
```foxpro  
#DEFINE LR_LOADFROMFILE 16
#DEFINE AC_SRC_OVER 0
#DEFINE AC_SRC_ALPHA 1
#DEFINE AC_SRC_NO_ALPHA 2
#DEFINE IMAGE_BITMAP 0
#DEFINE SRCCOPY 0xCC0020
#DEFINE BITMAP_STRU_SIZE 24

DO declare

LOCAL lcBitmap
*lcBitmap = "C:\WinNT\system32\setup.bmp"
lcBitmap = "C:\Windows\Forest.bmp"
= LoadAndShowBitmap(lcBitmap, LR_LOADFROMFILE, 20,100)
* end of main

PROCEDURE LoadAndShowBitmap(lcBitmap, lnLoadOptions, lnX,lnY)
	LOCAL hBitmap
	hBitmap = LoadImage(0, lcBitmap, IMAGE_BITMAP,;
		0,0, lnLoadOptions)

	IF hBitmap <> 0
		= ShowBitmap(hBitmap, lnX,lnY)
		= DeleteObject(hBitmap)
	ELSE
		= MESSAGEBOX(lcBitmap + Chr(13) + Chr(13) +;
			"Check if this is a valid bitmap file.",;
			32, " Unable to load an image from file")
	ENDIF

PROCEDURE ShowBitmap(hBitmap, lnX, lnY)
*|typedef struct _BLENDFUNCTION {
*|  BYTE     BlendOp;
*|  BYTE     BlendFlags;
*|  BYTE     SourceConstantAlpha;
*|  BYTE     AlphaFormat;
*|}BLENDFUNCTION, *PBLENDFUNCTION, *LPBLENDFUNCTION;

	LOCAL hWindow, hDC, hMemDC, lnWidth, lnHeight
	STORE 0 TO lnWidth, lnHeight
	= GetBitmapSize(hBitmap, @lnWidth, @lnHeight)

	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	
	hMemDC = CreateCompatibleDC(hDC)
	= SelectObject(hMemDC, hBitmap)

	LOCAL lnAlphaBlend, lnResult,;
		lnBlendOp, lnBlendFlags, lnSrcConstAlpha, lnAlphaFormat

	lnBlendOp = AC_SRC_OVER  && always
	lnBlendFlags = 0         && always
	lnSrcConstAlpha = 48     && intensity, up to 255
	lnAlphaFormat = 0        && try AC_SRC_ALPHA on non-white background

	* assembling the BLENDFUNCTION structure
	lnAlphaBlend = lnBlendOp +;
		BitLShift(lnBlendFlags, 8) +;
		BitLShift(lnSrcConstAlpha, 16) +;
		BitLShift(lnAlphaFormat, 24)

	lnResult = AlphaBlend(hDC, lnX,lnY, lnWidth,lnHeight,;
		hMemDC, 0,0, lnWidth,lnHeight,;
		lnAlphaBlend)

	IF lnResult = 0
	*  6 = The handle is invalid
	* 87 = The parameter is incorrect
		? "Error:", GetLastError()
	ENDIF

	= DeleteDC(hMemDC)
	= ReleaseDC(hWindow, hDc)
RETURN .T.

FUNCTION GetBitmapSize(hBitmap, lnWidth, lnHeight)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)

	IF GetObjectA(hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		lnWidth  = buf2dword(SUBSTR(lcBuffer, 5,4))
		lnHeight = buf2dword(SUBSTR(lcBuffer, 9,4))
   	ENDIF

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWindow, INTEGER dc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject

	DECLARE INTEGER LoadImage IN user32;
		INTEGER hinst, STRING lpszName, INTEGER uType,;
		INTEGER cxDesired, INTEGER cyDesired, INTEGER fuLoad

	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	DECLARE INTEGER AlphaBlend IN Msimg32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER nWidthSrc,;
		INTEGER nHeightSrc, INTEGER blendFunction

	DECLARE INTEGER GetLastError IN kernel32  
```  
***  


## Listed functions:
[AlphaBlend](../libraries/msimg32/AlphaBlend.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[LoadImage](../libraries/user32/LoadImage.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
