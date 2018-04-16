[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipTranslateWorldTransform
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates this Graphics object"s world transformation matrix with the product of itself and a translation matrix.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipTranslateWorldTransform(
	GpGraphics *graphics,
	REAL dx,
	REAL dy,
	GpMatrixOrder order
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipTranslateWorldTransform IN gdiplus;
	INTEGER graphics,;
	SINGLE  dx,;
	SINGLE  dy,;
	INTEGER ord
  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

dx
[in] Real number that specifies the horizontal component of the translation. 

dy
[in] Real number that specifies the vertical component of the translation. 

order
[in] Element of the MatrixOrder enumeration that specifies the order of multiplication.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
```cpp
typedef enum {  
    MatrixOrderPrepend = 0,  
    MatrixOrderAppend = 1  
} MatrixOrder;
```
  
<Em>MatrixOrderPrepend</Em>  
Specifies that the new matrix is on the left and the existing matrix is on the right.   
  
<Em>MatrixOrderAppend</Em>  
Specifies that the existing matrix is on the left and the new matrix is on the right.  
  
***  

