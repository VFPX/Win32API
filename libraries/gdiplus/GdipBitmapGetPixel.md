[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipBitmapGetPixel
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the color value of an individual pixel.
***  


## Code examples:
[GDI+: Color Transparency](../../samples/sample_549.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipBitmapGetPixel(
	GpBitmap* bitmap,
	INT x, INT y, ARGB *color)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipBitmapGetPixel IN gdiplus;
	INTEGER gdibitmap,;
	INTEGER x,;
	INTEGER y,;
	LONG @argbcolor  
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
[out] ARGB color value of the pixel.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipBitmapSetPixel](../gdiplus/GdipBitmapSetPixel.md).  
  
***  

