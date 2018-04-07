[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetClipRectI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the clipping region of this Graphics object by a specified rectangle.
***  


## Code examples:
[GDI+: Scrolling through large image using the mouse](../../samples/sample_546.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetClipRectI(
	GpGraphics *graphics,
	INT x, INT y,
	INT width, INT height,
	CombineMode combineMode
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetClipRectI IN gdiplus;
	INTEGER graphics,;
	INTEGER x,;
	INTEGER y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER combineMode  
```  
***  


## Parameters:
graphics
[in] Pointer to a Graphics object.

x
[in] Specifies the logical x-coordinate of the upper-left corner of the rectangle.

y
[in] Specifies the logical y-coordinate of the upper-left corner of the rectangle.

width
[in] Specifies the logical width of the rectangle.

height
[in] Specifies the logical height of the rectangle.

combineMode
[in] Element of the CombineMode enumeration that specifies how the specified rectangle is combined with the clipping region of this Graphics object.  
***  


## Return value:
If the function succeeds, it returns Ok (0).  
***  


## Comments:
See also: [GdipResetClip](..//GdipResetClip.md).  
  
***  

