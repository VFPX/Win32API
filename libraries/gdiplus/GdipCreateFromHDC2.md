[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateFromHDC2
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
hdc
[in] Handle to a device context that will be associated with the new Graphics object.

hdevice
[in] Handle to a device that will be associated with the new Graphics object. 

graphics
[out] Handle to the Graphics object.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The Graphics class provides methods for drawing lines, curves, figures, images, and text. A Graphics object stores attributes of the display device and attributes of the items to be drawn.  
  
When no longer needed the Graphics object must be deleted with the GdipDeleteGraphics function.  
  
See also: [GdipCreateFromHWND](GdipCreateFromHWND.md), [GdipCreateFromHDC](GdipCreateFromHDC.md) functions.  
  
***  

