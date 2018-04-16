[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetPageUnit
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the unit of measure for this Graphics handle. 
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPageUnit(
	GpGraphics *graphics,
	GpUnit unit
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPageUnit IN gdiplus;
	INTEGER graphics,;
	INTEGER unit  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.

unit
[in] Element of the Unit enumeration that specifies the unit of measure for this Graphics handle.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The page unit belongs to the page transformation, which converts page coordinates to device coordinates.  
  
See Also: [GdipGetPageUnit](GdipGetPageUnit.md)   
  
***  

