[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DragDetect
Group: [Mouse Input](../../functions_group.md#Mouse_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DragDetect function captures the mouse and tracks its movement until the user releases the left button, presses the ESC key, or moves the mouse outside the drag rectangle around the specified point.
***  


## Code examples:
[Tracking mouse movement to detect when to start dragging](../../samples/sample_281.md)  

## Declaration:
```foxpro  
BOOL DragDetect(
  HWND hwnd,   // handle to window
  POINT pt     // initial position
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DragDetect IN user32;
	INTEGER   hwnd,;
	STRING  @ pt  
```  
***  


## Parameters:
hwnd 
[in] Handle to the window receiving mouse input. 

pt 
[in] Initial position of the mouse, in screen coordinates. The function determines the coordinates of the drag rectangle by using this point.   
***  


## Return value:
If the user moved the mouse outside of the drag rectangle while holding down the left button , the return value is nonzero.  
***  


## Comments:
The width and height of the drag rectangle are specified by the SM_CXDRAG and SM_CYDRAG values returned by the GetSystemMetrics function.  
  
The system metrics for the drag rectangle are configurable (through the Windows Registry), allowing for larger or smaller drag rectangles.   
  
***  

