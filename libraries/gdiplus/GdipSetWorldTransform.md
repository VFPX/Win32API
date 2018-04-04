[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetWorldTransform
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the world transformation of this Graphics object.

***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetWorldTransform(
	GpGraphics *graphics,
	GpMatrix *matrix
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetWorldTransform IN gdiplus;
	INTEGER graphics,;
	INTEGER matrix
  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object. 

matrix
[in] Handle to a Matrix object.  
***  


## Return value:
Returns GpStatus value, 0 means success.   
***  

