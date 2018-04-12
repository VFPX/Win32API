[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: printing image file

## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.  

Make sure the source file name is valid. The source file can be in any of graphics formats supported by the GDI+: BMP, GIF, JPG, TIF, EMF...  

See also:

* [Printing Image File, programmatically set print page orientation to landscape](sample_555.md)  
* [How to display the Print property sheet](sample_531.md)  
  
***  


## Code:
```foxpro  
SET PROCEDURE TO gdiplus ADDITIVE
DO decl

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PRIVATE gdiplus
gdiplus = CREATEOBJECT("gdiplusinit")

LOCAL img, hPrnDC, gdip, docinfo
hPrnDC = GetPrnDC()
img = CREATEOBJECT("gdiimage", "c:\windows\forest.bmp")
gdip = CREATEOBJECT("graphics", hPrnDC)

docinfo = PADR(CHR(20), 20, CHR(0))
= StartDoc(m.hPrnDC, m.docinfo)
= StartPage(m.hPrnDC)
WITH gdip
	.DrawImage(img, 20,20)
	.DrawImage(img, 25+img.imgwidth,20,;
		img.imgwidth/4, img.imgheight/4)
ENDWITH
= EndPage(m.hPrnDC)
= EndDoc(m.hPrnDC)
= DeleteDC(hPrnDC)
* end of main

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
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER PrintDlg IN comdlg32 STRING @ lppd
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING lpdi  
```  
***  


## Listed functions:
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  

***  

