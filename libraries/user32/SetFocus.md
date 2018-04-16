[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetFocus
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sets the keyboard focus to the specified window. The window must be attached to the calling thread"s message queue
***  


## Declaration:
```foxpro  
HWND SetFocus(
	HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetFocus IN user32;
AS SetFocusAPI INTEGER hWindow
  
```  
***  


## Parameters:
hWnd
[in] Handle to the window that will receive the keyboard input. If this parameter is NULL, keystrokes are ignored.  
***  


## Return value:
If the function succeeds, the return value is the handle to the window that previously had the keyboard focus.   
***  


## Comments:
```foxpro
DECLARE INTEGER SetFocus IN user32;  
	AS SetFocusAPI INTEGER hWindow  
? SetFocusAPI(_screen.HWnd)
```
See also: [GetFocus](../user32/GetFocus.md), [SetForegroundWindow](../user32/SetForegroundWindow.md), [GetForegroundWindow](../user32/GetForegroundWindow.md), [GetActiveWindow](../user32/GetActiveWindow.md).  
  
***  

