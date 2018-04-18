[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: sending image of FoxPro form to printer

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.    

Call this code from a method or event of a FoxPro form when that form is active, i.e. posesses the keyboard focus.  

See also:


<!-- Anatoliy -->
<a href="http://www.news2news.com/vfp/?solution=9"><img src="../images/screencapture_270_48.png" width=270 height=48 border=0 alt="Download ScreenCapture Library"></a>   

* [How to print FoxPro form](sample_158.md)  
* [How to print FoxPro form -- II (using metafile)](sample_406.md)  
* [Storing screen shot of a form to a BMP file](sample_187.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
  
***  


## Code:
```foxpro  
SET PROCEDURE TO gdiplus ADDITIVE
#DEFINE SRCCOPY  0x00CC0020
DO decl

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PRIVATE gdiplus
gdiplus = CREATEOBJECT("gdiplusinit")

LOCAL hwindow, hdc, bmp, nWidth, nHeight
hwindow = GetFocus()
hdc = GetWindowDC(hwindow)
STORE 0 TO nWidth, nHeight
= GetWinRect(hwindow, @nWidth, @nHeight)

bmp = CREATEOBJECT("gdibitmap", m.nWidth, m.nHeight)
WITH bmp
	.graphics.GetDC
	= BitBlt(.graphics.hdc, 0,0, .imgwidth, .imgheight,;
		m.hdc, 0,0, SRCCOPY)
	.graphics.ReleaseDC
ENDWITH

LOCAL hPrnDC, gdip, docinfo
hPrnDC = GetPrnDC()
gdip = CREATEOBJECT("graphics", hPrnDC)

docinfo = PADR(CHR(20), 20, CHR(0))
= StartDoc(m.hPrnDC, m.docinfo)
= StartPage(m.hPrnDC)
WITH gdip
	* note that the actual printing is scaled
	.DrawImage(bmp, 20,20,;
		bmp.imgwidth/2, bmp.imgheight/2)

*	.DrawImage(bmp, 20,20)
ENDWITH
= EndPage(m.hPrnDC)
= EndDoc(m.hPrnDC)
= DeleteDC(m.hPrnDC)
= ReleaseDC(m.hwindow, m.hdc)
* end of main

PROCEDURE GetWinRect(hwindow, nWidth, nHeight)
#DEFINE maxDword  0xffffffff
	LOCAL lpRect, nLeft, nTop, nRight, nBottom
	lpRect = REPLI (Chr(0), 16)
	= GetWindowRect (hwindow, @lpRect)
	nRight  = buf2dword(SUBSTR(lpRect, 9,4))
	nBottom = buf2dword(SUBSTR(lpRect, 13,4))

	nLeft = buf2dword(SUBSTR(lpRect, 1,4))
	IF nLeft > nRight
		nLeft = nLeft - maxDword
	ENDIF
	nTop = buf2dword(SUBSTR(lpRect, 5,4))
	IF nTop > nBottom
		nTop = nTop - maxDword
	ENDIF
	nWidth = nRight - nLeft
	nHeight = nBottom - nTop
RETURN

FUNCTION GetPrnDC
* returns device context of default printer
#DEFINE PD_RETURNDC      0x100
#DEFINE PD_RETURNDEFAULT 0x400
	LOCAL lcStruct, lnFlags
	lnFlags = PD_RETURNDEFAULT + PD_RETURNDC

	lcStruct = num2dword(66) + Repli(Chr(0), 16) +;
		num2dword(lnFlags) + Repli(Chr(0), 42)
	IF PrintDlg(@lcStruct) <> 0
		RETURN buf2dword (SUBSTR(lcStruct, 17,4))
	ENDIF
RETURN 0

PROCEDURE decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER PrintDlg IN comdlg32 STRING @ lppd
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING lpdi

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  


***  

