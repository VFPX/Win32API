[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDrawImageRectRectI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Draws an image optionally using a ImageAttributes object.
***  


## Code examples:
[GDI+: Color Transparency](../../samples/sample_549.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDrawImageRectRectI(
	GpGraphics *graphics,
	GpImage *image,
	INT dstx, INT dsty,
	INT dstwidth, INT dstheight,
	INT srcx, INT srcy,
	INT srcwidth, INT srcheight,
	GpUnit srcUnit,
	GDIPCONST GpImageAttributes* imageAttributes,
	DrawImageAbort callback,
	VOID * callbackData)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDrawImageRectRectI IN gdiplus;
	INTEGER graphics,;
	INTEGER gdiimage,;
	INTEGER dstx,;
	INTEGER dsty,;
	INTEGER dstwidth,;
	INTEGER dstheight,;
	INTEGER srcx,;
	INTEGER srcy,;
	INTEGER srcwidth,;
	INTEGER srcheight,;
	INTEGER srcUnit,;
	INTEGER imageAttributes,;
	INTEGER callback,;
	INTEGER callbackData  
```  
***  


## Parameters:
graphics
[in] Handle of a Graphics object.

image
[in] Handle of a Image object that specifies the source image. 

dstx
[in] Specifies the x-coordinate of the upper-left corner of the destination drawing area.

dsty
[in] Specifies the y-coordinate of the upper-left corner of the destination drawing area.

dstwidth
[in] Specifies the width of the portion of the destination drawing area.

dstheight
[in] Specifies the height of the portion of the destination drawing area.

srcx
[in] Specifies the x-coordinate of the upper-left corner of the portion of the source image to be drawn.

srcy
[in] Specifies the y-coordinate of the upper-left corner of the portion of the source image to be drawn.

srcwidth
[in] Specifies the width of the portion of the source image to be drawn.

srcheight
[in] Specifies the height of the portion of the source image to be drawn.

srcUnit
[in] Element of the Unit enumeration that specifies the unit of measure for the image.

imageAttributes
[in] Handle to a ImageAttributes object. Can be NULL.

callback
[in] Pointer to a callback procedure used to cancel the drawing in progress. Can be NULL.

callbackData
[in] Pointer to additional data used by the method specified by the callback parameter. Can be NULL.
  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
This function can be used for drawing images with colors or color ranges made transparent.  
  
See also: [GdipDrawImageRectI](../gdiplus/GdipDrawImageRectI.md), [AlphaBlend](../msimg32/AlphaBlend.md).  
  
***  

