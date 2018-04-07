[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ScreenToClient
Group: [Coordinate Space and Transformation](../../functions_group.md#Coordinate_Space_and_Transformation)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The ScreenToClient function converts the screen coordinates of a specified point on the screen to client-area coordinates.
***  


## Code examples:
[Form Magnifier](../../samples/sample_414.md)  

## Declaration:
```foxpro  
BOOL ScreenToClient(
	HWND hWnd,        // handle to window
	LPPOINT lpPoint   // screen coordinates
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ScreenToClient IN user32;
	INTEGER   hWnd,;
	STRING  @ lpPoint  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose client area will be used for the conversion. 

lpPoint 
[in] Pointer to a POINT structure that specifies the screen coordinates to be converted.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [ClientToScreen](../gdi32/ClientToScreen.md).  
  
***  

