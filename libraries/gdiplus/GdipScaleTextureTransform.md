[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipScaleTextureTransform
Group: [GDI+ Brush](../../functions_group.md#GDIplus_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates this texture brush"s current transformation matrix with the product of itself and a scaling matrix.
***  


## Code examples:
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipScaleTextureTransform(
	GpTexture* brush,
	REAL sx,
	REAL sy,
	GpMatrixOrder order
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipScaleTextureTransform IN gdiplus;
	INTEGER brush,;
	SINGLE sx,;
	SINGLE sy,;
	INTEGER matrixorder  
```  
***  


## Parameters:
brush
[in] Handle of the brush object.

sx
[in] Real number that specifies the amount to scale in the x direction.
sy
[in] Real number that specifies the amount to scale in the y direction.

order
[in] Optional. Element of the MatrixOrder enumeration that specifies the order of the multiplication.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipCreateTexture](../gdiplus/GdipCreateTexture.md), [GdipResetTextureTransform](..//GdipResetTextureTransform.md).  
  
***  

