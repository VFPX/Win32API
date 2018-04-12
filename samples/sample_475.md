[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: Storing content of the Clipboard to a bitmap file

## Short description:
Based on GdiPlus class, this code shows how to retrieve an image stored on the clipboard and save it to a graphics file in one of GDI+ supported formats, BMP, GIF. PNG, TIFF, JPEG.  
***  


## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.   

Related code samples:  
* [Storing content of the Clipboard to a bitmap file using GDI API](sample_189.md)  
* [GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](sample_457.md)  
* [Copying picture of the active form to the Clipboard using Bitmap API functions](sample_091.md)  
* [Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](sample_404.md)  
* [Storing screen shot of a form to a bitmap file](sample_187.md)  

  
***  


## Code:
```foxpro  
SET PROCEDURE TO gdiplus ADDITIVE
#DEFINE CF_BITMAP 2
#DEFINE CF_DIB    8
DO decl

IF IsClipboardFormatAvailable(CF_DIB)=0
	= MESSAGEBOX("No image data found stored " +;
		"on the clipboard.   ")
	RETURN
ENDIF

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PRIVATE gdiplus As gdiplusinit, img As gdibitmap
gdiplus = CREATEOBJECT("gdiplusinit")

= OpenClipboard(0)

LOCAL bmp As gdibitmap, hBitmap, hDib, lResult
hBitmap = GetClipboardData(CF_BITMAP)
hDib = GetClipboardData(CF_DIB)
bmp = CREATEOBJECT("gdibitmap")

* use either of two ways to create an instance
* of the gdibitmap object
*lResult = bmp.CreateFromHBITMAP(hBitmap)
lResult = bmp.CreateFromBITMAPINFO(hDib)

IF lResult
* make sure the target folder is valid
* uncomment one or more lines with savetofile
*!*		bmp.savetofile("c:\temp\tmp.jpg")
*!*		bmp.savetofile("c:\temp\tmp.gif")
*!*		bmp.savetofile("c:\temp\tmp.bmp")
*!*		bmp.savetofile("c:\temp\tmp.tif")
*!*		bmp.savetofile("c:\temp\tmp.png")
ENDIF

= CloseClipboard()
* end of main

PROCEDURE decl
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER GetClipboardData IN user32 INTEGER uFormat

	DECLARE INTEGER IsClipboardFormatAvailable IN user32;
		INTEGER wFormat  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[GetClipboardData](../libraries/user32/GetClipboardData.md)  
[IsClipboardFormatAvailable](../libraries/user32/IsClipboardFormatAvailable.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  

## Comment:
When an image is copied, most likely it creates on the clipboard at least three different blocks of data:  
- Bitmap handle (CF_BITMAP)  
- BITMAPINFO structure (CF_DIB)  
- BITMAPV5HEADER structure (CF_DIBV5)  
  
This code above retrieves data in CF_DIB format from the clipboard and passes it to the GdipCreateBitmapFromGdiDib function to create an instance of GDI+ bitmap object. This newly created object can be saved to a file, printed or painted on a window.  
  
The GetClipboardData returns a pointer to a memory object containing a BITMAPINFO structure followed by the bitmap bits.   
  
There is a simplification in the way the code treats the BITMAPINFO data. For some display resolutions, like 1, 4, 8 and rarely 16 bits per pixel, the BITMAPINFO structure may contain a color table. If you are able to use GDI+ and Visual FoxPro, most likely your display resolution does not require a presence of such color table in the BITMAPINFO structure. That is how this structure is believed to contain only 40 bytes occupied by BITMAPINFOHEADER data.  
  
* * *  
Same way the GetClipboardData call with CF_BITMAP as input parameter can retrieve a bitmap handle. This handle then can be passed to the GdipCreateBitmapFromHBITMAP function to create an instance of GDI+ bitmap object. This newly created object can be saved to a file, printed or painted on a window.  
  
***  

