<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMonitorContrast
Group: Monitor Configuration (Vista) - Library: dxva2    
***  


#### Retrieves the minimum, maximum, and current contrast settings for a monitor.
***  


## Declaration:
```foxpro  
BOOL GetMonitorContrast(
  HANDLE  hMonitor,
  LPDWORD  pdwMinimumContrast,
  LPDWORD  pdwCurrentContrast,
  LPDWORD  pdwMaximumContrast
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMonitorContrast IN dxva2;
	INTEGER hMonitor,;
	LONG @pdwMinimumContrast,;
	LONG @pdwCurrentContrast,;
	LONG @pdwMaximumContrast  
```  
***  


## Parameters:
```txt  
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

pdwMinimumContrast
[out]  Receives the monitor"s minimum contrast.

pdwCurrentContrast
[out]  Receives the monitor"s current contrast.

pdwMaximumContrast
[out]  Receives the monitor"s maximum contrast.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: SetMonitorContrast   
  
***  

