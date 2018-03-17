<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipBitmapSetPixel
Group: GDI+ Bitmap - Library: gdiplus    
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
```txt  
gdibitmap
[in] Handle to a GDI bitmap.

x
[in] Integer X-coordinate of pixel to get.

y
[in] Integer Y-coordinate of pixel to get.

argbcolor
[in] ARGB color value to be set for the pixel.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipBitmapGetPixel   
  
***  

