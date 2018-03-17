<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteMatrix
Group: GDI+ Matrix - Library: gdiplus    
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
```txt  
matrix
[in] Handle to a Matrix object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
  
***  


## Comments:
See also: GdipCreateMatrix.  
  
***  

