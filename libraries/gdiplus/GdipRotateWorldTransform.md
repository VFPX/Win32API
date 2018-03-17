<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipRotateWorldTransform
Group: GDI+ Graphics - Library: gdiplus    
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
```txt  
graphics
[in] Handle to the Graphics object.

angle
[in] Real number that specifies the angle, in degrees, of rotation.

order
[in] Element of the MatrixOrder enumeration that specifies the order of multiplication.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

