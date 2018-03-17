<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DestroyPhysicalMonitors
Group: Monitor Configuration (Vista) - Library: dxva2    
***  


#### Closes an array of open monitor handles. That is one of a scary name for API function.
***  


## Code examples:
[How to adjust monitor brightness (Vista, monitor with DDC support)](../../samples/sample_543.md)  

## Declaration:
```foxpro  
BOOL DestroyPhysicalMonitors(
  DWORD dwPhysicalMonitorArraySize,
  LPPHYSICAL_MONITOR pPhysicalMonitorArray
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DestroyPhysicalMonitors IN dxva2;
	LONG dwPhysicalMonitorArraySize,;
	STRING @pPhysicalMonitorArray  
```  
***  


## Parameters:
```txt  
dwPhysicalMonitorArraySize
[in]  Number of elements in the pPhysicalMonitorArray array.

pPhysicalMonitorArray
[in]  Pointer to an array of PHYSICAL_MONITOR structures.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Call this function to close an array of monitor handles obtained from the GetPhysicalMonitorsFromHMONITOR or GetPhysicalMonitorsFromIDirect3DDevice9 function.  
  
***  

