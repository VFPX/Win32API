[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window

## Before you begin:
Make sure that the source file is a valid BMP file.  

Check more examples:  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing screen shot of a form to a BMP file](sample_187.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [How to print a BMP file](sample_211.md)  

  
***  


## Code:
```foxpro  
DO decl

#DEFINE LR_MONOCHROME          1
#DEFINE LR_LOADFROMFILE       16
#DEFINE LR_LOADTRANSPARENT    32
#DEFINE LR_VGACOLOR          128
#DEFINE LR_LOADMAP3DCOLORS  4096

	LOCAL lcBitmap
*	lcBitmap = "c:\WinNT\Fiddle Head.bmp"
	lcBitmap = "c:\Windows\Metal Links.bmp"
	
	= LoadAndShowBitmap (lcBitmap,;
		LR_LOADFROMFILE, 20,100)

	= LoadAndShowBitmap (lcBitmap,;
		LR_LOADFROMFILE+LR_MONOCHROME, 320,100)

	= LoadAndShowBitmap (lcBitmap,;
		LR_LOADFROMFILE+LR_VGACOLOR, 620,100)

PROCEDURE  LoadAndShowBitmap (lcBitmap, lnLoadOptions, lnX,lnY)
#DEFINE IMAGE_BITMAP  0
	LOCAL hBitmap

	hBitmap = LoadImage (0, lcBitmap, IMAGE_BITMAP,;
		0,0, lnLoadOptions)

	IF hBitmap <> 0
		= ShowBitmap (hBitmap, lnX,lnY)
		= DeleteObject (hBitmap)
	ELSE
	* unable to load an image from the file
	ENDIF

PROCEDURE  ShowBitmap (hBitmap, lnX, lnY)
#DEFINE SRCCOPY  13369376
	LOCAL hWnd, hDC, hMemDC, lnWidth, lnHeight

	STORE 0 TO lnWidth, lnHeight
	= GetBitmapSize (hBitmap, @lnWidth, @lnHeight)

	hWnd = GetActiveWindow()
	hDC = GetWindowDC (hWnd)
	
	hMemDC = CreateCompatibleDC(hDC)
	= SelectObject (hMemDC, hBitmap)

	= BitBlt (hDC, lnX,lnY, lnWidth,lnHeight,;
		hMemDC, 0,0, SRCCOPY)

	= DeleteDC(hMemDC)
	= ReleaseDC (hWnd, hDc)
RETURN .T.
	
FUNCTION  GetBitmapSize (hBitmap, lnWidth, lnHeight)
#DEFINE BITMAP_STRU_SIZE   24
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)

	IF GetObjectA(hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		lnWidth  = buf2dword (SUBSTR(lcBuffer, 5,4))
		lnHeight = buf2dword (SUBSTR(lcBuffer, 9,4))
   	ENDIF

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER dc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject

	DECLARE INTEGER LoadImage IN user32;
		INTEGER hinst, STRING lpszName, INTEGER uType,;
		INTEGER cxDesired, INTEGER cyDesired, INTEGER fuLoad

	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[LoadImage](../libraries/user32/LoadImage.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  

## Comment:
The LoadImage function, being supplied with a valid bitmap file name, loads this file into the corresponding Bitmap structures and returns a Bitmap handle.   
  
After that the handle can be used for displaying this Bitmap on various devices (the display, the available printers etc.) as well as for manipulating with its data using other Gdi32 functions.  
  
With little changes this code can be used for printing bitmap files.  
  
Notice that the image displayed on the main VFP form is not  "fixed", as it is when the _SCREEN property used.  
  
***  

