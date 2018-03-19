
## Function name : GdipGetImageHorizontalResolution
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
img
[in] Handle to Image Object

resolution
[out] Resolution of this image in dots per inch.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: GdipGetImageVerticalResolution, GdipGetImageWidth, GdipBitmapSetResolution, GdipGetDpiX   
  
***  

