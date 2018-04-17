[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to print a bitmap file

## Before you begin:
Make sure that the source file is a valid bitmap file.   

Check more examples:  
* [GDI+: how to print image file](sample_455.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing screen shot of a form to a bitmap file](sample_187.md)  
* [Storing clipboard contents to a bitmap file](sample_189.md)  
* [Using the LoadImage() to display a bitmap file on the main VFP window](sample_210.md)  

***  


## Code:
```foxpro  
#DEFINE cnBitsPerPixel  24  && bits per pixel
DO decl

PRIVATE hBitmap, hScreenHwnd, hScreenDC, hPrnDC,;
	pnWidth, pnHeight, xOffsPrn, yOffsPrn, xScale, yScale

STORE 0 TO hBitmap, pnWidth, pnHeight, hScreenHwnd, hScreenDC, hPrnDC,;
	xOffsPrn, yOffsPrn, xScale, yScale

LOCAL lcFilename
lcFilename = "c:\Windows\Setup.bmp"

IF LoadBmpFromFile (lcFilename)
	DO RetrieveDevProps
	DO InitPrinting
	DO CleanThePlace
ENDIF
* End Of Main

FUNCTION LoadBmpFromFile (lcFilename)
#DEFINE IMAGE_BITMAP        0
#DEFINE LR_LOADFROMFILE    16
#DEFINE BITMAP_STRU_SIZE   24

	hBitmap = LoadImage (0, lcFilename, IMAGE_BITMAP,;
		0,0, LR_LOADFROMFILE)

	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)

	IF GetObjectA(hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		pnWidth  = buf2dword (SUBSTR(lcBuffer, 5,4))
		pnHeight = buf2dword (SUBSTR(lcBuffer, 9,4))
	ENDIF
RETURN  hBitmap <> 0

PROCEDURE  RetrieveDevProps
#DEFINE LOGPIXELSX           88
#DEFINE LOGPIXELSY           90
#DEFINE PHYSICALOFFSETX     112
#DEFINE PHYSICALOFFSETY     113

	* retrieving screen window handle and device context
	hScreenHwnd = GetActiveWindow()
	hScreenDC = GetWindowDC(hScreenHwnd)

	* the device context of your default printer
	hPrnDC = GetDefaultPrnDC()

	* left margin of the printer page
	xOffsPrn = GetDeviceCaps(hPrnDC, PHYSICALOFFSETX)

	* top margin
	yOffsPrn = GetDeviceCaps(hPrnDC, PHYSICALOFFSETY)

	* horizontal scale when converting between display and printer
	xScale = GetDeviceCaps(hPrnDC,;
		LOGPIXELSX)/GetDeviceCaps(hScreenDC, LOGPIXELSX)

	* vertical scale
	yScale = GetDeviceCaps(hPrnDC,;
	LOGPIXELSY)/GetDeviceCaps(hScreenDC, LOGPIXELSY)
RETURN

PROCEDURE  InitPrinting
#DEFINE DIB_RGB_COLORS        0
#DEFINE SRCCOPY        13369376
	LOCAL lcBInfo, lpBitsArrayPtr, lcDocInfo

	lcBInfo = InitBitmapInfo()
	lpBitsArrayPtr = InitBitsArray()

	= GetDIBits (hScreenDC, hBitmap, 0, pnHeight,;
		lpBitsArrayPtr, @lcBInfo, DIB_RGB_COLORS)

	* init DOCINFO structure -- 20 bytes
	* it is empty -- that means all default settings applied:
	* page format, orientation, pages, number of copies etc.
	lcDocInfo = Chr(20) + Repli(Chr(0), 19)

	IF StartDoc(hPrnDC, @lcDocInfo) > 0
		= StartPage(hPrnDC)

		= StretchDIBits (hPrnDC, xOffsPrn, yOffsPrn,;
			xOffsPrn + Int(xScale * pnWidth),;
			yOffsPrn + Int(yScale * pnHeight),;
			0,0, pnWidth, pnHeight,;
			lpBitsArrayPtr, @lcBInfo, DIB_RGB_COLORS, SRCCOPY)

		= EndPage(hPrnDC)
		= EndDoc(hPrnDC)
	ENDIF

	= GlobalFree (lpBitsArrayPtr)
RETURN

PROCEDURE  CleanThePlace
	= DeleteObject(hBitmap)
	= DeleteDC(hPrnDC)
	= ReleaseDC (hScreenHwnd, hScreenDC)
RETURN

FUNCTION  GetDefaultPrnDC
* returns device context for the default printer
#DEFINE PD_RETURNDC         256
#DEFINE PD_RETURNDEFAULT   1024
	LOCAL lcStruct, lnFlags
	lnFlags = PD_RETURNDEFAULT + PD_RETURNDC

	* fill PRINTDLG structure
	lcStruct = num2dword(66) + Repli(Chr(0), 16) +;
		num2dword(lnFlags) + Repli(Chr(0), 42)
	IF PrintDlg (@lcStruct) <> 0
		RETURN buf2dword (SUBSTR(lcStruct, 17,4))
	ENDIF
RETURN  0

FUNCTION  InitBitmapInfo()
#DEFINE BI_RGB         0
#DEFINE RGBQUAD_SIZE   4  && RGBQUAD
#DEFINE BHDR_SIZE     40  && BITMAPINFOHEADER

	LOCAL lnRgbQuadSize, lcRgbQuad, lcBIHdr

	* initializing BitmapInfoHeader structure
	lcBIHdr = num2dword(BHDR_SIZE) +;
		num2dword(pnWidth) + num2dword(pnHeight) +;
		num2word(1) + num2word(cnBitsPerPixel) +;
		num2dword(BI_RGB) + Repli(Chr(0), 20)

	* creating a buffer for the color table
	IF cnBitsPerPixel <= 8
		lnRgbQuadSize = (2^cnBitsPerPixel) * RGBQUAD_SIZE
		lcRgbQuad = Repli(Chr(0), lnRgbQuadSize)
	ELSE
		lcRgbQuad = ""
	ENDIF
RETURN  lcBIHdr + lcRgbQuad

PROCEDURE  InitBitsArray()
#DEFINE GMEM_FIXED   0
	LOCAL lnPtr, lnAllocSize, lnBytesPerScan

	* making sure the value is DWORD-aligned
	lnBytesPerScan = Int((pnWidth * cnBitsPerPixel)/8)
	IF Mod(lnBytesPerScan, 4) <> 0
		lnBytesPerScan = lnBytesPerScan + 4 - Mod(lnBytesPerScan, 4)
	ENDIF

	lnAllocSize = pnHeight * lnBytesPerScan
	lnPtr = GlobalAlloc (GMEM_FIXED, lnAllocSize)
	= ZeroMemory (lnPtr, lnAllocSize)
RETURN  lnPtr  && pointer to a memory block

FUNCTION  num2word (lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER LoadImage IN user32;
		INTEGER hinst, STRING lpszName, INTEGER uType,;
		INTEGER cxDesired, INTEGER cyDesired, INTEGER fuLoad

	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	DECLARE INTEGER PrintDlg IN comdlg32 STRING @ lppd
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING @ lpdi
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
    DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

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

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes  
```  
***  


## Listed functions:
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDIBits](../libraries/gdi32/GetDIBits.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[LoadImage](../libraries/user32/LoadImage.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  
[StretchDIBits](../libraries/gdi32/StretchDIBits.md)  
[ZeroMemory](../libraries/kernel32/ZeroMemory.md)  

## Comment:
The LoadImage is used to read data from a bitmap file into corresponding structures and to provide a handle. With this handle bitmap data is transferred to the device context of a default printer.  
  
Actually this code is much similar to the [Printing the image of a FoxPro form](sample_158.md) code. The only difference is the origin of the bitmap handle. In this example it is the result of reading data from a bitmap file. Otherwise, while printing a form, the bitmap handle is retrieved from the device context of the form.  
  
***  

