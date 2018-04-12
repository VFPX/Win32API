[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: creating scaled copy of image file

## Before you begin:
The code creates source image object from an image file. It also creates empty destination bitmap object. Note that the Bitmap class is subclassed from the Image class. GDI+ flat API calls allow to use bitmap handles as if they were image handles.  

Then the code uses the graphics of the destination bitmap both as a tool and canvas to draw the scaled source image on it. Finally the destination bitmap saves itself to file.  

The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.   

Make sure the source and destination file names are valid. The source file can be in any of graphics formats supported by the GDI+: BMP, GIF, JPG, TIF, EMF... The destination file type is limited to BMP, JPG, GIF, PNG and TIFF.  

See also:

* [GDI+: cropping images](sample_515.md)  
* [GDI+: rotating images](sample_525.md)  

  
***  


## Code:
```foxpro  
SET PROCEDURE TO gdiplus ADDITIVE

LOCAL cSrcFile, cDstFile, nScale, gdip As gdiplusinit,;
	src As gdiplus_image, dst as gdiplus_bitmap

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
gdip = CREATEOBJECT("gdiplusinit")

cSrcFile = "c:\windows\forest.bmp"
cDstFile = "d:\temp\test.png"
nScale=4

* creating Image object from the source file
src = CREATEOBJECT("gdiimage", cSrcFile)

IF src.himage = 0
	? "Could not load source image file:",;
		src.errorcode
	RETURN
ENDIF

* creating destination Bitmap object,
* setting its dimensions scaled from the source image file
dst = CREATEOBJECT("gdibitmap",;
	src.imgwidth/nScale, src.imgheight/nScale)

* drawing the source file using the graphics object
* of the destination Bitmap
dst.graphics.DrawImage(src, 0,0,;
	src.imgwidth/nScale, src.imgheight/nScale)

IF NOT dst.SaveToFile(cDstFile)
	? "Error code:", dst.errorcode
ELSE
* using default application to open the file
    DECLARE INTEGER ShellExecute IN shell32;
    	INTEGER hwnd, STRING lpOperation,;
    	STRING lpFile, STRING lpParameters,;
    	STRING lpDirectory, INTEGER nShowCmd

	= ShellExecute(0, "open", cDstFile, "", "", 3)
ENDIF  
```  
***  


## Listed functions:
[ShellExecute](../libraries/shell32/ShellExecute.md)  

## Comment:
.Net code: GetThumbnailImage works well when the requested thumbnail image has a size of about  120 x 120.  
  
***  

