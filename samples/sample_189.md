[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Storing content of the Clipboard to a bitmap file

## Before you begin:
To test this code copy something "bmp-like" to the Windows clipboard. Cut or copy a picture fragment inside a graphics application or just press the Print Screen key.  

Make sure the destination path and file name are valid.  

See also:

* [GDI+: Storing content of the Clipboard to a bitmap file](sample_475.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing screen shot of a form to a bitmap file](sample_187.md)  
* [Using the LoadImage() to display a bitmap file on the main VFP window](sample_210.md)  
* [How to print a bitmap file](sample_211.md)  
* [GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](sample_457.md)  

 
***  


## Code:
```foxpro  
#DEFINE CF_BITMAP 2
#DEFINE OBJ_BITMAP 7
#DEFINE DIB_RGB_COLORS 0
#DEFINE GENERIC_WRITE 0x40000000
#DEFINE FILE_SHARE_WRITE 2
#DEFINE CREATE_ALWAYS 2
#DEFINE FILE_ATTRIBUTE_NORMAL 128
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE BI_RGB 0
#DEFINE GMEM_FIXED 0
#DEFINE BFHDR_SIZE 14  && BITMAPFILEHEADER
#DEFINE BHDR_SIZE 40  && BITMAPINFOHEADER
#DEFINE RGBQUAD_SIZE 4  && RGBQUAD
#DEFINE BHDR_SIZE 40  && BITMAPINFOHEADER
#DEFINE BITMAP_STRU_SIZE 24

DO declare

LOCAL hClipBmp, lcTargetFile
lcTargetFile = "c:\temp\clipboard.bmp"

= OpenClipboard(0)
hClipBmp = GetClipboardData(CF_BITMAP)
= CloseClipboard()

IF hClipBmp = 0 Or GetObjectType(hClipBmp) <> OBJ_BITMAP
	= MESSAGEBOX("No bitmap data found on the clipboard.     " +;
		CHR(13)+CHR(13)+;
		"Press Print Screen key and test again.     ",;
		64, "Clipboard to BMP")
	RETURN
ENDIF

= bitmap2file(hClipBmp, lcTargetFile)
= DeleteObject(hClipBmp)
* end of main

PROCEDURE bitmap2file(hBitmap, lcTargetFile)
	PRIVATE pnWidth, pnHeight, pnBitsSize, pnRgbQuadSize, pnBytesPerScan
	STORE 0 TO pnWidth, pnHeight, pnBytesPerScan, pnBitsSize, pnRgbQuadSize
	= GetBitmapDimensions(hBitmap, @pnWidth, @pnHeight)

	LOCAL lpBitsArray, lcBInfo

	lcBInfo = InitBitmapInfo()
	lpBitsArray = InitBitsArray()

	LOCAL hwnd, hdc, hMemDC
	hwnd = GetActiveWindow()
	hdc = GetWindowDC(hwnd)
	hMemDC = CreateCompatibleDC(hdc)
	= ReleaseDC(hwnd, hdc)

	= GetDIBits(hMemDC, hBitmap, 0, pnHeight, lpBitsArray,;
			@lcBInfo, DIB_RGB_COLORS)

	LOCAL hFile, lnFileSize, lnOffBits, lcBFileHdr

	* bitmap file size
	lnFileSize = BFHDR_SIZE + BHDR_SIZE + pnRgbQuadSize + pnBitsSize

	* offset to the bitmap bits
	lnOffBits = BFHDR_SIZE + BHDR_SIZE + pnRgbQuadSize
	
	* bitmap file header
	lcBFileHdr = "BM" + num2dword(lnFileSize) +;
			num2dword(0) + num2dword(lnOffBits)

	* target file handle
	hFile = CreateFile(lcTargetFile,;
				GENERIC_WRITE,;
				FILE_SHARE_WRITE, 0,;
				CREATE_ALWAYS,;
				FILE_ATTRIBUTE_NORMAL, 0)

	IF hFile <> INVALID_HANDLE_VALUE
	* a straightforward process of storing block after block:
		WAIT WINDOW "Storing to file..." NOWAIT

		= String2File(hFile, @lcBFileHdr)           && BitmapFileHeader
		= String2File(hFile, @lcBInfo)              && BitmapInfo
		= Ptr2File(hFile, lpBitsArray, pnBitsSize)  && bitmap data
		= CloseHandle(hFile)
		
		WAIT CLEAR
		IF MESSAGEBOX("File created " +;
			lcTargetFile + Chr(13)+Chr(13) +;
			LTRIM(STR(lnFileSize)) + " bytes" + Chr(13) +;
			LTRIM(STR(pnWidth)) + " x " +;
			LTRIM(STR(pnHeight)) + Chr(13) + CHR(13) +;
			"Press YES to open this file " +;
			"in the default application.     ",;
			32+4, "Clipboard to BMP") = 6

			= ShellExecute(0, "open", m.lcTargetFile,;
				"", "", 3)
		ENDIF
	ELSE
		= MESSAGEBOX("Unable to create file " +;
			lcTargetFile + "     ", 48, "Error")
	ENDIF

	= GlobalFree(lpBitsArray)
	= DeleteDC(hMemDC)
RETURN

PROCEDURE GetBitmapDimensions(hBitmap, lnWidth, lnHeight)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), BITMAP_STRU_SIZE)
	IF GetObjectA(hBitmap, BITMAP_STRU_SIZE, @lcBuffer) <> 0
		lnWidth  = buf2dword(SUBSTR(lcBuffer, 5,4))
		lnHeight = buf2dword(SUBSTR(lcBuffer, 9,4))
	ENDIF
RETURN

PROCEDURE InitBitmapInfo(lcBIHdr)

	LOCAL lnBitsPerPixel, lcBIHdr, lcRgbQuad

	* forcing 24-bit format
	lnBitsPerPixel = 24
	pnBytesPerScan = Int((pnWidth * lnBitsPerPixel)/8)

	* line width should be DWORD-aligned (4 bytes)
	* important for 16- and 24-bit images
	IF Mod(pnBytesPerScan, 4) <> 0
		pnBytesPerScan = pnBytesPerScan + 4 - Mod(pnBytesPerScan, 4)
	ENDIF

	* initializing BitmapInfoHeader structure
	lcBIHdr = num2dword(BHDR_SIZE) + num2dword(pnWidth) +;
		num2dword(pnHeight) + num2word(1) + num2word(lnBitsPerPixel) +;
		num2dword(BI_RGB) + Repli(Chr(0), 20)

	* creating a buffer for the color table
	IF lnBitsPerPixel <= 8
		pnRgbQuadSize = (2^lnBitsPerPixel) * RGBQUAD_SIZE
		lcRgbQuad = Repli(Chr(0), pnRgbQuadSize)
	ELSE
		lcRgbQuad = ""
	ENDIF
RETURN  lcBIHdr + lcRgbQuad

PROCEDURE InitBitsArray()
	LOCAL lnPtr

	pnBitsSize = pnHeight * pnBytesPerScan
	lnPtr = GlobalAlloc(GMEM_FIXED, pnBitsSize)
	= ZeroMemory(lnPtr, pnBitsSize)
RETURN  lnPtr

PROCEDURE String2File(hFile, lcBuffer)
* appends string buffer to a file
	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped

	= WriteFile(hFile, @lcBuffer, Len(lcBuffer), 0, 0)
RETURN

PROCEDURE Ptr2File(hFile, lnPointer, lnBt2Write)
* appends memory block to a file
	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, INTEGER lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped

	= WriteFile(hFile, lnPointer, lnBt2Write, 0, 0)
RETURN

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow
	DECLARE INTEGER CreateCompatibleDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hWindow
	DECLARE INTEGER GetClipboardData IN user32 INTEGER uFormat
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWindow, INTEGER hdc
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hWindow, STRING lpOperation,;
		STRING lpFile, STRING lpParameters,;
		STRING lpDirectory, INTEGER nShowCmd

	DECLARE INTEGER GetObject IN gdi32 AS GetObjectA;
		INTEGER hgdiobj, INTEGER cbBuffer, STRING @lpvObject

	DECLARE INTEGER GetObjectType IN gdi32 INTEGER h

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE INTEGER GetDIBits IN gdi32;
		INTEGER hdc, INTEGER hbmp,;
		INTEGER uStartScan, INTEGER cScanLines,;
		INTEGER lpvBits, STRING @lpbi, INTEGER uUsage

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateCompatibleDC](../libraries/gdi32/CreateCompatibleDC.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClipboardData](../libraries/user32/GetClipboardData.md)  
[GetDIBits](../libraries/gdi32/GetDIBits.md)  
[GetObject](../libraries/gdi32/GetObject.md)  
[GetObjectType](../libraries/gdi32/GetObjectType.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  
[WriteFile](../libraries/kernel32/WriteFile.md)  

## Comment:
The clipboard must stay opened during the procedure and only then closed. The handle to the clipboard content is retrieved via the GetClipboardData call.  
  
If this is a bitmap handle, then the code is invoked that is very much like the [Storing screen shot of a form to a bitmap file](sample_187.md).  
  
The target file is a 24 bit per pixel bitmap.  
  
***  

