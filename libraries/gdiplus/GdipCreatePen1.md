[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreatePen1
Group: [GDI+ Pen](../../functions_group.md#GDIplus_Pen)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
color
[in] ARGB color value. 

width
[in] Real number that specifies the width of this pen"s stroke.

unit
[in] Member of the Unit enumeration.

gdipen
[out] Handle to the Pen object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the Pen handle, call the GdipDeletePen function.   
  
***  

