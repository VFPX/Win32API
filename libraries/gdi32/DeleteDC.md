[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteDC
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Deletes the specified device context (DC).
***  


## Code examples:
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Creating a device context for the specified printer](../../samples/sample_145.md)  
[Retrieving Printer Device Context using PrintDlg function](../../samples/sample_150.md)  
[Retrieving graphic capabilities of default printer](../../samples/sample_155.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: printing image file](../../samples/sample_452.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
BOOL DeleteDC(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
From the GDI Black Book: <Em>remember, use the ReleaseDC function only for a display device context that was retrieved from the GDI device-context cache. After you"re done with the memory device context, you must free it by using the DeleteDC function.</Em>  
  
Finally:  
- use ReleaseDC for forms (the hwnd used as the first parameter)  
- use DeleteDC for memory device contexts (e.g. CreateCompatibleDC)  
  
***  

