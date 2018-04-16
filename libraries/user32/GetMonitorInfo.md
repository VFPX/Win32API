[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMonitorInfo
Group: [Multiple Display Monitors](../../functions_group.md#Multiple_Display_Monitors)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMonitorInfo function retrieves information about a display monitor.
***  


## Code examples:
[How to change display settings: screen resolution, screen refresh rate](../../samples/sample_374.md)  
[How to detect if additional monitor is connected and active](../../samples/sample_542.md)  

## Declaration:
```foxpro  
BOOL GetMonitorInfo(
  HMONITOR hMonitor,  // handle to display monitor
  LPMONITORINFO lpmi  // display monitor information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMonitorInfo IN user32;
	INTEGER  hMonitor,;
	STRING @ lpmi
  
```  
***  


## Parameters:
hMonitor 
[in] Handle to the display monitor of interest.

lpmi 
[out] Pointer to a MONITORINFO or MONITORINFOEX structure that receives information about the specified display monitor.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Returned structure type, MONITORINFO or MONITORINFOEX, is defined by <Em>cbSize</Em> member set before calling this function. The MONITORINFOEX structure is a superset of the MONITORINFO structure.  
  
hMonitor value can be obtained from a call to either of EnumDisplayMonitors, MonitorFromWindow, MonitorFromPoint, MonitorFromRect.  
  
The EnumDisplayMonitors is unlikely to be used in pure FoxPro code since it requires a callback function.  
  
See also [EnumDisplayDevices](EnumDisplayDevices.md), [EnumDisplaySettings](EnumDisplaySettings.md) functions.  
  
***  

