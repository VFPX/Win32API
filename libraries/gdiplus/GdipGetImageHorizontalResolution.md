<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImageHorizontalResolution
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the horizontal resolution of this image.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageHorizontalResolution(
	GpImage *image,
	REAL *resolution
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageHorizontalResolution IN gdiplud;
	INTEGER img,;
	SINGLE @resolution  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image Object

resolution
[out] Resolution of this image in dots per inch.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: GdipGetImageVerticalResolution, GdipGetImageWidth, GdipBitmapSetResolution, GdipGetDpiX   
  
***  

