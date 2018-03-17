<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMonitorBrightness
Group: Monitor Configuration (Vista) - Library: dxva2    
***  


#### Retrieves the minimum, maximum, and current brightness settings for a monitor.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL GetMonitorBrightness(
  HANDLE  hMonitor,
  LPDWORD  pdwMinimumBrightness,
  LPDWORD  pdwCurrentBrightness,
  LPDWORD  pdwMaximumBrightness
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMonitorBrightness IN dxva2;
	INTEGER hMonitor,;
	LONG @pdwMinimumBrightness,;
	LONG @pdwCurrentBrightness,;
	LONG @pdwMaximumBrightness  
```  
***  


## Parameters:
```txt  
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

pdwMinimumBrightness
[out]  Receives the monitor"s minimum brightness.

pdwCurrentBrightness
[out]  Receives the monitor"s current brightness.

pdwMaximumBrightness
[out]  Receives the monitor"s maximum brightness.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If this function is supported, the GetMonitorCapabilities function returns the MC_CAPS_BRIGHTNESS flag.  
  
See also: SetMonitorBrightness   
  
***  

