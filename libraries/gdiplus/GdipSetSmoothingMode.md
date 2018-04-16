[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetSmoothingMode
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the rendering quality of the Graphics object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetSmoothingMode(
	GpGraphics *graphics,
	SmoothingMode smoothingMode)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetSmoothingMode IN gdiplus;
	INTEGER graphics,;
	INTEGER smoothingMode  
```  
***  


## Parameters:
graphics
[in] Handle of a Graphics object.

smoothingMode
[in] Element of the SmoothingMode enumeration.  
***  


## Return value:
Returns Ok (0) if succeeded.  
***  


## Comments:
See also: [GdipGetSmoothingMode](../gdiplus/GdipGetSmoothingMode.md).  
  
[SmoothingMode enumeration](http://msdn.microsoft.com/en-us/library/windows/desktop/ms534173(v=vs.85).aspx).  
  
***  

