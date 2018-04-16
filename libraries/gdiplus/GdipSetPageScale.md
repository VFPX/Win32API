[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetPageScale
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the scaling factor for the page transformation of this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPageScale(
	GpGraphics *graphics,
	REAL scale
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPageScale IN gdiplus;
	INTEGER graphics,;
	SINGLE scale  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

scale
[in] Real number that specifies the scaling factor.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: [GdipGetPageScale](GdipGetPageScale.md), [GdipSetPageUnit](GdipSetPageUnit.md)   
  
***  

