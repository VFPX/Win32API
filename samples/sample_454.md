[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF)

## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.   

Make sure the target file name is valid. The target file can be created in several graphics format supported by the GDI+: BMP, GIF, JPG, TIF.  

Call this code from a method or event of a FoxPro form when that form is active, i.e. posesses the keyboard focus.  

See also:

* [GDI: Storing screen shot of a form to bitmap file](sample_187.md)  
* [Printing the image of a FoxPro form](sample_158.md)  
* [Storing clipboard contents to a BMP file](sample_189.md)  
* [Using the LoadImage() to display a BMP file on the main VFP window](sample_210.md)  
* [How to print a bitmap file](sample_211.md)  

  
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
	.SaveToFile("d:\temp\vfp.tif")	
ENDWITH

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

PROCEDURE decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  

***  

