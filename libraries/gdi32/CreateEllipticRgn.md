[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateEllipticRgn
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The CreateEllipticRgn function creates an elliptical region.
***  


## Code examples:
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  

## Declaration:
```foxpro  
HRGN CreateEllipticRgn(
  int nLeftRect,   // x-coord of upper-left corner of rectangle
  int nTopRect,    // y-coord of upper-left corner of rectangle
  int nRightRect,  // x-coord of lower-right corner of rectangle
  int nBottomRect  // y-coord of lower-right corner of rectangle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateEllipticRgn IN gdi32;
	INTEGER nLeftRect,;
	INTEGER nTopRect,;
	INTEGER nRightRect,;
	INTEGER nBottomRect  
```  
***  


## Parameters:
nLeftRect 
[in] Specifies the x-coordinate in logical units, of the upper-left corner of the bounding rectangle of the ellipse. 

nTopRect 
[in] Specifies the y-coordinate in logical units, of the upper-left corner of the bounding rectangle of the ellipse. 

nRightRect 
[in] Specifies the x-coordinate in logical units, of the lower-right corner of the bounding rectangle of the ellipse. 

nBottomRect 
[in] Specifies the y-coordinate in logical units, of the lower-right corner of the bounding rectangle of the ellipse.  
***  


## Return value:
If the function succeeds, the return value is the handle to the region. If the function fails, the return value is NULL. 
  
***  

