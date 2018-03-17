<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetMonitorContrast
Group: Monitor Configuration (Vista) - Library: dxva2    
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
```txt  
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

dwNewContrast
[in]  Contrast value. To get the monitor"s minimum and maximum contrast values, call, call GetMonitorContrast.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If this function is supported, the GetMonitorCapabilities function returns the MC_CAPS_CONTRAST flag.  
  
See also: GetMonitorContrast, GetMonitorBrightness   
  
***  

