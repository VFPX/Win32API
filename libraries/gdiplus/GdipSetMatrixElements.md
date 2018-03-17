<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetMatrixElements
Group: GDI+ Matrix - Library: gdiplus    
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
```txt  
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
  
```  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  


## Comments:
See also: GdipGetMatrixElements.  
  
***  

