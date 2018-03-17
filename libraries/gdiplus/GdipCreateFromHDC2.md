<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateFromHDC2
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Returns handle to the Graphics object that is associated with a specified device context and a specified device.


***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateFromHDC2(
    HDC hdc,
    HANDLE hDevice,
    GpGraphics **graphics
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateFromHDC2 IN gdiplus;
	INTEGER   hdc,;
	INTEGER   hDevice,;
	INTEGER @ graphics  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to a device context that will be associated with the new Graphics object.

hdevice
[in] Handle to a device that will be associated with the new Graphics object.

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
  
See also: GdipCreateFromHWND, GdipCreateFromHDC functions.  
  
***  

