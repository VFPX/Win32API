[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathToRegion
Group: [Path](../../functions_group.md#Path)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a region from the path that is selected into the specified device context. The resulting region uses device coordinates.
***  


## Code examples:
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  

## Declaration:
```foxpro  
HRGN PathToRegion(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathToRegion IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to a device context that contains a closed path.  
***  


## Return value:
If the function succeeds, the return value identifies a valid region. If the function fails, the return value is zero. 
  
***  

