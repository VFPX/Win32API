<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ClientToScreen
Group: Coordinate Space and Transformation - Library: gdi32    
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
```txt  
hWnd
[in] Handle to the window whose client area is used for the conversion.

lpPoint
[in/out] Pointer to a POINT structure that contains the client coordinates to be converted. The new screen coordinates are copied into this structure if the function succeeds.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: ScreenToClient   
  
***  

