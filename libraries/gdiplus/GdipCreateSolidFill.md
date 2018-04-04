[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateSolidFill
Group: [GDI+ Brush](../../functions_group.md#GDIplus_Brush)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a SolidBrush object based on a color.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateSolidFill(
	ARGB color,
	GpSolidFill **brush
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateSolidFill IN gdiplus;
	INTEGER   clr,;
	INTEGER @ brush  
```  
***  


## Parameters:
color
[in] ARGB Color value that specifies the initial color of this solid brush. 

brush
[out] Handle of the brush object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the handle, call the GdipDeleteBrush function.   
  
***  

