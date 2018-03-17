<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateSolidFill
Group: GDI+ Brush - Library: gdiplus    
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
```txt  
color
[in] ARGB Color value that specifies the initial color of this solid brush.

brush
[out] Handle of the brush object.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the handle, call the GdipDeleteBrush function.   
  
***  

