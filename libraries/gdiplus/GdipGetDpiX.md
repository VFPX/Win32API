
## Function name : GdipGetDpiX
Group: GDI+ Graphics - Library: gdiplus    
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
See also: GdipGetDpiY, GdipGetImageHorizontalResolution, GdipBitmapSetResolution   
  
***  

