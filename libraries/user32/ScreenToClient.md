<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ScreenToClient
Group: Coordinate Space and Transformation - Library: user32    
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
```txt  
hWnd
[in] Handle to the window whose client area will be used for the conversion.

lpPoint
[in] Pointer to a POINT structure that specifies the screen coordinates to be converted.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: ClientToScreen   
  
***  

