[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipTranslateMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates this matrix with the product of itself and a translation matrix.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipTranslateMatrix(
	GpMatrix *matrix,
	REAL offsetX,
	REAL offsetY,
	GpMatrixOrder order
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipTranslateMatrix IN gdiplus;
	INTEGER matrix,;
	SINGLE  offsetX,;
	SINGLE  offsetY,;
	INTEGER ord
  
```  
***  


## Parameters:
matrix
[in] Handle to the Matrix object.

offsetX
[in] Real number that specifies the horizontal component of the translation. 

offsetY
[in] Real number that specifies the vertical component of the translation. 

order
[in] Element of the MatrixOrder enumeration that specifies the order of the multiplication.   
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

