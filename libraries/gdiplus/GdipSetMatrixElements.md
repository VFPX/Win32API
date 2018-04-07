[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetMatrixElements
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the elements of this matrix.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetMatrixElements(
	GpMatrix *matrix,
	REAL m11,
	REAL m12,
	REAL m21,
	REAL m22,
	REAL dx,
	REAL dy
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetMatrixElements IN gdiplus;
	INTEGER matrix,;
	SINGLE m11,;
	SINGLE m12,;
	SINGLE m21,;
	SINGLE m22,;
	SINGLE dx,;
	SINGLE dy  
```  
***  


## Parameters:
matrix
[in] Handle to a Matrix object.

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
  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  


## Comments:
See also: [GdipGetMatrixElements](../gdiplus/GdipGetMatrixElements.md).  
  
***  

