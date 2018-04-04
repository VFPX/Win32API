[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDesktopWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetDesktopWindow function returns the handle of the Windows desktop window. The desktop window covers the entire screen. The desktop window is the area on top of which all icons and other windows are painted
***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Scanning a hierarchy of child windows down from the Windows Desktop](../../samples/sample_045.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Retrieving geometrical parameters of the system desktop window](../../samples/sample_092.md)  
[Confining Windows calculator inside the VFP main window](../../samples/sample_245.md)  
[Running a regular FoxPro form while main VFP window is minimized](../../samples/sample_246.md)  
[Obtaining some properties for the Windows desktop using the GetWindowPlacement function](../../samples/sample_263.md)  
[The window and its ancestors](../../samples/sample_266.md)  
[Using the IsWindowEnabled function](../../samples/sample_306.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[How to change display settings: screen resolution, screen refresh rate](../../samples/sample_374.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Custom GDI+ class](../../samples/sample_450.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
HWND GetDesktopWindow(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDesktopWindow IN user32  
```  
***  


## Parameters:
This function has no parameters  
***  


## Return value:
The return value is the handle of the desktop window  
***  

