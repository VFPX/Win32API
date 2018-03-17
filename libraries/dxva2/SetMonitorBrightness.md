<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetMonitorBrightness
Group: Monitor Configuration (Vista) - Library: dxva2    
***  


#### Sets a monitor"s brightness value.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL SetMonitorBrightness(
  HANDLE  hMonitor,
  DWORD  dwNewBrightness
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMonitorBrightness IN dxva2;
	INTEGER hMonitor,;
	LONG dwNewBrightness  
```  
***  


## Parameters:
```txt  
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

dwNewBrightness
[in]  Brightness value. To get the monitor"s minimum and maximum brightness values, call GetMonitorBrightness.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If this function is supported, the GetMonitorCapabilities function returns the MC_CAPS_BRIGHTNESS flag.  
  
See also: GetMonitorBrightness   
  
***  

