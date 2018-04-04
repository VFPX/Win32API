[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipRotateMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates this matrix with the product of itself and a rotation matrix.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipRotateMatrix(
	GpMatrix *matrix,
	REAL angle,
	GpMatrixOrder order
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipRotateMatrix IN gdiplus;
	INTEGER matrix,;
	SINGLE angle,;
	INTEGER ord  
```  
***  


## Parameters:
matrix
[in] Handle to the Matrix object.

angle
[in] Real number that specifies the angle, in degrees, of rotation.

order
[in] Element of the MatrixOrder enumeration that specifies the order of multiplication.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

