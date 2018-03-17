<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipInvertMatrix
Group: GDI+ Matrix - Library: gdiplus    
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
```txt  
matrix
[in] Handle to a Matrix object.
  
```  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  

