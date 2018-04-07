[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipFillPieI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Uses a brush to fill the interior of a pie.
***  


## Code examples:
[GDI+: Drawing a Pie Chart](../../samples/sample_514.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipFillPieI(
	GpGraphics *graphics,
	GpBrush *brush,
	INT x,
	INT y,
	INT width,
	INT height,
	REAL startAngle,
	REAL sweepAngle
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipFillPieI IN gdiplus;
	INTEGER graphics,;
	INTEGER brush,;
	INTEGER x,;
	INTEGER y,;
	INTEGER width,;
	INTEGER height,;
	SINGLE startAngle,;
	SINGLE sweepAngle  
```  
***  


## Parameters:
graphics
[in] Handle of a Graphics object.

brush
[in] Handle of a Brush that is used to paint the interior of the pie.

x
[in] Integer that specifies the x-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie. 

y
[in] Integer that specifies the y-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie. 

width
[in] Integer that specifies the width of the rectangle that bounds the ellipse in which to draw the pie. 

height
[in] Integer that specifies the height of the rectangle that bounds the ellipse in which to draw the pie. 

startAngle
[in] Real number that specifies the angle, in degrees, between the x-axis and the starting point of the arc that defines the pie. A positive value specifies clockwise rotation. 

sweepAngle
[in] Real number that specifies the angle, in degrees, between the starting and ending points of the arc that defines the pie. A positive value specifies clockwise rotation.  
***  


## Return value:
If the function succeeds, it returns Ok (0).  
***  


## Comments:
See also: [GdipDrawPieI](../gdiplus/GdipDrawPieI.md).  
  
***  

