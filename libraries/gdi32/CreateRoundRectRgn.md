[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateRoundRectRgn
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a rectangular region with rounded corners.
***  


## Code examples:
[Setting the Window Region for a form](../../samples/sample_120.md)  

## Declaration:
```foxpro  
HRGN CreateRoundRectRgn(
  int nLeftRect,      // x-coordinate of upper-left corner
  int nTopRect,       // y-coordinate of upper-left corner
  int nRightRect,     // x-coordinate of lower-right corner
  int nBottomRect,    // y-coordinate of lower-right corner
  int nWidthEllipse,  // height of ellipse
  int nHeightEllipse  // width of ellipse
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateRoundRectRgn IN gdi32;
	INTEGER nLeftRect,;
	INTEGER nTopRect,;
	INTEGER nRightRect,;
	INTEGER nBottomRect,;
	INTEGER nWidthEllipse,;
	INTEGER nHeightEllipse  
```  
***  


## Parameters:
nLeftRect 
[in] Specifies the x-coordinate of the upper-left corner of the region in device units. 

nTopRect 
[in] Specifies the y-coordinate of the upper-left corner of the region in device units. 

nRightRect 
[in] Specifies the x-coordinate of the lower-right corner of the region in device units. 

nBottomRect 
[in] Specifies the y-coordinate of the lower-right corner of the region in device units. 

nWidthEllipse 
[in] Specifies the width of the ellipse used to create the rounded corners in device units. 

nHeightEllipse 
[in] Specifies the height of the ellipse used to create the rounded corners in device units.  
***  


## Return value:
If the function succeeds, the return value is the handle to the region.  
***  

