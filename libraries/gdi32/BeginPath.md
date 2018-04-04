[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : BeginPath
Group: [Path](../../functions_group.md#Path)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The BeginPath function opens a path bracket in the specified device context.
***  


## Code examples:
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  

## Declaration:
```foxpro  
BOOL BeginPath(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BeginPath IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.  
***  


## Return value:
If the function succeeds, the return value is nonzero (but it is not a handle to the path). If the function fails, the return value is zero. 
  
***  


## Comments:
After a path bracket is open, an application can begin calling GDI drawing functions to define the points that lie in the path. An application can close an open path bracket by calling the EndPath function.   
  
Several drawing functions can be used on the different Windows operating systems: TextOut, CloseFigure, LineTo, MoveToEx, Polygon, Polyline etc.  
  
***  

