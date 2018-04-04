[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateBitmapFromGraphics
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
width
[in] Integer that specifies the width, in pixels, of the bitmap. 

height
[in] Integer that specifies the height, in pixels, of the bitmap. 

target
[in] Handle to a GDI+ Graphics object. 

bitmap
[out] Handle to the GDI+ bitmap object.  
***  


## Return value:
Returns 0 on success.  
***  

