<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateBitmapFromGraphics
Group: GDI+ Bitmap - Library: gdiplus    
***  


#### Creates a Bitmap object based on a Graphics object, a width, and a height.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateBitmapFromGraphics(
	INT width,
	INT height,
	GpGraphics* target,
	GpBitmap** bitmap
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateBitmapFromGraphics IN gdiplus;
	INTEGER   width,;
	INTEGER   height,;
	INTEGER   graphics,;
	INTEGER @ bitmap
  
```  
***  


## Parameters:
```txt  
width
[in] Integer that specifies the width, in pixels, of the bitmap.

height
[in] Integer that specifies the height, in pixels, of the bitmap.

target
[in] Handle to a GDI+ Graphics object.

bitmap
[out] Handle to the GDI+ bitmap object.  
```  
***  


## Return value:
Returns 0 on success.  
***  

