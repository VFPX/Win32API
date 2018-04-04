[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateCompatibleBitmap
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a bitmap compatible with the device that is associated with the specified device context.
***  


## Code examples:
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
HBITMAP CreateCompatibleBitmap(
  HDC hdc,        // handle to DC
  int nWidth,     // width of bitmap, in pixels
  int nHeight     // height of bitmap, in pixels
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateCompatibleBitmap IN gdi32;
	INTEGER hdc,;
	INTEGER nWidth,;
	INTEGER nHeight  
```  
***  


## Parameters:
hdc 
[in] Handle to a device context. 

nWidth 
[in] Specifies the bitmap width, in pixels. 

nHeight 
[in] Specifies the bitmap height, in pixels.  
***  


## Return value:
If the function succeeds, the return value is a handle to the bitmap.  
***  


## Comments:
When created the bitmap can be placed on a device context using SelectObject function. When you no longer need the bitmap, call the DeleteObject function to delete it.  
  
***  

