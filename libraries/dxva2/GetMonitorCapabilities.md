[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMonitorCapabilities
Group: [Monitor Configuration (Vista)](../../functions_group.md#Monitor_Configuration_(Vista))  -  Library: [dxva2](../../Libraries.md#dxva2)  
***  


#### Retrieves the configuration capabilities of a monitor. Call this function to find out which high-level monitor configuration functions are supported by the monitor.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL GetMonitorCapabilities(
  HANDLE  hMonitor,
  LPDWORD  pdwMonitorCapabilities,
  LPDWORD  pdwSupportedColorTemperatures
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMonitorCapabilities IN dxva2;
	INTEGER hMonitor,;
	LONG @pdwMonitorCapabilities,;
	LONG @pdwSupportedColorTemperatures  
```  
***  


## Parameters:
hMonitor
[in]  Handle to a physical monitor. To get the monitor handle, call GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9.

pdwMonitorCapabilities
[out]  Receives a bitwise OR of capabilities flags. See Remarks.

pdwSupportedColorTemperatures
[out]  Receives a bitwise OR of color temperature flags. See Remarks.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The GetMonitorCapabilities function fails if the monitor does not support the <a href="http://en.wikipedia.org/wiki/Display_Data_Channel">Display Data Channel</a> (DDC/CI).  
  
* * *  
That is what the function returns for SyncMaster T240:  
  
The capabilities flags value is 7199 (1110000011111).   
  
There are currently 13 capabilities flags defining which high-level configuration function is supported by this monitor including GETs and/or SETs for brightness, color temperature, contrast, display area position & size, factory defaults and more.  
  
The color temperature flags value is 129 (10000001), which indicates support for 4000K and 11500K color temperatures.  
  
***  

