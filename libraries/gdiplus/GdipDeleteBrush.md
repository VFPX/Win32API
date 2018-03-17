<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteBrush
Group: GDI+ Brush - Library: gdiplus    
***  


#### Deletes the specified Brush object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteBrush(
	GpBrush *brush
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteBrush IN gdiplus;
	INTEGER brush  
```  
***  


## Parameters:
```txt  
brush
[in] Handle to the Brush object created with GdipCreateSolidFill, GdipCreateHatchBrush, GdipCloneBrush or similar function.  
```  
***  


## Return value:
Returns 0 on success.  
***  

