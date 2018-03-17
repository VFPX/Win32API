<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetPathGradientCenterColor
Group: GDI+ PathGradient Brush - Library: gdiplus    
***  


#### Sets the center color of this path gradient brush. The center color is the color that appears at the brush`s center point.
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
```txt  
brush
Handle of the brush object.

color
ARGB color.  
```  
***  


## Return value:
Returns 0 on success.  
***  

