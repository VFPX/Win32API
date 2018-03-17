<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateMatrix
Group: GDI+ Matrix - Library: gdiplus    
***  


#### Creates and initializes a Matrix object that represents the identity matrix.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateMatrix(GpMatrix **matrix)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateMatrix IN gdiplus;
	INTEGER @ matrix  
```  
***  


## Parameters:
```txt  
matrix
[out] Handle to the Matrix object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success. 
  
***  


## Comments:
A transformation matrix that doesn"t have any effect when applied to a point. Technically, the matrix is composed of all zeros with just the diagonal having ones.  
  
See also: GdipCreateMatrix2, GdipDeleteMatrix.  
  
***  

