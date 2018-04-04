[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FrameRgn
Group: [Region](../../functions_group.md#Region)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The FrameRgn function draws a border around the specified region by using the specified brush.
***  


## Code examples:
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  

## Declaration:
```foxpro  
BOOL FrameRgn(
  HDC hdc,     // handle to device context
  HRGN hrgn,   // handle to region to be framed
  HBRUSH hbr,  // handle to brush used to draw border
  int nWidth,  // width of region frame
  int nHeight  // height of region frame
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT FrameRgn IN gdi32;
	INTEGER hdc,;
	INTEGER hrgn,;
	INTEGER hbr,;
	INTEGER nWidth,;
	INTEGER nHeight  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

hrgn 
[in] Handle to the region to be enclosed in a border. The region"s coordinates are presumed to be in logical units. 

hbr 
[in] Handle to the brush to be used to draw the border. 

nWidth 
[in] Specifies the width, in logical units, of vertical brush strokes. 

nHeight 
[in] Specifies the height, in logical units, of horizontal brush strokes.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  

