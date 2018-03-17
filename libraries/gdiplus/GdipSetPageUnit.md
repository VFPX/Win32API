<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetPageUnit
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Sets the unit of measure for this Graphics handle. 
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPageUnit(
	GpGraphics *graphics,
	GpUnit unit
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPageUnit IN gdiplus;
	INTEGER graphics,;
	INTEGER unit  
```  
***  


## Parameters:
```txt  
graphics
[in] Handle to the Graphics object.

unit
[in] Element of the Unit enumeration that specifies the unit of measure for this Graphics handle.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The page unit belongs to the page transformation, which converts page coordinates to device coordinates.  
  
See Also: GdipGetPageUnit   
  
***  

