[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to print picture stored in enhanced-format metafile (*.emf)

## Before you begin:
Check more examples:  
* [GDI+: how to print image file](sample_455.md)  
* [How to print bitmap file](sample_211.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
  
***  


## Code:
```foxpro  
#DEFINE PHYSICALOFFSETX  112
#DEFINE PHYSICALOFFSETY  113
#DEFINE HORZSIZE  4
#DEFINE VERTSIZE  6
#DEFINE HORZRES   8
#DEFINE VERTRES   10
DO decl

LOCAL hPrnDC, hMeta, cHdr, cRect, nRight, nBottom,;
	xoffs, yoffs, hsize, vsize, hres, vres, cDocinfo

* target device context of default printer
hPrnDC = GetDefaultPrnDC()
IF hPrnDC = 0
	? "Could not access default printer."
	RETURN
ENDIF

hMeta = GetEnhMetaFile("test.emf")  && provide valid *.emf file
IF hMeta = 0
	? "Could not open file."
	RETURN
ENDIF

cHdr = Repli(Chr(0), 4096)
IF GetEnhMetaFileHeader(hMeta, Len(cHdr), @cHdr) = 0
	= DeleteEnhMetaFile(hMeta)
	? "Could not read EMF header data."
	RETURN
ENDIF

* obtaining bounding rectangle for the metafile
cRect = SUBSTR(cHdr,25,16)  && offset to rclFrame in ENHMETAHEADER struct
nRight = buf2dword(SUBSTR(cRect,9,4))
nBottom = buf2dword(SUBSTR(cRect,13,4))

* adjusting frame size and position for the target DC
xoffs = GetDeviceCaps(hPrnDC, PHYSICALOFFSETX)  && prn page left margin
yoffs = GetDeviceCaps(hPrnDC, PHYSICALOFFSETY)  && prn page top margin
hsize = GetDeviceCaps(hPrnDC, HORZSIZE) * 100   && .01 millimeter units
vsize = GetDeviceCaps(hPrnDC, VERTSIZE) * 100   && .01 millimeter units
hres = GetDeviceCaps(hPrnDC, HORZRES)
vres = GetDeviceCaps(hPrnDC, VERTRES)

cRect = num2dword(xoffs) + num2dword(yoffs) +;
	num2dword((xoffs+nRight) * hres/hsize) +;
	num2dword((yoffs+nBottom) * vres/vsize)

* drawing the picture on default printer
cDocinfo = Chr(20) + Repli(Chr(0), 19) && 20 bytes of DOCINFO struct
IF StartDoc(hPrnDC, cDocinfo) > 0
	= StartPage(hPrnDC)
	= PlayEnhMetaFile(hPrnDC, hMeta, @cRect)
	= EndPage(hPrnDC)
	= EndDoc(hPrnDC)
ENDIF

* releasing resources
= DeleteEnhMetaFile(hMeta)
= DeleteDC(hPrnDC)
* end of main

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC In user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER DeleteEnhMetaFile IN gdi32 INTEGER hemf
	DECLARE INTEGER GetEnhMetaFile IN gdi32 STRING lpszMetaFile
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex

	DECLARE INTEGER GetEnhMetaFileHeader In gdi32;
		INTEGER hemf, INTEGER cbBuffer, STRING @lpemh

	DECLARE INTEGER PlayEnhMetaFile IN gdi32;
		INTEGER hdc, INTEGER hemf, STRING @lpRect

	DECLARE INTEGER PrintDlg IN comdlg32 STRING @lppd
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING lpdi

FUNCTION GetDefaultPrnDC
* returns device context for the default printer
#DEFINE PD_RETURNDC         256
#DEFINE PD_RETURNDEFAULT   1024
	LOCAL lcStruct, lnFlags
	lnFlags = PD_RETURNDEFAULT + PD_RETURNDC

	* fill PRINTDLG structure
	lcStruct = num2dword(66) + Repli(Chr(0), 16) +;
		num2dword(lnFlags) + Repli(Chr(0), 42)
	IF PrintDlg(@lcStruct) <> 0
		RETURN buf2dword(SUBSTR(lcStruct, 17,4))
	ENDIF
RETURN  0

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
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteEnhMetaFile](../libraries/gdi32/DeleteEnhMetaFile.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetEnhMetaFile](../libraries/gdi32/GetEnhMetaFile.md)  
[GetEnhMetaFileHeader](../libraries/gdi32/GetEnhMetaFileHeader.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[PlayEnhMetaFile](../libraries/gdi32/PlayEnhMetaFile.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  
