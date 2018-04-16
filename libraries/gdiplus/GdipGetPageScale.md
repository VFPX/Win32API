[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetPageScale
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the scaling factor currently set for the page transformation of this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPageScale(
	GpGraphics *graphics,
	REAL *scale
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPageScale IN gdiplus;
	INTEGER graphics,;
	SINGLE @scale  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

scale
[out] Real number that specifies the scaling factor currently set for this Graphics handle.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The page transformation converts page coordinates to device coordinates.  
  
See Also: [GdipSetPageScale](GdipSetPageScale.md), [GdipGetPageUnit](GdipGetPageUnit.md)   
  
***  

