[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPhysicalMonitorsFromHMONITOR
Group: [Monitor Configuration (Vista)](../../functions_group.md#Monitor_Configuration_(Vista))  -  Library: [dxva2](../../Libraries.md#dxva2)  
***  


#### Retrieves the physical monitors associated with an HMONITOR monitor handle.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL GetPhysicalMonitorsFromHMONITOR(
  HMONITOR  hMonitor,
  DWORD  dwPhysicalMonitorArraySize,
  LPPHYSICAL_MONITOR  pPhysicalMonitorArray
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPhysicalMonitorsFromHMONITOR IN dxva2;
	INTEGER hMonitor,;
	LONG dwPhysicalMonitorArraySize,;
	STRING @pPhysicalMonitorArray  
```  
***  


## Parameters:
hMonitor
[in]  A monitor handle. Monitor handles are returned by several Multiple Display Monitor functions, including EnumDisplayMonitors and MonitorFromWindow.

dwPhysicalMonitorArraySize
[in]  Number of elements in pPhysicalMonitorArray. To get the required size of the array, call GetNumberOfPhysicalMonitorsFromHMONITOR.

pPhysicalMonitorArray
[out]  Pointer to an array of PHYSICAL_MONITOR structures. The caller must allocate the array.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
When you are done using the monitor handles, close them by passing the pPhysicalMonitorArray array to the DestroyPhysicalMonitors function.  
  
***  

