<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetPageScale
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Sets the scaling factor for the page transformation of this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPageScale(
	GpGraphics *graphics,
	REAL scale
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPageScale IN gdiplus;
	INTEGER graphics,;
	SINGLE scale  
```  
***  


## Parameters:
```txt  
graphics
[in] Handle to the Graphics object.

scale
[in] Real number that specifies the scaling factor.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
See Also: GdipGetPageScale, GdipSetPageUnit   
  
***  

