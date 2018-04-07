[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetForegroundWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetForegroundWindow function returns a handle to the foreground window (the window with which the user is currently working). The system assigns a slightly higher priority to the thread that creates the foreground window than it does to other threads.
***  


## Declaration:
```foxpro  
HWND GetForegroundWindow(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetForegroundWindow IN user32  
```  
***  


## Return value:
The return value is a handle to the foreground window. The foreground window can be NULL in certain circumstances, such as when a window is losing activation.   
***  


## Comments:
See the SetForegroundWindow function for more details about foreground windows.  
  
Visual FoxPro 9.0 introduces the AppState property, which indicates whether the Visual FoxPro application has focus or not. _SCREEN.AppState returns 0 or 1.   
  
Using the BindEvent() function you can easily detect when your Visual FoxPro application loses or receives focus.  
  
See also: [SetFocus](../user32/SetFocus.md), [GetFocus](../user32/GetFocus.md), [SetForegroundWindow](../user32/SetForegroundWindow.md), [GetActiveWindow](../user32/GetActiveWindow.md).  
  
***  

