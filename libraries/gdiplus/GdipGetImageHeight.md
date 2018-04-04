[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageHeight
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the height, in pixels, of this image.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageHeight(
	GpImage *image,
	UINT *height
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageHeight IN gdiplus;
	INTEGER   img,;
	INTEGER @ imgheight  
```  
***  


## Parameters:
img
[in] Handle to Image Object

imgwidth
[out] Height of this image in pixels.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

