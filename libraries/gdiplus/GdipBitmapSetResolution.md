<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipBitmapSetResolution
Group: GDI+ Bitmap - Library: gdiplus    
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
```txt  
gdibitmap
[in] Handle to a GDI bitmap.

xdpi
[in] Real number that specifies the horizontal resolution in dots per inch.

ydpi
[in] Real number that specifies the vertical resolution in dots per inch.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipGetDpiX, GdipGetDpiY, GdipGetImageHorizontalResolution, GdipGetImageVerticalResolution   
  
***  

