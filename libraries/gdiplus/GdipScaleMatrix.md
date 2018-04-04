[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipScaleMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
matrix
[in] Handle to a Matrix object.

scaleX
[in] Real number that specifies the horizontal scale factor. 

scaleY
[in] Real number that specifies the vertical scale factor. 

order
[in] Element of the MatrixOrder enumeration that specifies the order of the multiplication.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

