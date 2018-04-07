[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetForegroundWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetForegroundWindow function puts the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user
***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  
[Testing Transparent Menu Class with top-level form (requires VFP9)](../../samples/sample_497.md)  
[How to hot-track menu item selection in top-level form (requires VFP9)](../../samples/sample_521.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
BOOL SetForegroundWindow(
    HWND  hwnd 	// handle of window to bring to foreground
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetForegroundWindow IN user32 INTEGER hwnd  
```  
***  


## Parameters:
hwnd
Identifies the window that should be activated and brought to the foreground  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
MSDN: Starting with Windows 98, your application can no longer simply rely on calling SetForegroundWindow to get the foreground window. The system restricts which processes can set the foreground window.  
  
See also the GetForegroundWindow function.  
  
Visual FoxPro 9.0 introduces the AppState property, which indicates whether the Visual FoxPro application has focus or not. _SCREEN.AppState returns 0 or 1.   
  
Using the BindEvent() function you can easily detect when your Visual FoxPro application loses or receives focus.  
  
See also: [SetFocus](../user32/SetFocus.md), [GetFocus](../user32/GetFocus.md), [GetForegroundWindow](../user32/GetForegroundWindow.md), [GetActiveWindow](../user32/GetActiveWindow.md).  
  
***  

