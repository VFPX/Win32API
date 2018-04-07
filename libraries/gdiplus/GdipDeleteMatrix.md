[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteMatrix
Group: [GDI+ Matrix](../../functions_group.md#GDIplus_Matrix)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Deletes the Matrix object created by GdipCreateMatrix, GdipCloneMatrix and similar functions.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteMatrix(GpMatrix *matrix)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteMatrix IN gdiplus;
	INTEGER matrix  
```  
***  


## Parameters:
matrix
[in] Handle to a Matrix object.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
  
***  


## Comments:
See also: [GdipCreateMatrix](../gdiplus/GdipCreateMatrix.md).  
  
***  

