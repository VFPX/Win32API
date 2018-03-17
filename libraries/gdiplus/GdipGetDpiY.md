<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetDpiY
Group: GDI+ Graphics - Library: gdiplus    
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
```txt  
graphics
[in] Handle to the Graphics object.

dpi
[out] The vertical resolution, in dots per inch, of the display device associated with this Graphics handle.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See also: GdipGetDpiX, GdipGetImageVerticalResolution, GdipBitmapSetResolution   
  
***  

