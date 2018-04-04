[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteBrush
Group: [GDI+ Brush](../../functions_group.md#GDIplus_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
brush
[in] Handle to the Brush object created with GdipCreateSolidFill, GdipCreateHatchBrush, GdipCloneBrush or similar function.  
***  


## Return value:
Returns 0 on success.  
***  

