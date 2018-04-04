[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MonitorFromWindow
Group: [Multiple Display Monitors](../../functions_group.md#Multiple_Display_Monitors)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a handle to the display monitor that has the largest area of intersection with the bounding rectangle of a specified window.

***  


## Code examples:
[How to change display settings: screen resolution, screen refresh rate](../../samples/sample_374.md)  
[How to detect if additional monitor is connected and active](../../samples/sample_542.md)  
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
HMONITOR MonitorFromWindow(
  HWND hwnd,       // handle to a window
  DWORD dwFlags    // determine return value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MonitorFromWindow IN user32;
	INTEGER hWindow,;
	INTEGER dwFlags
  
```  
***  


## Parameters:
hwnd 
[in] Handle to the window of interest. 

dwFlags 
[in] Determines the function"s return value if the window does not intersect any display monitor.   
***  


## Return value:
If the window intersects one or more display monitor rectangles, the return value is an HMONITOR handle to the display monitor that has the largest area of intersection with the window.  
***  


## Comments:
It might be possible that handles to multiple monitors are not random and start with 0x10001 value.  
  
See also GetMonitorInfo, EnumDisplayDevices functions.  
  
***  

