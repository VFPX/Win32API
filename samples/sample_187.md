[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Storing screen shot of a form to bitmap file

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
Call this code from a VFP form to store its snapshot to a bitmap file (24-bpp). Make sure that the target file *(m.lcFilename)* is a valid path.  

Check similar example [Storing screen shot of a form to enhanced metafile (*.emf)](sample_402.md).  

See also:


<!-- Anatoliy -->
<a href="http://www.news2news.com/vfp/?solution=9"><img src="../images/screencapture_270_48.png" width=270 height=48 border=0 alt="Download ScreenCapture Library">   

* [GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF) ](sample_454.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a bitmap file](sample_211.md)  

  
***  


## Code:
```foxpro  
#DEFINE DIB_RGB_COLORS 0
#DEFINE BI_RGB 0
#DEFINE RGBQUAD_SIZE 4  && RGBQUAD
#DEFINE BHDR_SIZE 40  && BITMAPINFOHEADER
#DEFINE GMEM_FIXED 0
#DEFINE GENERIC_WRITE  0x40000000
#DEFINE FILE_SHARE_WRITE 2
#DEFINE CREATE_ALWAYS 2
#DEFINE FILE_ATTRIBUTE_NORMAL 128
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE BFHDR_SIZE 14  && BITMAPFILEHEADER
#DEFINE SRCCOPY 0xCC0020
#DEFINE MAX_DWORD 0xffffffff

DO declare

PRIVATE hMemDC, hMemBmp, lnWidth, lnHeight, lnBitsPerPixel,;
	lnBytesPerScan, lcBFileHdr, lcBIHdr, lpBitsArray, lnBitsSize,;
	lcRgbQuad, lnRgbQuadSize, lcBInfo, lnFileSize

STORE "" TO lcBIHdr, lcBInfo, lcRgbQuad
STORE 0 TO hMemDC, hMemBmp, lnWidth, lnHeight, lnFileSize,;
	lnBitsPerPixel, lnBytesPerScan, lnRgbQuadSize, lpBitsArray, lnBitsSize

	= MakeSnapshot()
	= InitBitmapInfo()
	= InitBitsArray()

	= GetDIBits(hMemDC, hMemBmp, 0, lnHeight, lpBitsArray,;
			@lcBInfo, DIB_RGB_COLORS)
	
	LOCAL lcFilename
	lcFilename = "c:\Temp\myfile.bmp"

	IF bmp2file(lcFilename)
		ACTI SCREEN
		? "File:", lcFilename
		? "Size:", LTRIM(TRANS(lnFileSize, "999,999,999,999"))
		? "Width:", LTRIM(STR(lnWidth)) + " pixels"
		? "Height:", LTRIM(STR(lnHeight)) + " pixels"
		? "Bits per pixel:", LTRIM(STR(lnBitsPerPixel))
	ENDIF

	= GlobalFree(lpBitsArray)
	= DeleteObject(hMemBmp)
	= DeleteDC(hMemDC)
* end of main

PROCEDURE InitBitmapInfo()
	* force 24-bit format
	lnBitsPerPixel = 24
	lnBytesPerScan = lnWidth * 3

	* line width should be DWORD-aligned (4 bytes)
	* important for 16- and 24-bit color palettes
	IF Mod(lnBytesPerScan, 4) <> 0
		lnBytesPerScan = lnBytesPerScan + 4 - Mod(lnBytesPerScan, 4)
	ENDIF

	* initialize BitmapInfoHeader structure
	lcBIHdr = num2dword(BHDR_SIZE) + num2dword(lnWidth) +;
		num2dword(lnHeight) + num2word(1) + num2word(lnBitsPerPixel) +;
		num2dword(BI_RGB) + num2dword(0) + num2dword(0) + num2dword(0) +;
		num2dword(0) + num2dword(0)

	* create a buffer for the color table
	IF lnBitsPerPixel <= 8
		lnRgbQuadSize = (2^lnBitsPerPixel) * RGBQUAD_SIZE
		lcRgbQuad = Repli(Chr(0), lnRgbQuadSize)
	ELSE
		lnRgbQuadSize = 0
		lcRgbQuad = ""
	ENDIF

	* merge two pieces together
	lcBInfo = lcBIHdr + lcRgbQuad
RETURN

PROCEDURE InitBitsArray()
	lnBitsSize = lnHeight * lnBytesPerScan
	lpBitsArray = GlobalAlloc(GMEM_FIXED, lnBitsSize)
	= ZeroMemory(lpBitsArray, lnBitsSize)

FUNCTION bmp2file(lcTargetFile)
* save all pieces to a disk file
	LOCAL hFile, lnOffBits

	* the size of the bitmap file
	lnFileSize = BFHDR_SIZE + BHDR_SIZE + lnRgbQuadSize + lnBitsSize

	* offset to the binary bitmap data
	lnOffBits = BFHDR_SIZE + BHDR_SIZE + lnRgbQuadSize
	
	* bitmap file header
	lcBFileHdr = "BM" + num2dword(lnFileSize) +;
			num2dword(0) + num2dword(lnOffBits)
	
	* create target file
	hFile = CreateFile(lcTargetFile, GENERIC_WRITE,;
		FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)

	IF hFile <> INVALID_HANDLE_VALUE
	* store block after block, very straightforward process
		= String2File(hFile, @lcBFileHdr)           && BitmapFileHeader
		= String2File(hFile, @lcBInfo)              && BitmapInfo
		= Ptr2File(hFile, lpBitsArray, lnBitsSize)  && bitmap data
		= CloseHandle(hFile)
		RETURN .T.
	ELSE
		= MESSAGEBOX("Failed to create target file: " + lcTargetFile)
		RETURN .F.
	ENDIF

PROCEDURE String2File(hFile, lcBuffer)
* appends string buffer to a file
	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped
	= WriteFile(hFile, @lcBuffer, Len(lcBuffer), 0, 0)

PROCEDURE Ptr2File(hFile, lnPointer, lnBt2Write)
* appends memory block to a file
	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, INTEGER lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped
	= WriteFile(hFile, lnPointer, lnBt2Write, 0, 0)

PROCEDURE MakeSnapshot()
	LOCAL hWindow, hdc, hSavedBitmap

	hWindow = GetFocus()
	hdc = GetWindowDC(hWindow)
	= GetWinRect(hWindow, @lnWidth, @lnHeight)

	hMemDC = CreateCompatibleDC(hdc)
	hMemBmp = CreateCompatibleBitmap(hdc, lnWidth, lnHeight)

	hSavedBitmap = SelectObject(hMemDC, hMemBmp)
	= BitBlt(hMemDC, 0,0, lnWidth,lnHeight, hdc, 0,0, SRCCOPY)

	* display the mouse cursor on the screenshot
	= DrawMouseCursor()

	= SelectObject(hMemDC, hSavedBitmap)
	= ReleaseDC(hWindow, hdc)

PROCEDURE DrawMouseCursor
#DEFINE CURSORINFO_SIZE 20
	* the cursor must be visible before calling the GetCursorInfo
	= ShowCursor(1)
	DOEVENTS

	LOCAL cBuffer, hCursor, hIcon, nX, nY

	cBuffer = PADR(CHR(CURSORINFO_SIZE), CURSORINFO_SIZE, CHR(0))
	IF GetCursorInfo(@cBuffer) = 0
	* GetCursorInfo failed call GetLastError()
		RETURN
	ENDIF

	* get the handle and the position of the cursor
	hCursor = buf2dword(SUBSTR(cBuffer, 9,4))
	nX = buf2dword(SUBSTR(cBuffer, 13,4))
	nY = buf2dword(SUBSTR(cBuffer, 17,4))

	hIcon = CopyIcon(hCursor)
	IF hIcon <> 0
		* draw the cursor on the memory device context
		= DrawIcon(hMemDC, m.nX, m.nY, m.hIcon)
		= DestroyIcon(hIcon)
	ENDIF

PROCEDURE GetWinRect(hWindow, lnWidth, lnHeight)
    LOCAL lpRect, lnLeft, lnTop, lnRight, lnBottom
    lpRect = Repli(Chr(0), 16)
    = GetWindowRect(hWindow, @lpRect)

    lnLeft = buf2dword(SUBSTR(lpRect, 1,4))
    lnTop = buf2dword(SUBSTR(lpRect, 5,4))
    lnRight = buf2dword(SUBSTR(lpRect, 9,4))
    lnBottom = buf2dword(SUBSTR(lpRect, 13,4))

    IF lnLeft > lnRight
    	lnLeft = lnLeft - MAX_DWORD
    ENDIF
    IF lnTop > lnBottom
    	lnTop = lnTop - MAX_DWORD
    ENDIF

	lnWidth  = lnRight - lnLeft
	lnHeight = lnBottom - lnTop

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

PROCEDURE declare
	DECLARE INTEGER GetDIBits IN gdi32;
		INTEGER hdc, INTEGER hbmp, INTEGER uStartScan,;
		INTEGER cScanLines, INTEGER lpvBits, STRING @lpbi,;
		INTEGER uUsage

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hWindow, STRING @lpRect
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWindow, INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetCursorInfo IN user32 STRING @pci
	DECLARE INTEGER CopyIcon IN user32 INTEGER hIcon
	DECLARE INTEGER DestroyIcon IN user32 INTEGER hIcon
	DECLARE INTEGER ShowCursor IN user32 INTEGER bShow

	DECLARE INTEGER DrawIcon IN user32;
		INTEGER hDC, INTEGER X, INTEGER Y, INTEGER hIcon

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
		INTEGER hdc, INTEGER nWidth, INTEGER nHeight

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile

*** The structures used in this code:
*| typedef struct tagBITMAPINFOHEADER{
*|   DWORD  biSize;             0:4
*|   LONG   biWidth;            4:4
*|   LONG   biHeight;           8:4
*|   WORD   biPlanes;          12:2
*|   WORD   biBitCount;        14:2
*|   DWORD  biCompression;     16:4
*|   DWORD  biSizeImage;       20:4
*|   LONG   biXPelsPerMeter;   24:4
*|   LONG   biYPelsPerMeter;   28:4
*|   DWORD  biClrUsed;         32:4
*|   DWORD  biClrImportant;    36:4 = 40 bytes
*| } BITMAPINFOHEADER, *PBITMAPINFOHEADER

*| typedef struct tagRGBQUAD {
*|   BYTE    rgbBlue;
*|   BYTE    rgbGreen;
*|   BYTE    rgbRed;
*|   BYTE    rgbReserved;
*| } RGBQUAD; total 4 bytes

*| typedef struct tagBITMAPINFO {
*|  BITMAPINFOHEADER bmiHeader;
*|  RGBQUAD          bmiColors[1];
*|} BITMAPINFO, *PBITMAPINFO;

*| typedef struct tagBITMAPFILEHEADER {
*|   WORD    bfType;         0:2
*|   DWORD   bfSize;         2:4
*|   WORD    bfReserved1;    6:2
*|   WORD    bfReserved2;    8:2
*|   DWORD   bfOffBits;     10:4 = 14 bytes
*| } BITMAPFILEHEADER, *PBITMAPFILEHEADER;

*!*	typedef struct {
*!*	    DWORD cbSize;  0:4
*!*	    DWORD flags;   4:4
*!*	    HCURSOR hCursor; 8:4
*!*	    POINT ptScreenPos; 12:8
*!*	} CURSORINFO, *PCURSORINFO, *LPCURSORINFO  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CopyIcon](../libraries/user32/CopyIcon.md)  
[CreateCompatibleBitmap](../libraries/gdi32/CreateCompatibleBitmap.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[DestroyIcon](../libraries/user32/DestroyIcon.md)  
[DrawIcon](../libraries/user32/DrawIcon.md)  
[GetCursorInfo](../libraries/user32/GetCursorInfo.md)  
[GetDIBits](../libraries/gdi32/GetDIBits.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[ShowCursor](../libraries/user32/ShowCursor.md)  
[WriteFile](../libraries/kernel32/WriteFile.md)  

## Comment:
The resulting file is forced to be in 24-bit format (24 bits per pixel). It is not compressed.  
  
The part of DIB (Device-Independent Bitmap), that contains pixel data, can be too large for managing it via VFP strings. For that reason the GlobalAlloc/GlobalFree combination is used to allocate/release memory for this buffer.   
  
The WriteFile function is declared in two different ways: one for strings and another for pointers.  
  
Microsoft Knowledge Base Article - 161299  
[HOWTO: Capture and Print the Screen, a Form, or Any Window](https://jeffpar.github.io/kbarchive/kb/161/Q161299/)  
  
* * *  
April 5, 2006: a procedure added that draws current mouse cursor on the bitmap.  
  
* * *  
<a href="http://www.fileformat.info/">FileFormat.Info</a> references on file extensions, file formats, MIME types, data conversion between formats and more.  
  
***  

