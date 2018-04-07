[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcessIoCounters
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves accounting information for all I/O operations performed by the specified process.
***  


## Code examples:
[Obtaining I/O counts for the current process](../../samples/sample_535.md)  

## Declaration:
```foxpro  
BOOL WINAPI GetProcessIoCounters(
	__in   HANDLE hProcess,
	__out  PIO_COUNTERS lpIoCounters
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessIoCounters IN kernel32;
	INTEGER hProcess,;
	STRING @lpIoCounters  
```  
***  


## Parameters:
hProcess 
A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right.

lpIoCounters 
A pointer to an IO_COUNTERS structure that receives the I/O accounting information for the process.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [GetProcessTimes](../kernel32/GetProcessTimes.md), [GetProcessVersion](../kernel32/GetProcessVersion.md), [GetProcessMemoryInfo](../psapi/GetProcessMemoryInfo.md).  
  
***  

