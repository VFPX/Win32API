
## Function name : GdipGetImageHeight
Group: GDI+ Image - Library: gdiplus    
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

