<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetPageScale
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Gets the scaling factor currently set for the page transformation of this Graphics handle.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPageScale(
	GpGraphics *graphics,
	REAL *scale
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPageScale IN gdiplus;
	INTEGER graphics,;
	SINGLE @scale  
```  
***  


## Parameters:
```txt  
graphics
[in] Handle to the Graphics object.

scale
[out] Real number that specifies the scaling factor currently set for this Graphics handle.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The page transformation converts page coordinates to device coordinates.  
  
See Also: GdipSetPageScale, GdipGetPageUnit   
  
***  

