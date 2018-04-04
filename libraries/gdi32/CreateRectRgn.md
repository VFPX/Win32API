[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateRectRgn
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a rectangular region.
***  


## Code examples:
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Setting the Window Region for a form](../../samples/sample_120.md)  
[Finding parameters for the region specified](../../samples/sample_124.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
HRGN CreateRectRgn(
  int nLeftRect,   // x-coordinate of upper-left corner
  int nTopRect,    // y-coordinate of upper-left corner
  int nRightRect,  // x-coordinate of lower-right corner
  int nBottomRect  // y-coordinate of lower-right corner
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateRectRgn IN gdi32;
	INTEGER nLeftRect,;
	INTEGER nTopRect,;
	INTEGER nRightRect,;
	INTEGER nBottomRect  
```  
***  


## Parameters:
nLeftRect 
[in] Specifies the x-coordinate of the upper-left corner of the region in logical units. 

nTopRect 
[in] Specifies the y-coordinate of the upper-left corner of the region in logical units. 

nRightRect 
[in] Specifies the x-coordinate of the lower-right corner of the region in logical units. 

nBottomRect 
[in] Specifies the y-coordinate of the lower-right corner of the region in logical units.  
***  


## Return value:
If the function succeeds, the return value is the handle to the region. If the function fails, the return value is NULL. 
  
***  

