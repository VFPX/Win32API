[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : TextOut
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Writes a character string at the specified location, using the currently selected font, background color, and text color.

***  


## Code examples:
[Printing text on the client area of the main VFP window](../../samples/sample_034.md)  
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using Font and Text functions](../../samples/sample_304.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Vertical Label control](../../samples/sample_398.md)  

## Declaration:
```foxpro  
BOOL TextOut(
  HDC hdc,           // handle to DC
  int nXStart,       // x-coordinate of starting position
  int nYStart,       // y-coordinate of starting position
  LPCTSTR lpString,  // character string
  int cbString       // number of characters
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER TextOut IN gdi32;
    INTEGER hdc,;
    INTEGER x,;
    INTEGER y,;
    STRING  lpString,;
    INTEGER nCount  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

nXStart 
[in] Specifies the logical x-coordinate of the reference point that the system uses to align the string. 

nYStart 
[in] Specifies the logical y-coordinate of the reference point that the system uses to align the string. 

lpString 
[in] Pointer to the string to be drawn  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
See also: [DrawText](../user32/DrawText.md), [CreateFont](../gdi32/CreateFont.md).  
  
***  

