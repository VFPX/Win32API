[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetPathGradientCenterColor
Group: [GDI+ PathGradient Brush](../../functions_group.md#GDIplus_PathGradient_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the center color of this path gradient brush. The center color is the color that appears at the brush's center point.
***  


## Code examples:
[GDI+: creating a gradient](../../samples/sample_596.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPathGradientCenterColor(
	GpPathGradient *brush,
	ARGB color
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPathGradientCenterColor IN gdiplus;
	INTEGER brush,;
	INTEGER color  
```  
***  


## Parameters:
brush
Handle of the brush object.

color
ARGB color.  
***  


## Return value:
Returns 0 on success.  
***  

