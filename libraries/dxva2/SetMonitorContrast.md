[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetMonitorContrast
Group: [Monitor Configuration (Vista)](../../functions_group.md#Monitor_Configuration_(Vista))  -  Library: [dxva2](../../Libraries.md#dxva2)  
***  


#### Sets the contrast value for a monitor. 
***  


## Declaration:
```foxpro  
BOOL SetMonitorContrast(
  HANDLE  hMonitor,
  DWORD  dwNewContrast
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMonitorContrast IN dxva2;
	INTEGER hMonitor,;
	LONG dwNewContrast  
```  
***  


## Parameters:
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

dwNewContrast
[in]  Contrast value. To get the monitor"s minimum and maximum contrast values, call, call GetMonitorContrast.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If this function is supported, the GetMonitorCapabilities function returns the MC_CAPS_CONTRAST flag.  
  
See also: [GetMonitorContrast](../dxva2/GetMonitorContrast.md), [GetMonitorBrightness](../dxva2/GetMonitorBrightness.md).  
  
***  

