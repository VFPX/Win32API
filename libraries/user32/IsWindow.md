[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The IsWindow function determines whether the specified window handle identifies an existing window
***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[Custom GDI+ class](../../samples/sample_450.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
BOOL IsWindow(
    HWND  hWnd 	// handle of window
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsWindow IN user32 INTEGER hwnd  
```  
***  


## Parameters:
hWnd
Specifies the window handle  
***  


## Return value:
If the window handle identifies an existing window, the return value is TRUE; otherwise, it is FALSE  
***  

