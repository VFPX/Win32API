[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateTexture
Group: [GDI+ Brush](../../functions_group.md#GDIplus_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a brush that contains an Image object that is used for the fill.
***  


## Code examples:
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateTexture(
	GpImage *image,
	GpWrapMode wrapmode,
	GpTexture **texture
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateTexture IN gdiplus;
	INTEGER img,;
	LONG wrapmode,;
	INTEGER @texture  
```  
***  


## Parameters:
image
[in] Handle to Image Object

wrapmode
[in] Element of the WrapMode enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush.

texture
[out] Handle of the brush object.
  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipCreateSolidFill](../gdiplus/GdipCreateSolidFill.md), [GdipDeleteBrush](../gdiplus/GdipDeleteBrush.md), [GdipFillRectangle](../gdiplus/GdipFillRectangle.md).  
  
***  

