[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteObject
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Deletes a logical pen, brush, font, bitmap, region, or palette, freeing all system resources associated with the object. After the object is deleted, the specified handle is no longer valid.
***  


## Code examples:
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[Custom GDI+ class](../../samples/sample_450.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL DeleteObject(
  HGDIOBJ hObject   // handle to graphic object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteObject IN gdi32;
	INTEGER hObject  
```  
***  


## Parameters:
hObject 
[in] Handle to a logical pen, brush, font, bitmap, region, or palette.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

