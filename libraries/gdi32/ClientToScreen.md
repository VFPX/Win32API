[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ClientToScreen
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Converts the client-area coordinates of a specified point to screen coordinates.
***  


## Declaration:
```foxpro  
BOOL ClientToScreen(
	HWND hWnd,       // handle to window
	LPPOINT lpPoint  // screen coordinates
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ClientToScreen IN user32;
	INTEGER hWindow,;
	STRING @lpPoint  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose client area is used for the conversion. 

lpPoint 
[in/out] Pointer to a POINT structure that contains the client coordinates to be converted. The new screen coordinates are copied into this structure if the function succeeds.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [ScreenToClient](../user32/ScreenToClient.md).  
  
***  

