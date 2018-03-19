
## Function name : GdipInvertMatrix
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
matrix
[in] Handle to a Matrix object.
  
***  


## Return value:
Returns GpStatus value; 0 means success.  
***  

