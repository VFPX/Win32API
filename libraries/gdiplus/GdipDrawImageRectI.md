[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDrawImageRectI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Draws an image
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDrawImageRectI(
	GpGraphics *graphics,
	GpImage *image,
	INT x,
	INT y,
	INT width,
	INT height
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDrawImageRectI IN gdiplus;
	INTEGER graphics,;
	INTEGER img,;
	INTEGER x,;
	INTEGER y,;
	INTEGER imgwidth,;
	INTEGER imgheight  
```  
***  


## Parameters:
graphics
[in] Pointer to a Graphics object.

image
[in] Pointer to an Image object that specifies the source image. 

x
[in] Integer that specifies the x-coordinate of the upper-left corner of the destination rectangle at which to draw the image. 

y
[in] Integer that specifies the y-coordinate of the upper-left corner of the destination rectangle at which to draw the image. 

width
[in] Integer that specifies the width of the destination rectangle at which to draw the image. 
height
[in] Integer that specifies the height of the destination rectangle at which to draw the image. 
  
***  


## Return value:
If succeeds, it returns Ok, which is an element of the Status enumeration.  
***  

