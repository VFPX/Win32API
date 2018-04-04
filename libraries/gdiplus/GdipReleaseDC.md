[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipReleaseDC
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Releases a device context handle obtained by a previous call to the GdipGetHDC with this Graphics handle.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipReleaseDC(
	GpGraphics* graphics,
	HDC hdc
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipReleaseDC IN gdiplus;
	INTEGER graphics,;
	INTEGER hdc
  
```  
***  


## Parameters:
graphics
[in] Handle to a Graphics object obtained from GdipCreateFromHDC, GdipCreateFromHDC2, GdipCreateFromHWND or GdipGetImageGraphicsContext functions.

hdc
[in] Handle to a device context obtained by a previous call to the GdipGetHDC method with this Graphics handle.   
***  


## Return value:
This call does not return a value.  
***  

