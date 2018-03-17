<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipResetWorldTransform
Group: GDI+ Graphics - Library: gdiplus    
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
```txt  
graphics
[in] Handle to the Graphics object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

