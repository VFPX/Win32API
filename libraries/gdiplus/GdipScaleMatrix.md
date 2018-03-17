<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipScaleMatrix
Group: GDI+ Matrix - Library: gdiplus    
***  


#### Updates this matrix with the product of itself and a scaling matrix.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipScaleMatrix(
	GpMatrix *matrix,
	REAL scaleX,
	REAL scaleY,
	GpMatrixOrder order
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipScaleMatrix IN gdiplus;
	INTEGER matrix,;
	SINGLE  scaleX,;
	SINGLE  scaleY,;
	INTEGER ord
  
```  
***  


## Parameters:
```txt  
matrix
[in] Handle to a Matrix object.

scaleX
[in] Real number that specifies the horizontal scale factor.

scaleY
[in] Real number that specifies the vertical scale factor.

order
[in] Element of the MatrixOrder enumeration that specifies the order of the multiplication.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

