[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipInvertMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### For invertible matrix, replaces the elements of this matrix with the elements of its inverse.


***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipInvertMatrix(
	GpMatrix *matrix
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipInvertMatrix IN gdiplus;
	INTEGER matrix
  
```  
***  


## Parameters:
matrix
[in] Handle to a Matrix object.
  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  

