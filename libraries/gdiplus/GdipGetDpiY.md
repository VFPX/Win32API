[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetDpiY
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the vertical resolution, in dots per inch, of the display device associated with this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetDpiY(
	GpGraphics *graphics,
	REAL* dpi
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetDpiY IN gdiplus;
	INTEGER graphics,;
	SINGLE @dpi  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

dpi
[out] The vertical resolution, in dots per inch, of the display device associated with this Graphics handle.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See also: [GdipGetDpiX](../gdiplus/GdipGetDpiX.md), [GdipGetImageVerticalResolution](../gdiplus/GdipGetImageVerticalResolution.md), [GdipBitmapSetResolution](../gdiplus/GdipBitmapSetResolution.md).  
  
***  

