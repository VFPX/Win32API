[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReleaseDC
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The ReleaseDC function releases a device context (DC), freeing it for use by other applications. For memory device contexts use the DeleteDC function.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[Printing text on the client area of the main VFP window](../../samples/sample_034.md)  
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Using GetNearestColor](../../samples/sample_044.md)  
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Drawing standard Windows icons](../../samples/sample_112.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Converting twips to pixels and vice versa](../../samples/sample_161.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Retrieving graphic capabilities of your display](../../samples/sample_188.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  
[Drawing cursors for the classes defined by the system (preregistered): BUTTON, EDIT, LISTBOX etc.](../../samples/sample_203.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Obtaining the bounding rectangle for the specified device context](../../samples/sample_237.md)  
[Drawing a window caption using the DrawCaption routine](../../samples/sample_238.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Drawing Windows frame controls using the DrawFrameControl function](../../samples/sample_254.md)  
[Drawing a rectangle using Windows regular edges and borders](../../samples/sample_256.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Using the DrawText function](../../samples/sample_303.md)  
[Using Font and Text functions](../../samples/sample_304.md)  
[Reading metrics for the currently selected font](../../samples/sample_339.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[Using the GradientFill function](../../samples/sample_353.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[Form Magnifier](../../samples/sample_414.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF)](../../samples/sample_454.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[GDI+: how to make VFP controls visually shake and shudder](../../samples/sample_526.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[GDI+: Scrolling through large image using the mouse](../../samples/sample_546.md)  
[GDI+: Creating thumbnails to preview images in a directory](../../samples/sample_547.md)  
[GDI+ fun: roach-infested desktop](../../samples/sample_548.md)  
[GDI+: Color Transparency](../../samples/sample_549.md)  
[How to find which fonts Windows uses for drawing captions, menus and message boxes](../../samples/sample_556.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  
[GDI+: custom control, base class](../../samples/sample_599.md)  

## Declaration:
```foxpro  
int ReleaseDC(
    HWND  hwnd,	// handle of window
    HDC  hdc 	// handle of device context
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReleaseDC IN user32;
	INTEGER hwnd,;
	INTEGER hdc
  
```  
***  


## Parameters:
hwnd
Identifies the window whose device context is to be released

hdc
Identifies the device context to be released  
***  


## Return value:
The return value specifies whether the device context is released. If the device context is released, the return value is 1  
***  


## Comments:
Once you obtain a device context (retrieved by GetDC, or GetWindowDC functions), you may write to the window. At the end of this process the device context must be released using ReleaseDC. Otherwise you will have a memory leak.  
  
GDI Black Book: <Em>remember, use the ReleaseDC function only for a display device context that was retrieved from the GDI device-context cache. After you"re done with the memory device context, you must free it by using the DeleteDC function.</Em>  
  
Finally:  
- use ReleaseDC for forms (the hwnd used as the first parameter)  
- use DeleteDC for memory device contexts (e.g. CreateCompatibleDC function)  
  
***  

