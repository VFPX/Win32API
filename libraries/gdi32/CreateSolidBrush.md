<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateSolidBrush
Group: Brush - Library: gdi32    
***  


#### The CreateSolidBrush function creates a logical brush that has the specified solid color. 
***  


## Code examples:
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
HBRUSH CreateSolidBrush(
  COLORREF crColor   // brush color value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateSolidBrush IN gdi32;
	LONG crColor  
```  
***  


## Parameters:
```txt  
crColor
[in] Specifies the color of the brush. To create a COLORREF color value, use the RGB macro.  
```  
***  


## Return value:
If the function succeeds, the return value identifies a logical brush.  
***  


## Comments:
A solid brush is a bitmap that the system uses to paint the interiors of filled shapes.   
  
After an application creates a brush by calling CreateSolidBrush, it can select that brush into any device context by calling the SelectObject function.  
  
***  

