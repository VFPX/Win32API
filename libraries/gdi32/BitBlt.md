[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : BitBlt
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The BitBlt function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.
***  


## Code examples:
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF)](../../samples/sample_454.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[GDI+: how to make VFP controls visually shake and shudder](../../samples/sample_526.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
BOOL BitBlt(
  HDC hdcDest, // handle to destination DC
  int nXDest,  // x-coord of destination upper-left corner
  int nYDest,  // y-coord of destination upper-left corner
  int nWidth,  // width of destination rectangle
  int nHeight, // height of destination rectangle
  HDC hdcSrc,  // handle to source DC
  int nXSrc,   // x-coordinate of source upper-left corner
  int nYSrc,   // y-coordinate of source upper-left corner
  DWORD dwRop  // raster operation code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BitBlt IN gdi32;
	INTEGER hDestDC,;
	INTEGER x,;
	INTEGER y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER hSrcDC,;
	INTEGER xSrc,;
	INTEGER ySrc,;
	INTEGER dwRop  
```  
***  


## Parameters:
hdcDest 
[in] Handle to the destination device context. 

nXDest 
[in] Specifies the logical x-coordinate of the upper-left corner of the destination rectangle. 

nYDest 
[in] Specifies the logical y-coordinate of the upper-left corner of the destination rectangle. 

nWidth 
[in] Specifies the logical width of the source and destination rectangles. 

nHeight 
[in] Specifies the logical height of the source and the destination rectangles. 

hdcSrc 
[in] Handle to the source device context. 

nXSrc 
[in] Specifies the logical x-coordinate of the upper-left corner of the source rectangle. 

nYSrc 
[in] Specifies the logical y-coordinate of the upper-left corner of the source rectangle. 

dwRop 
[in] Specifies a raster-operation code.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Not all devices support the BitBlt function. For more information, see the RC_BITBLT raster capability entry in the GetDeviceCaps function as well as the following functions: MaskBlt, PlgBlt, and StretchBlt.   
  
BitBlt returns an error if the source and destination device contexts represent different devices.  
  
***  

