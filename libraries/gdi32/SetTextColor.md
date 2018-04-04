[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetTextColor
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Sets the text color for the specified device context to the specified color.
***  


## Code examples:
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using the DrawText function](../../samples/sample_303.md)  
[Using Font and Text functions](../../samples/sample_304.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  

## Declaration:
```foxpro  
COLORREF SetTextColor(
  HDC hdc,           // handle to DC
  COLORREF crColor   // text color
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetTextColor IN gdi32;
	INTEGER hdc, INTEGER crColor  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

crColor 
[in] Specifies the color of the text.  
***  


## Return value:
If the function succeeds, the return value is a color reference for the previous text color as a COLORREF value. If the function fails, the return value is CLR_INVALID (0xFFFFFFFF). 
  
***  

