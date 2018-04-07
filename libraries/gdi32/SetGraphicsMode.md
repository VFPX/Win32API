[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetGraphicsMode
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Sets the graphics mode for the specified device context.
***  


## Declaration:
```foxpro  
int SetGraphicsMode(
	HDC hdc,    // handle to device context
	int iMode   // graphics mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetGraphicsMode IN gdi32;
	INTEGER hdc, INTEGER iMode
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

iMode 
[in] Specifies the graphics mode.  
***  


## Return value:
If the function succeeds, the return value is the old graphics mode.  
***  


## Comments:
See also: [GetGraphicsMode](../gdi32/GetGraphicsMode.md).  
  
***  

