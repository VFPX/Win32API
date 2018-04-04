[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SelectObject
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Selects an object into the specified device context (DC). The new object replaces the previous object of the same type.

***  


## Code examples:
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
HGDIOBJ SelectObject(
  HDC hdc,          // handle to DC
  HGDIOBJ hgdiobj   // handle to object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SelectObject IN gdi32;
	INTEGER hdc,;
	INTEGER hObject  
```  
***  


## Parameters:
hdc 
[in] Handle to the DC. 

hgdiobj 
[in] Handle to the object to be selected: bitmap, brush, font, pen, region  
***  


## Return value:
If the selected object is not a region and the function succeeds, the return value is a handle to the object being replaced.  
***  

