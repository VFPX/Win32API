[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to print FoxPro form -- II

## Before you begin:
Call this code from a method or event of FoxPro form to print image of the form on your default printer. Window handle of the form is obtained through GetFocus function. That is why this form has to be active, possessing the keyboard focus.  

This code sample is based on Enhanced Metafile API functions. In a similar example [How to print a FoxPro form](sample_158.md) a "bitmap" approach is used.  

Enhanced metfaile functions make this code sample comparatively short and easy to understand.  

See also:

* [How to print FoxPro form (GDI)](sample_158.md)  
* [GDI+: sending image of FoxPro form to printer ](sample_455.md)  
* [Storing screen shot of a form to a BMP file](sample_187.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a BMP file](sample_211.md)  
  
***  


## Code:
```foxpro  
#DEFINE PHYSICALOFFSETX  112
#DEFINE PHYSICALOFFSETY  113
#DEFINE HORZSIZE  4
#DEFINE VERTSIZE  6
#DEFINE HORZRES   8
#DEFINE VERTRES   10
#DEFINE SRCCOPY  0xCC0020

DO decl

LOCAL hWndSrc, hDCSrc, hPrnDC, hMetaDC, hMetaFile, xScale, yScale,;
		nWidth, nHeight, rcMeta, cDocinfo

* obtaining device context for the default printer
hPrnDC = GetDefaultPrnDC()
IF hPrnDC = 0
	? "Default printer is not available."
	RETURN
ENDIF

hWndSrc = GetFocus()
hDCSrc = GetWindowDC(hWndSrc)

* obtaining width and height for the source DC
rcMeta = Repli(Chr(0),16)
= GetWindowRect(hWndSrc, @rcMeta)
nWidth = buf2dword(SUBSTR(rcMeta,9,4)) - buf2dword(SUBSTR(rcMeta,1,4)) + 1
nHeight = buf2dword(SUBSTR(rcMeta,13,4)) - buf2dword(SUBSTR(rcMeta,5,4)) + 1

* drawing the picture on metafile device context
rcMeta = num2dword(0) + num2dword(0) +;
	num2dword(nWidth) + num2dword(nHeight)
hMetaDC = CreateEnhMetaFile(hDCSrc, Null, @rcMeta, Null)
= BitBlt(hMetaDC, 0,0, nWidth, nHeight, hDCSrc, 0,0, SRCCOPY)
hMetaFile = CloseEnhMetaFile(hMetaDC)

* scaling factor values from screen to printer
xScale = GetDeviceCaps(hPrnDC, HORZRES)/(GetDeviceCaps(hPrnDC, HORZSIZE) * 100)
yScale = GetDeviceCaps(hPrnDC, VERTRES)/(GetDeviceCaps(hPrnDC, VERTSIZE) * 100)
rcMeta = num2dword(0) + num2dword(0) +;
	num2dword(nWidth*xScale) + num2dword(nHeight*yScale)

* drawing the picture on default printer
cDocinfo = PADR(Chr(20),19,Chr(0)) && 20 bytes of DOCINFO struct
IF StartDoc(hPrnDC, cDocinfo) > 0
	= StartPage(hPrnDC)
	= PlayEnhMetaFile(hPrnDC, hMetaFile, @rcMeta)
	= EndPage(hPrnDC)
	= EndDoc(hPrnDC)
ENDIF

* releasing system resources
= DeleteEnhMetaFile(hMetaFile)
= DeleteDC(hPrnDC)
= ReleaseDC(hWndSrc, hDCSrc)
* end of main

PROCEDURE decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER GetWindowDC In user32 INTEGER hwnd
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex
	DECLARE INTEGER CloseEnhMetaFile IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteEnhMetaFile IN gdi32 INTEGER hemf
	DECLARE INTEGER PrintDlg IN comdlg32 STRING @ lppd
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING lpdi

	DECLARE INTEGER CreateEnhMetaFile IN gdi32;
		INTEGER hdcRef, STRING lpFilename,;
		STRING @lpRect, STRING lpDescription

	DECLARE INTEGER PlayEnhMetaFile IN gdi32;
		INTEGER hdc, INTEGER hemf, STRING @lpRect

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

FUNCTION GetDefaultPrnDC
* returns device context for the default printer
#DEFINE PD_RETURNDC       256
#DEFINE PD_RETURNDEFAULT  1024
	LOCAL cStruct, nFlags
	nFlags = PD_RETURNDEFAULT + PD_RETURNDC
	cStruct = num2dword(66) + Repli(Chr(0), 16) +;
		num2dword(nFlags) + Repli(Chr(0), 42)
	IF PrintDlg(@cStruct) <> 0
		RETURN buf2dword(SUBSTR(cStruct, 17,4))
	ENDIF
RETURN 0

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
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CloseEnhMetaFile](../libraries/gdi32/CloseEnhMetaFile.md)  
[CreateEnhMetaFile](../libraries/gdi32/CreateEnhMetaFile.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteEnhMetaFile](../libraries/gdi32/DeleteEnhMetaFile.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[PlayEnhMetaFile](../libraries/gdi32/PlayEnhMetaFile.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  


***  

