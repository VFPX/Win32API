[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to print FoxPro form

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
Call this code from a method or event of FoxPro form to print image of the form on your default printer.   

The window handle of the form is obtained through GetFocus function. For that a form has to be active and own the keyboard focus. In VFP7 and later, use ThisForm.HWnd instead.  

See also:


<!-- Anatoliy -->
<a href="http://www.news2news.com/vfp/?solution=9"><img src="../images/screencapture_270_48.png" width=270 height=48 border=0 alt="Download ScreenCapture Library"></a>   

* [How to print a FoxPro form using Metafile API functions](sample_406.md)  
* [GDI+: sending image of FoxPro form to printer ](sample_455.md)  
* [Storing screen shot of a form to a BMP file](sample_187.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a BMP file](sample_211.md)  
  
***  


## Code:
```foxpro  
#DEFINE LOGPIXELSX 0x0058
#DEFINE LOGPIXELSY 0x005A
#DEFINE PHYSICALOFFSETX 0x0070
#DEFINE PHYSICALOFFSETY 0x0071
#DEFINE SRCCOPY 0xCC0020
#DEFINE DIB_RGB_COLORS 0
#DEFINE DOCINFO_STRUCT_SIZE 20

DO declare

PRIVATE pnWidth, pnHeight, pnBitsPerPixel, pnBytesPerScan
STORE 0 TO pnWidth, pnHeight, pnBitsPerPixel, pnBytesPerScan

LOCAL hWindow, hFormDC, hPrnDC, hMemDC, hMemBmp,;
	hSavedBitmap, xOffsPrn, yOffsPrn, xScale, yScale,;
	lcDocInfo, lcBInfo, lpBitsArray

* retrieving printer device context and page offsets
hPrnDC = GetDefaultPrnDC()  && no error check
xOffsPrn = GetDeviceCaps(hPrnDC, PHYSICALOFFSETX)
yOffsPrn = GetDeviceCaps(hPrnDC, PHYSICALOFFSETY)

* screen window handle, device context, width, and height
hWindow = GetFocus()  && a window with keyboard focus
hFormDC = GetWindowDC(hWindow)
= GetWinRect(hWindow, @pnWidth, @pnHeight)

* scaling factor from screen to printer
* SYSMETRIC() provides same results
xScale = GetDeviceCaps(hPrnDC, LOGPIXELSX)/;
	GetDeviceCaps(hFormDC, LOGPIXELSX)

yScale = GetDeviceCaps(hPrnDC, LOGPIXELSY)/;
	GetDeviceCaps(hFormDC, LOGPIXELSY)

* creating screen compatible DC and BITMAP objects for passing the image
* through them from screen to printer;
* direct screen to printer copying does not work
hMemDC = CreateCompatibleDC(hFormDC)
hMemBmp = CreateCompatibleBitmap(hFormDC, pnWidth, pnHeight)
hSavedBitmap = SelectObject(hMemDC, hMemBmp)

* copying bitmap data from screen to the virtual device context;
* unselecting the bitmap from the memory device context
= BitBlt(hMemDC, 0,0, pnWidth,pnHeight, hFormDC, 0,0, SRCCOPY)
= SelectObject(hMemDC, hSavedBitmap)

* copying bits from the compatible bitmap to a buffer
* as a device-independent bitmap (DIB) with a BitsPerPixel value
* as one of the printer device context
lcBInfo = InitBitmapInfo(hPrnDC)
lpBitsArray = InitBitsArray()  && pointer
= GetDIBits(hMemDC, hMemBmp, 0, pnHeight,;
	lpBitsArray, @lcBInfo, DIB_RGB_COLORS)

lcDocInfo = PADR(CHR(DOCINFO_STRUCT_SIZE),;
	DOCINFO_STRUCT_SIZE, CHR(0))

IF StartDoc(hPrnDC, @lcDocInfo) > 0
	= StartPage(hPrnDC)

	= StretchDIBits(hPrnDC,;
		xOffsPrn, yOffsPrn,;
		xOffsPrn + INT(xScale * pnWidth),;
		yOffsPrn + INT(yScale * pnHeight),;
		0,0, pnWidth, pnHeight,;
		lpBitsArray, @lcBInfo,;
		DIB_RGB_COLORS, SRCCOPY)

	= EndPage(hPrnDC)
	= EndDoc(hPrnDC)
ENDIF

* releasing system resources on exit
= GlobalFree(lpBitsArray)
= DeleteObject(hMemBmp)
= DeleteDC(hMemDC)
= DeleteDC(hPrnDC)
= ReleaseDC(hWindow, hFormDC)
* end of main

PROCEDURE GetWinRect(lnHwnd, lnWidth, lnHeight)
#DEFINE MAX_DWORD 0xffffffff
* returns window width and height for the given hwnd
	LOCAL lpRect, lnLeft, lnTop, lnRight, lnBottom
	lpRect = REPLICATE(CHR(0), 16)
	= GetWindowRect(lnHwnd, @lpRect)

	lnRight = buf2dword(SUBSTR(lpRect, 9,4))
	lnBottom = buf2dword(SUBSTR(lpRect, 13,4))

	lnLeft = buf2dword(SUBSTR(lpRect, 1,4))
	IF lnLeft > lnRight
		lnLeft = lnLeft - MAX_DWORD
	ENDIF

	lnTop = buf2dword(SUBSTR(lpRect,  5,4))
	IF lnTop > lnBottom
		lnTop = lnTop - MAX_DWORD
	ENDIF

	lnWidth = lnRight - lnLeft
	lnHeight = lnBottom - lnTop

FUNCTION GetDefaultPrnDC
#DEFINE PD_RETURNDC 0x100
#DEFINE PD_RETURNDEFAULT 0x400
#DEFINE PRINTDLG_STRUCT_SIZE 66
* returns device context for the default printer

	LOCAL lcStruct, lnFlags
	lnFlags = BITOR(PD_RETURNDEFAULT, PD_RETURNDC)

	* populating PRINTDLG structure
	lcStruct = num2dword(PRINTDLG_STRUCT_SIZE) +;
		REPLICATE(CHR(0), 16) +;
		num2dword(lnFlags) + REPLICATE(CHR(0), 42)

	IF PrintDlg(@lcStruct) <> 0
		RETURN buf2dword(SUBSTR(lcStruct, 17,4))
	ENDIF
RETURN 0

FUNCTION InitBitmapInfo(hTargetDC)
#DEFINE BI_RGB 0
#DEFINE BHDR_STRUCT_SIZE 40  && BITMAPINFOHEADER
#DEFINE RGBQUAD_SIZE 4  && RGBQUAD

	LOCAL lnRgbQuadSize, lcRgbQuad, lcBIHdr

	* use printer BitPerPixel value
	pnBitsPerPixel=24

	* initializing BitmapInfoHeader structure
	lcBIHdr = num2dword(BHDR_STRUCT_SIZE) +;
		num2dword(pnWidth) + num2dword(pnHeight) +;
		num2word(1) + num2word(pnBitsPerPixel) +;
		num2dword(BI_RGB) + REPLICATE(CHR(0), 20)

	* creating buffer for the color table
	IF pnBitsPerPixel <= 8
		lnRgbQuadSize =(2^pnBitsPerPixel) * RGBQUAD_SIZE
		lcRgbQuad = REPLICATE(CHR(0), lnRgbQuadSize)
	ELSE
		lcRgbQuad = ""
	ENDIF
RETURN lcBIHdr + lcRgbQuad

PROCEDURE InitBitsArray()
#DEFINE GMEM_FIXED 0
	LOCAL lnPtr, lnAllocSize

	* the value must be DWORD-aligned
	pnBytesPerScan = INT((pnWidth * pnBitsPerPixel)/8)
	IF MOD(pnBytesPerScan, 4) <> 0
		pnBytesPerScan = pnBytesPerScan +;
			4 - MOD(pnBytesPerScan, 4)
	ENDIF

	lnAllocSize = pnHeight * pnBytesPerScan
	lnPtr = GlobalAlloc(GMEM_FIXED, lnAllocSize)
	ZeroMemory(lnPtr, lnAllocSize)
RETURN lnPtr

FUNCTION num2word(lnValue)
RETURN CHR(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

FUNCTION num2dword(lnValue)
#DEFINE m0 0x00000100
#DEFINE m1 0x00010000
#DEFINE m2 0x01000000
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN CHR(b0)+CHR(b1)+CHR(b2)+CHR(b3)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hWindow, STRING @lpRect
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING @ lpdi
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER PrintDlg IN comdlg32 STRING @ lppd
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
		INTEGER hdc, INTEGER nWidth, INTEGER nHeight

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

	DECLARE INTEGER StretchDIBits IN gdi32;
		INTEGER hdc, INTEGER XDest, INTEGER YDest,;
		INTEGER nDestWidth, INTEGER nDestHeight, INTEGER XSrc,;
		INTEGER YSrc, INTEGER nSrcWidth, INTEGER nSrcHeight,;
		INTEGER lpBits, STRING @lpBitsInfo,;
		INTEGER iUsage, INTEGER dwRop

	DECLARE INTEGER GetDIBits IN gdi32;
		INTEGER hdc, INTEGER hbmp, INTEGER uStartScan,;
		INTEGER cScanLines, INTEGER lpvBits, STRING @lpbi,;
		INTEGER uUsage  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CreateCompatibleBitmap](../libraries/gdi32/CreateCompatibleBitmap.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetDIBits](../libraries/gdi32/GetDIBits.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  
[StretchDIBits](../libraries/gdi32/StretchDIBits.md)  

## Comment:
At the beginning two [device contexts](https://msdn.microsoft.com/en-us/library/windows/desktop/dd183553(v=vs.85).aspx) are retrieved:   
\- source device context from an active form  
\- destination device context from a default printer -- PrintDlg is used  
  
It is not possible to transfer bitmap data directly between these device contexts -- at least to my knowledge. That is why you need a mediator -- the *compatible device context* and the *compatible bitmap* selected into it.   
  
The ***compatible*** means that these both have properties similar to their form counterparts.  
  
Bitmap information (both headers and data) is copied from the form to the compatible bitmap via the BitBlt function. Then device-independent bitmap data is selected from this temporary bitmap via the GetDIBits, next to be sent to the printer device context using the StretchDIBits function.  
  
The last transfer is wrapped into the StartDoc | StartPage ... EndPage | EndDoc calls.  
  
To keep the code short several simplifications have been made: only one page is printed regardless of the size of the form; no control of the page orientation.   
  
The PRINTDLG structure, one used to initialize the printer settings, is mostly populated with zeros. That means all default printing settings are applied: one copy, all pages, portrait etc. To switch, for example,  to the album orientation, populate correspondent members of this structure. Check [this example](sample_150.md).  
  
***  

