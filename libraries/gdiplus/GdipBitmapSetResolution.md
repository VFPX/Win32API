[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipBitmapSetResolution
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the resolution of this Bitmap object.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipBitmapSetResolution(
	GpBitmap* bitmap,
	REAL xdpi,
	REAL ydpi
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipBitmapSetResolution IN gdiplus;
	INTEGER hbm,;
	SINGLE xdpi,;
	SINGLE ydpi  
```  
***  


## Parameters:
gdibitmap
[in] Handle to a GDI bitmap.

xdpi
[in] Real number that specifies the horizontal resolution in dots per inch. 

ydpi
[in] Real number that specifies the vertical resolution in dots per inch.   
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipGetDpiX](../gdiplus/GdipGetDpiX.md), [GdipGetDpiY](../gdiplus/GdipGetDpiY.md), [GdipGetImageHorizontalResolution](../gdiplus/GdipGetImageHorizontalResolution.md), [GdipGetImageVerticalResolution](../gdiplus/GdipGetImageVerticalResolution.md).  
  
***  

