[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipResetWorldTransform
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the world transformation matrix of this Graphics object to the identity matrix.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[GDI+: Using Scale and Shear transformations](../../samples/sample_479.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipResetWorldTransform(
	GpGraphics *graphics
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipResetWorldTransform IN gdiplus;
	INTEGER graphics
  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

