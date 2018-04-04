[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCloneBitmapArea
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a new Bitmap object by copying a portion of this bitmap.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCloneBitmapArea(
	REAL x,
	REAL y,
	REAL width,
	REAL height,
	PixelFormat format,
	GpBitmap *srcBitmap,
	GpBitmap **dstBitmap
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCloneBitmapArea IN gdiplus;
	SINGLE    x,;
	SINGLE    y,;
	SINGLE    width,;
	SINGLE    height,;
	INTEGER   fmt,;
	INTEGER   srcBitmap,;
	INTEGER @ dstBitmap
  
```  
***  


## Parameters:
x
[in] Real number that specifies the x-coordinate of the upper-left corner of the rectangle that specifies the portion of this bitmap to copy. 

y
[in] Real number that specifies the y-coordinate of the upper-left corner of the rectangle that specifies the portion of this bitmap to copy. 

width
[in] Real number that specifies the width of the rectangle that specifies the portion of this bitmap to copy. 

height
[in] Real number that specifies the height of the rectangle that specifies the portion of this image to copy. 

format
[in] Integer that specifies the pixel format of the new bitmap.

srcbitmap
[in] Handle to source GDI+ bitmap object.

dstbitmap
[out] Handle to new GDI+ bitmap object.
  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
// In-memory pixel data formats:  
// bits 0-7 = format index  
// bits 8-15 = pixel size (in bits)  
// bits 16-23 = flags  
// bits 24-31 = reserved  
  
***  

