<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetSmoothingMode
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Determines whether smoothing (antialiasing) is applied to the Graphics object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetSmoothingMode(
	GpGraphics *graphics,
	SmoothingMode *smoothingMode)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetSmoothingMode IN gdiplus;
	INTEGER graphics,;
	INTEGER @smoothingMode  
```  
***  


## Parameters:
```txt  
graphics
[in] Handle of a Graphics object.

smoothingMode
[out] Element of the SmoothingMode enumeration.  
```  
***  


## Return value:
Returns Ok (0) if succeeded.  
***  


## Comments:
See also: GdipSetSmoothingMode   
  
<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/ms534173(v=vs.85).aspx">SmoothingMode</a> enumeration.  
  
***  

