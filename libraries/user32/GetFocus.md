[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFocus
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the handle to the window that has the keyboard focus, if the window is attached to the calling thread"s message queue.
***  


## Code examples:
[Retrieving window and menu help context identifiers](../../samples/sample_025.md)  
[GetFocus returns a HWND value](../../samples/sample_090.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Drawing standard Windows icons](../../samples/sample_112.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Setting the Window Region for a form](../../samples/sample_120.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[How to drag a Form not using its Titlebar or Caption](../../samples/sample_195.md)  
[How to start the screen saver and how to find whether the screen saver is active](../../samples/sample_196.md)  
[Using IsChild() for testing ThisForm.ShowWindow property](../../samples/sample_207.md)  
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Retrieving top-child window for the VFP form](../../samples/sample_209.md)  
[Drawing a window caption using the DrawCaption routine](../../samples/sample_238.md)  
[Running a regular FoxPro form while main VFP window is minimized](../../samples/sample_246.md)  
[Animating a transition of the VFP form (a wire-frame rectangle)](../../samples/sample_255.md)  
[Disabling drawing in the VFP form](../../samples/sample_257.md)  
[The window and its ancestors](../../samples/sample_266.md)  
[Placing a button on the VFP form as a new child window](../../samples/sample_274.md)  
[Tracking mouse movement to detect when to start dragging](../../samples/sample_281.md)  
[Setting the mouse capture to the specified window](../../samples/sample_282.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[How to intercept window messages sent to VFP form](../../samples/sample_307.md)  
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[Form Magnifier](../../samples/sample_414.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[How to block the ALT+TAB shortcut (WinXP)](../../samples/sample_432.md)  
[GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF)](../../samples/sample_454.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[How to block the PrintScreen key](../../samples/sample_489.md)  

## Declaration:
```foxpro  
HWND GetFocus(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFocus IN user32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is the handle to the window with the keyboard focus. If the calling thread"s message queue does not have an associated window with the keyboard focus, the return value is NULL.  
***  


## Comments:
This function returns a window handle to an active form, or for the main VFP window if it has the keyboard focus. In this case its result is equivalent to the one of GetActiveWindow.  
  
See also: [SetFocus](../user32/SetFocus.md), [SetForegroundWindow](../user32/SetForegroundWindow.md), [GetForegroundWindow](../user32/GetForegroundWindow.md), [GetActiveWindow](../user32/GetActiveWindow.md).  
  
***  

