[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipShearMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates this matrix with the product of itself and a shearing matrix.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipShearMatrix(
	GpMatrix *matrix,
	REAL shearX,
	REAL shearY,
	GpMatrixOrder order
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipShearMatrix IN gdiplus;
	INTEGER matrix,;
	SINGLE  shearX,;
	SINGLE  shearY,;
	INTEGER ord
  
```  
***  


## Parameters:
matrix
[in] Handle to a Matrix object. 

shearX
[in] Real number that specifies the horizontal shear factor. 

shearY
[in] Real number that specifies the vertical shear factor. 

order
[in] Element of the MatrixOrder enumeration that specifies the order of the multiplication.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

