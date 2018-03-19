[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageWidth
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the width, in pixels, of this image.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageWidth(
	GpImage *image,
	UINT *width
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageWidth IN gdiplus;
	INTEGER   img,;
	INTEGER @ imgwidth  
```  
***  


## Parameters:
img
[in] Handle to Image Object

imgwidth
[out]  Width of this image in pixels.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

