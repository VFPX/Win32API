[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcessMemoryInfo
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### Retrieves information about the memory usage of the specified process in the PROCESS_MEMORY_COUNTERS structure.
***  


## Code examples:
[Memory usage info for current VFP session (WinNT only)](../../samples/sample_172.md)  

## Declaration:
```foxpro  
BOOL GetProcessMemoryInfo(
  HANDLE Process,                          // handle to process
  PPROCESS_MEMORY_COUNTERS ppsmemCounters, // buffer
  DWORD cb                                 // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessMemoryInfo IN psapi;
	INTEGER  Process,;
	STRING @ ppsmemCounters,;
	INTEGER  cb  
```  
***  


## Parameters:
Process 
[in] Handle to the process. 

ppsmemCounters 
[out] Pointer to the PROCESS_MEMORY_COUNTERS structure that receives information about the memory usage of the process. 

cb 
[in] Specifies the size, in bytes, of the PROCESS_MEMORY_COUNTERS structure. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
See also WinNT Performance Monitor.  
  
See also: [GetProcessIoCounters](../kernel32/GetProcessIoCounters.md), [GetProcessTimes](../kernel32/GetProcessTimes.md), [GetProcessVersion](../kernel32/GetProcessVersion.md).  
  
***  

