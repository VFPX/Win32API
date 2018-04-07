[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMapMode
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Retrieves the current mapping mode.
***  


## Declaration:
```foxpro  
int GetMapMode(
	HDC hdc   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMapMode IN gdi32;
	INTEGER hDC
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.   
***  


## Return value:
If the function succeeds, the return value specifies the mapping mode.  
***  


## Comments:
See also: [SetMapMode](../gdi32/SetMapMode.md).  
  
***  

