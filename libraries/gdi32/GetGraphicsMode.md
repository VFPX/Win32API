[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetGraphicsMode
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Retrieves the current graphics mode for the specified device context.
***  


## Declaration:
```foxpro  
int GetGraphicsMode(
	HDC hdc   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetGraphicsMode IN gdi32;
	INTEGER hDC
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.   
***  


## Return value:
If the function succeeds, the return value is the current graphics mode.  
***  


## Comments:
An application can set the graphics mode for a device context by calling the SetGraphicsMode function.  
  
***  

