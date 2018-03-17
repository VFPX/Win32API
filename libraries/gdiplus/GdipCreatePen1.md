<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreatePen1
Group: GDI+ Pen - Library: gdiplus    
***  


#### Creates a Pen object that uses a specified color and width.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreatePen1(
	ARGB color,
	REAL width,
	GpUnit unit,
	GpPen **pen
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreatePen1 IN gdiplus;
	INTEGER   color,;
	SINGLE    penwidth,;
	INTEGER   unit,;
	INTEGER @ gdipen
  
```  
***  


## Parameters:
```txt  
color
[in] ARGB color value.

width
[in] Real number that specifies the width of this pen"s stroke.

unit
[in] Member of the Unit enumeration.

gdipen
[out] Handle to the Pen object.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the Pen handle, call the GdipDeletePen function.   
  
***  

