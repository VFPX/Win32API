[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetCapture
Group: [Mouse Input](../../functions_group.md#Mouse_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetCapture function sets the mouse capture to the specified window belonging to the current thread.
***  


## Code examples:
[Setting the mouse capture to the specified window](../../samples/sample_282.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
HWND SetCapture(
  HWND hWnd   // handle to window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetCapture IN user32;
	INTEGER hWnd  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window in the current thread that is to capture the mouse.   
***  


## Return value:
The return value is a handle to the window that had previously captured the mouse. If there is no such window, the return value is NULL.   
***  

