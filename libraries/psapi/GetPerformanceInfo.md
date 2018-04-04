[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPerformanceInfo
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### Retrieves the performance values contained in the PERFORMANCE_INFORMATION structure.
***  


## Code examples:
[Obtaining OS memory performance information](../../samples/sample_567.md)  

## Declaration:
```foxpro  
BOOL WINAPI GetPerformanceInfo(
	__out  PPERFORMANCE_INFORMATION
		pPerformanceInformation,
	__in   DWORD cb
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPerformanceInfo in psapi;
	STRING @pPerfInfo,;
	LONG cb
  
```  
***  


## Parameters:
pPerformanceInformation [out]
A pointer to a PERFORMANCE_INFORMATION structure that receives the performance information.

cb [in]
The size of the PERFORMANCE_INFORMATION structure, in bytes.  
***  


## Return value:
If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE. To get extended error information, call GetLastError.  
***  

