[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to display picture stored in enhanced-format metafile (*.emf)

## Code:
```foxpro  
DO decl
LOCAL hWindow, hDC, hMeta, cHdr, cRect, nRight, nBottom

hMeta = GetEnhMetaFile("test.emf")  && provide valid *.emf file
IF hMeta = 0
	? "Could not open file."
	RETURN
ENDIF

*|typedef struct tagENHMETAHEADER {
*|  DWORD iType;            0:4
*|  DWORD nSize;            4:4
*|  RECTL rclBounds;        8:16
*|  RECTL rclFrame;        24:16
*|  DWORD dSignature;      40:4
*|  DWORD nVersion;        44:4
*|  DWORD nBytes;          48:4
*|  DWORD nRecords;        52:4
*|  WORD  nHandles;        56:2
*|  WORD  sReserved;       58:2
*|  DWORD nDescription;    60:4
*|  DWORD offDescription;  64:4
*|  DWORD nPalEntries;     68:4
*|  SIZEL szlDevice;       72:8
*|  SIZEL szlMillimeters;  80:8
*|#if (WINVER >= 0x0400)
*|  DWORD cbPixelFormat;   88:4
*|  DWORD offPixelFormat;  92:4
*|  DWORD bOpenGL;         96:4
*|#endif /* WINVER >= 0x0400 */
*|#if (WINVER >= 0x0500)
*|  SIZEL szlMicrometers; 100:8
*|#endif /* WINVER >= 0x0500 */
*|} ENHMETAHEADER, *PENHMETAHEADER; total bytes 108 (WinXP)

cHdr = Repli(Chr(0), 4096)
IF GetEnhMetaFileHeader(hMeta, Len(cHdr), @cHdr) = 0
	= DeleteEnhMetaFile(hMeta)
	? "Could not read EMF header data."
	RETURN
ENDIF

* calculating the bounding rectangle that will be used
* to display the picture; starts from (100,100)
cRect = SUBSTR(cHdr,9,16)  && an offset to rclBounds in ENHMETAHEADER
nRight = buf2dword(SUBSTR(cRect,9,4))
nBottom = buf2dword(SUBSTR(cRect,13,4))
cRect = num2dword(100) + num2dword(100) +;
	num2dword(nRight+100) + num2dword(nBottom+100)

* target window -- main VFP screen
hWindow = GetActiveWindow()
hDC = GetWindowDC(hWindow)

* displaying the picture
= PlayEnhMetaFile(hDC, hMeta, @cRect)

* releasing system resources
= DeleteEnhMetaFile(hMeta)
= ReleaseDC(hWindow, hDC)
* end of main

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC In user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER DeleteEnhMetaFile IN gdi32 INTEGER hemf
	DECLARE INTEGER GetEnhMetaFile IN gdi32 STRING lpszMetaFile

	DECLARE INTEGER GetEnhMetaFileHeader In gdi32;
		INTEGER hemf, INTEGER cbBuffer, STRING @lpemh

	DECLARE INTEGER PlayEnhMetaFile IN gdi32;
		INTEGER hdc, INTEGER hemf, STRING @lpRect

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[DeleteEnhMetaFile](../libraries/gdi32/DeleteEnhMetaFile.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetEnhMetaFile](../libraries/gdi32/GetEnhMetaFile.md)  
[GetEnhMetaFileHeader](../libraries/gdi32/GetEnhMetaFileHeader.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[PlayEnhMetaFile](../libraries/gdi32/PlayEnhMetaFile.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
