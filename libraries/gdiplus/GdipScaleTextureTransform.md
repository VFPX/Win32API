<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipScaleTextureTransform
Group: GDI+ Brush - Library: gdiplus    
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
```txt  
brush
[in] Handle of the brush object.

sx
[in] Real number that specifies the amount to scale in the x direction.
sy
[in] Real number that specifies the amount to scale in the y direction.

order
[in] Optional. Element of the MatrixOrder enumeration that specifies the order of the multiplication.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipCreateTexture, GdipResetTextureTransform   
  
***  

