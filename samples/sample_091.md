[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to copy the image of a form to the Clipboard using Bitmap API functions

## Before you begin:
This sample code shows how to copy the image of an active form to the Clipboard in CF_BITMAP format.  

There is a similar example using Bitmap API functions copying data in CF_ENHMETAFILE format:   
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](sample_404.md)  

Check other Bitmap API examples:  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Storing screen shot of a form to a BMP file](sample_187.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a bitmap file](sample_211.md)  
  
***  


## Code:
```foxpro  
#DEFINE CF_BITMAP 2	&& clipboard format
#DEFINE SRCCOPY 0xCC0020  && BitBlt raster operation code
DO declare

PRIVATE hWindow, lnLeft, lnTop, lnRight, lnBottom, lnWidth, lnHeight
*hWindow = GetActiveWindow()  && active window
hWindow = GetFocus()  && a window with keyboard focus
*hWindow = Application.hWnd
*hWindow = _screen.HWnd

* retrieving geometrical parameters of the window
STORE 0 TO lnLeft, lnTop, lnRight, lnBottom, lnWidth, lnHeight
= GetRect(@lnLeft, @lnTop, @lnRight, @lnBottom, @lnWidth, @lnHeight)

* and its device context
hdc = GetWindowDC(m.hWindow)

* creating compatible DC and BITMAP
hVdc = CreateCompatibleDC(hdc)
hBitmap = CreateCompatibleBitmap(hdc, lnWidth, lnHeight)
= SelectObject(hVdc, hBitmap)  && selecting created BITMAP into hVdc

* copying a rectangular area from HDC to hVdc
= BitBlt(hVdc, 0,0, lnWidth,lnHeight, hdc, 0,0, SRCCOPY)

* opening clipboard and placing bitmap data on it
= OpenClipboard(m.hWindow)
= EmptyClipboard()
= SetClipboardData(CF_BITMAP, m.hBitmap)
= CloseClipboard()  && clipboard not closed may affect other apps

* releasing GDI objects
= DeleteObject(m.hBitmap)
= DeleteDC(m.hVdc)
= ReleaseDC(m.hWindow, m.hdc)
* end of main

PROCEDURE declare
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hWindow, STRING @lpRect
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWindow, INTEGER hdc
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER EmptyClipboard  IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hWindow
	DECLARE INTEGER SetClipboardData IN user32 INTEGER wFormat, INTEGER hMem

	DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
		INTEGER hdc, INTEGER nWidth, INTEGER nHeight

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

PROCEDURE GetRect(lnLeft, lnTop, lnRight, lnBottom, lnWidth, lnHeight)
    LOCAL lpRect
    lpRect = REPLICATE(CHR(0), 16)
    = GetWindowRect(m.hWindow, @lpRect)

    lnLeft = buf2dword(SUBSTR(lpRect,  1,4))
    lnTop = buf2dword(SUBSTR(lpRect,  5,4))
    lnRight = buf2dword(SUBSTR(lpRect,  9,4))
    lnBottom = buf2dword(SUBSTR(lpRect, 13,4))
	lnWidth = lnRight - lnLeft
	lnHeight = lnBottom - lnTop

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 0x100 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 0x10000 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 0x1000000  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[CreateCompatibleBitmap](../libraries/gdi32/CreateCompatibleBitmap.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EmptyClipboard](../libraries/user32/EmptyClipboard.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetClipboardData](../libraries/user32/SetClipboardData.md)  

## Comment:
The GetFocus function retrieves the handle to the window that has the keyboard focus.  
  
If you call this procedure from a form you will get an image of this form on  the clipboard.  
  
Being called from the main VFP window, with no other forms running, this procedures copies to the clipboard the whole main window itself.  
  
* * *  
An article [How To Copy the Screen or Active Window to the Clipboard from Visual Basic](https://support.microsoft.com/en-us/help/240653/how-to-copy-the-screen-or-active-window-to-the-clipboard-from-visual-b) published on Microsoft Help and Support page describes a different approach -- the picture of the whole screen is sent to the clipboard by virtually pressing (through the keybd_event call) PrtScr key.  
  
***  

