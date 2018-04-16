[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageHorizontalResolution
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
See Also: 

[GdipGetImageVerticalResolution](GdipGetImageVerticalResolution.md), [GdipGetImageWidth](GdipGetImageWidth.md), [GdipBitmapSetResolution](GdipBitmapSetResolution.md), [GdipGetDpiX](GdipGetDpiX.md)   
  
***  

