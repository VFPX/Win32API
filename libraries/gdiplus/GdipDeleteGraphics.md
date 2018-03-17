<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteGraphics
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
```txt  
graphics
[in] Handle to the Graphics object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

