[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetWindow function retrieves the handle of a window that has the specified relationship to the specified window.
***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Retrieving top-child window for the VFP form](../../samples/sample_209.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[Customizing the frame of top-level form: removing the standard frame (VFP9, Vista)](../../samples/sample_574.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  
[GDI+: custom control, base class](../../samples/sample_599.md)  

## Declaration:
```foxpro  
HWND GetWindow(
    HWND  hWnd,	// handle of original window
    UINT  uCmd 	// relationship flag
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindow IN user32;
	INTEGER hwnd,;
	INTEGER wFlag  
```  
***  


## Parameters:
hWnd
Identifies a window

uCmd
Specifies the relationship between the specified window and the window whose handle is to be retrieved  
***  


## Return value:
If the function succeeds, the return value is a window handle  
***  

