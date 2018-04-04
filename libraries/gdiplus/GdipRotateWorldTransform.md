[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipRotateWorldTransform
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Updates the world transformation matrix of this Graphics object with the product of itself and a rotation matrix.

***  


## Code examples:
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipRotateWorldTransform(
	GpGraphics *graphics,
	REAL angle,
	GpMatrixOrder order
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipRotateWorldTransform IN gdiplus;
	INTEGER graphics,;
	SINGLE  angle,;
	INTEGER ord
  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

angle
[in] Real number that specifies the angle, in degrees, of rotation. 

order
[in] Element of the MatrixOrder enumeration that specifies the order of multiplication.   
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

