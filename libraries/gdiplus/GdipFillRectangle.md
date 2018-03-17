<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipFillRectangle
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Uses a brush to fill the interior of a rectangle.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipFillRectangle(
	GpGraphics *graphics,
	GpBrush *brush,
	REAL x,
	REAL y,
	REAL width,
	REAL height
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipFillRectangle IN gdiplus;
	INTEGER graphics,;
	INTEGER brush,;
	SINGLE  x,;
	SINGLE  y,;
	SINGLE  width,;
	SINGLE  height  
```  
***  


## Parameters:
```txt  
graphics
[in] Pointer to a Graphics object.

brush
[in] Pointer to a Brush that is used to paint the interior of the rectangle.

x
[in] Real number that specifies the x-coordinate of the upper-left corner of the rectangle to be filled.

y
[in] Real number that specifies the y-coordinate of the upper-left corner of the rectangle to be filled.

width
[in] Real number that specifies the width of the rectangle to be filled.

height
[in] Real number that specifies the height of the rectangle to be filled.  
```  
***  


## Return value:
If the method succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
Create Brush object using functions GdipCreateSolidFill, GdipCreateHatchBrush, GdipCreateTexture etc.  
  
***  

