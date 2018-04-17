[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateMatrix2
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates and initializes a 3x3 matrix that represents an affine transformation.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateMatrix2(
	REAL m11,
	REAL m12,
	REAL m21,
	REAL m22,
	REAL dx,
	REAL dy,
	GpMatrix **matrix
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateMatrix2 IN gdiplus;
	SINGLE m11,;
	SINGLE m12,;
	SINGLE m21,;
	SINGLE m22,;
	SINGLE dx,;
	SINGLE dy,;
	INTEGER @matrix  
```  
***  


## Parameters:
m11
[in] Real number that specifies the element in the first row, first column. 

m12
[in] Real number that specifies the element in the first row, second column. 

m21
[in] Real number that specifies the element in the second row, first column. 

m22
[in] Real number that specifies the element in the second row, second column. 

dx
[in] Real number that specifies the element in the third row, first column. 

dy
[in] Real number that specifies the element in the third row, second column.

matrix
[out] Handle to the Matrix object.  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  


## Comments:
The affine transformation is a transformation that is a combination of single transformations such as translation or rotation or reflection on an axis.  
  

See also: [GdipCreateMatrix](../gdiplus/GdipCreateMatrix.md), [GdipDeleteMatrix](../gdiplus/GdipDeleteMatrix.md).  
  
***  

