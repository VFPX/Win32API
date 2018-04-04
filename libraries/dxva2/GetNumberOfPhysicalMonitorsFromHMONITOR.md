[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNumberOfPhysicalMonitorsFromHMONITOR
Group: [Monitor Configuration (Vista)](../../functions_group.md#Monitor_Configuration_(Vista))  -  Library: [dxva2](../../Libraries.md#dxva2)  
***  


#### Retrieves the number of physical monitors associated with an HMONITOR monitor handle.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL GetNumberOfPhysicalMonitorsFromHMONITOR(
  HMONITOR  hMonitor,
  LPDWORD  pdwNumberOfPhysicalMonitors
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNumberOfPhysicalMonitorsFromHMONITOR IN dxva2;
	INTEGER hMonitor,;
	LONG @pdwNumberOfPhysicalMonitors  
```  
***  


## Parameters:
hMonitor
[in]  A monitor handle. Monitor handles are returned by several Multiple Display Monitor functions, including EnumDisplayMonitors and MonitorFromWindow.

pdwNumberOfPhysicalMonitors
[out]  Receives the number of physical monitors associated with the monitor handle.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Call this function before calling GetPhysicalMonitorsFromHMONITOR.  
  
This is a really long name for API function. The whole group of the Monitor Configuration functions sports very long, supposedly extra meaningful, function names.   
  
This one I like especially -- <Em>GetNumberOfPhysicalMonitorsFromIDirect3DDevice9</Em> -- though I might need to add changes to the PHP code on my site to accomodate names like this.  
  
This must be a new Microsoft trend in naming functions. Otherwise we would have already enjoyed API functions like <Em>DownloadAFileFromFTPServerConnected</Em> instead of boringly undescriptive FtpGetFile. I must be raving.  
  
***  

