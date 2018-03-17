<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImageWidth
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
```txt  
img
[in] Handle to Image Object

imgwidth
[out]  Width of this image in pixels.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

