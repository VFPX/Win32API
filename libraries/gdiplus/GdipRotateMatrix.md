<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipRotateMatrix
Group: GDI+ Matrix - Library: gdiplus    
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
```txt  
matrix
[in] Handle to the Matrix object.

angle
[in] Real number that specifies the angle, in degrees, of rotation.

order
[in] Element of the MatrixOrder enumeration that specifies the order of multiplication.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

