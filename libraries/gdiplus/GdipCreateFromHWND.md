<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateFromHWND
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Returns handle to the Graphics object associated with the windows handle.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateFromHWND(
    HWND hwnd,
    GpGraphics **graphics
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateFromHWND IN gdiplus;
	INTEGER   hWindow,;
	INTEGER @ graphics  
```  
***  


## Parameters:
```txt  
hwnd
[in] Identifies the window or control.

graphics
[out] Handle to the Graphics object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The Graphics class provides methods for drawing lines, curves, figures, images, and text. A Graphics object stores attributes of the display device and attributes of the items to be drawn.  
  
When no longer needed the Graphics object must be deleted with the GdipDeleteGraphics function.  
  
See also: GdipCreateFromHDC, GdipCreateFromHDC2 functions.  
  
***  

