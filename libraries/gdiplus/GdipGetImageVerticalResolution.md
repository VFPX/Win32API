[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageVerticalResolution
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
img
[in] Handle to Image Object

resolution
[in] Resolution to be set in dots per inch.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: [GdipGetImageHorizontalResolution](GdipGetImageHorizontalResolution.md), [GdipGetImageHeight](GdipGetImageHeight.md), [GdipBitmapSetResolution](GdipBitmapSetResolution.md), [GdipGetDpiY](GdipGetDpiY.md)   
  
***  

