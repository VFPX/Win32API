[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteGraphics
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Deletes the Graphics object created by GdipCreateFromHWND, GdipCreateFromHDC or GdipCreateFromHDC2 function.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteGraphics(
    GpGraphics *graphics
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteGraphics IN gdiplus;
	INTEGER graphics  
```  
***  


## Parameters:
graphics
[in] Handle to the Graphics object.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

