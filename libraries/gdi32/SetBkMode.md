[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetBkMode
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Sets the background mix mode of the specified device context. The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.
***  


## Code examples:
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using the DrawText function](../../samples/sample_303.md)  
[Using Font and Text functions](../../samples/sample_304.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  

## Declaration:
```foxpro  
int SetBkMode(
  HDC hdc,      // handle to DC
  int iBkMode   // background mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetBkMode IN gdi32;
	INTEGER hdc,;
	INTEGER iBkMode  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

iBkMode 
[in] Specifies the background mode.  
***  


## Return value:
If the function succeeds, the return value specifies the previous background mode. If the function fails, the return value is zero.  
```txt
#DEFINE TRANSPARENT    1  
#DEFINE OPAQUE         2
```
***  

