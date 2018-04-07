[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipBitmapSetPixel
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the color value of an individual pixel.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipBitmapSetPixel(
	GpBitmap* bitmap,
	INT x, INT y, ARGB color)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipBitmapSetPixel IN gdiplus;
	INTEGER gdibitmap,;
	INTEGER x,;
	INTEGER y,;
	INTEGER argbcolor  
```  
***  


## Parameters:
gdibitmap
[in] Handle to a GDI bitmap.

x
[in] Integer X-coordinate of pixel to get.

y
[in] Integer Y-coordinate of pixel to get.

argbcolor
[in] ARGB color value to be set for the pixel.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipBitmapGetPixel](../gdiplus/GdipBitmapGetPixel.md).  
  
***  

