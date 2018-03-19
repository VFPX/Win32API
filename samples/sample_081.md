[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Placing an arbitrary rectangular area of main VFP window on the Clipboard

## Code:
```foxpro  
LPARAMETERS  lnLeft, lnTop, lnRight, lnBottom

#DEFINE CF_BITMAP  2	     && clipboard format
#DEFINE SRCCOPY    13369376  && BitBlt raster operation code

DO decl

* width and height of the rectangular area
lnWidth = lnRight - lnLeft + 1
lnHeight = lnBottom - lnTop + 1

* retrieving HWND and DC for the main VFP window
hwnd = GetActiveWindow()

* try both HDC values and note the difference
hdc = GetWindowDC (hwnd)  && device context of the whole window
*hdc = GetDC (hwnd)	&& device context of the client area
	
* creating compatible DC and BITMAP
hVdc = CreateCompatibleDC (hdc)
hBitmap = CreateCompatibleBitmap (hdc, lnWidth, lnHeight)
= SelectObject (hVdc, hBitmap)  && insert created BITMAP into hVdc

* copying a rectangular area from HDC to hVdc
= BitBlt (hVdc, 0,0, lnWidth,lnHeight,;
	hdc, lnLeft,lnTop, SRCCOPY)

* opening clipboard and place bitmap data into it
= OpenClipboard (hwnd)
= EmptyClipboard()

lnResult = SetClipboardData (CF_BITMAP, hBitmap)
IF lnResult <> 0
* Done! See the fragment appeared in Clipboard viewer
ELSE
	? "Error code: "
	?? GetLastError()
ENDIF

* closing the clipboard -- important
= CloseClipboard()

* releasing system resources
= DeleteObject (hBitmap)
= DeleteDC (hVdc)
= ReleaseDC (hwnd, hdc)
* end of main

PROCEDURE  decl   && not a few
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER GetDC IN user32 INTEGER hwnd
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER EmptyClipboard  IN user32
	DECLARE INTEGER SetClipboardData IN user32 INTEGER wFmt, INTEGER hMem

	DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
		INTEGER hdc, INTEGER nWidth, INTEGER nHeight

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop  
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
[GetDC](../libraries/user32/GetDC.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetClipboardData](../libraries/user32/SetClipboardData.md)  

## Comment:
Pass into this procedure four screen coordinates that are relative to the upper left corner of the main VFP window or its client area -- depending on HDC used.  
  
***  

