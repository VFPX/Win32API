[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetPathGradientCenterPointI
Group: [GDI+ PathGradient Brush](../../functions_group.md#GDIplus_PathGradient_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the center point of this path gradient brush.
***  


## Code examples:
[GDI+: creating a gradient](../../samples/sample_596.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPathGradientCenterPointI(
	GpPathGradient *brush,
	GDIPCONST GpPoint* point
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPathGradientCenterPointI IN gdiplus;
	INTEGER brush,;
	STRING @point  
```  
***  


## Parameters:
brush
Handle of the brush object.

point
A point to be set as the center.  
***  


## Return value:
Returns 0 on success.  
***  

