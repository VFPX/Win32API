[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetDpiX
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the horizontal resolution, in dots per inch, of the display device associated with this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetDpiX(
	GpGraphics *graphics,
	REAL* dpi
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetDpiX IN gdiplus;
	INTEGER graphics,;
	SINGLE @dpi  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

dpi
[out] The horizontal resolution, in dots per inch, of the display device associated with this Graphics handle.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See also: [GdipGetDpiY](../gdiplus/GdipGetDpiY.md), [GdipGetImageHorizontalResolution](../gdiplus/GdipGetImageHorizontalResolution.md), [GdipBitmapSetResolution](../gdiplus/GdipBitmapSetResolution.md).  
  
***  

