<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreatePathGradientI
Group: GDI+ PathGradient Brush - Library: gdiplus    
***  


#### Creates a PathGradient Brush object based on an array of points. Initializes the wrap mode of the path gradient brush.
***  


## Code examples:
[GDI+: creating a gradient](../../samples/sample_596.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreatePathGradientI(
	GDIPCONST GpPoint* points,
	INT count,
	GpWrapMode wrapMode,
	GpPathGradient **polyGradient)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreatePathGradientI IN gdiplus;
	STRING @points,;
	INTEGER pointcount,;
	INTEGER wrapMode,;
	INTEGER @polyGradient  
```  
***  


## Parameters:
```txt  
points [in]
Pointer to an array of points that specifies the boundary path of the path gradient brush.

count [in]
Integer that specifies the number of elements in the points array.

wrapMode [in]
Element of the WrapMode enumeration (0 to 4) that specifies how areas painted with the path gradient brush will be tiled.

brush
[out] Handle of the brush object.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the handle, call the GdipDeleteBrush function.  
  
***  

