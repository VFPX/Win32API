<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImageVerticalResolution
Group: GDI+ Image - Library: gdiplus    
***  


#### Sets the vertical resolution of this image.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageVerticalResolution(
	GpImage *image,
	REAL *resolution
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageVerticalResolution IN gdiplud;
	INTEGER img,;
	SINGLE @resolution  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image Object

resolution
[in] Resolution to be set in dots per inch.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: GdipGetImageHorizontalResolution, GdipGetImageHeight, GdipBitmapSetResolution, GdipGetDpiY   
  
***  

