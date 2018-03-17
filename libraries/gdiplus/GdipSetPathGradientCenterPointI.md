<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetPathGradientCenterPointI
Group: GDI+ PathGradient Brush - Library: gdiplus    
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
```txt  
brush
Handle of the brush object.

point
A point to be set as the center.  
```  
***  


## Return value:
Returns 0 on success.  
***  

