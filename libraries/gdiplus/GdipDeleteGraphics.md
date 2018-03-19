
## Function name : GdipDeleteGraphics
Group: GDI+ Graphics - Library: gdiplus    
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

