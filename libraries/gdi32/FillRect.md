[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FillRect
Group: [Filled Shape](../../functions_group.md#Filled_Shape)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The FillRect function fills a rectangle by using the specified brush. This function includes the left and top borders, but excludes the right and bottom borders of the rectangle. 
***  


## Code examples:
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
int FillRect(
  HDC hDC,           // handle to DC
  CONST RECT *lprc,  // rectangle
  HBRUSH hbr         // handle to brush
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FillRect IN user32;
	INTEGER   hDC,;
	STRING  @ rect,;
	INTEGER   hBrush
  
```  
***  


## Parameters:
hDC 
[in] Handle to the device context. 

lprc 
[in] Pointer to a RECT structure that contains the logical coordinates of the rectangle to be filled. 

hbr 
[in] Handle to the brush used to fill the rectangle.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
For a list of all the standard system colors, see GetSysColor.  
  
When filling the specified rectangle, FillRect does not include the rectangle"s right and bottom sides. GDI fills a rectangle up to, but not including, the right column and bottom row, regardless of the current mapping mode.   
  
***  

