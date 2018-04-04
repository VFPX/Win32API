[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDrawLineI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Uses a pen to draw a line.
***  


## Code examples:
[GDI+ fun: roach-infested desktop](../../samples/sample_548.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDrawLineI(
	GpGraphics *graphics,
	GpPen *pen,
	INT x1, INT y1,
	INT x2, INT y2)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDrawLineI IN gdiplus;
	INTEGER graphics,;
	INTEGER gdipen,;
	INTEGER x1,;
	INTEGER y1,;
	INTEGER x2,;
	INTEGER y2  
```  
***  


## Parameters:
graphics
[in] Pointer to a Graphics object.

pen
[in] Pointer to a Pen that is used to draw the line. 

x1
[in] Integer that specifies the x-coordinate of the starting point of the line. 

y1
[in] Integer that specifies the y-coordinate of the starting point of the line. 

x2
[in] Integer that specifies the x-coordinate of the ending point of the line.

y2
[in] Integer that specifies the y-coordinate of the ending point of the line  
***  


## Return value:
If the method succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
Create Pen object with GdipCreatePen1, GdipCreatePen2 or GdipClonePen function.  
  
***  

