[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcessTimes
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves timing information for the specified process.
***  


## Code examples:
[How to find when the application started](../../samples/sample_534.md)  

## Declaration:
```foxpro  
BOOL WINAPI GetProcessTimes(
  __in   HANDLE hProcess,
  __out  LPFILETIME lpCreationTime,
  __out  LPFILETIME lpExitTime,
  __out  LPFILETIME lpKernelTime,
  __out  LPFILETIME lpUserTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessTimes IN kernel32;
	INTEGER hProcess,;
	STRING @lpCreationTime,;
	STRING @lpExitTime,;
	STRING @lpKernelTime,;
	STRING @lpUserTime  
```  
***  


## Parameters:
hProcess 
A handle to the process whose timing information is sought. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right.

lpCreationTime 
A pointer to a FILETIME structure that receives the creation time of the process.

lpExitTime 
A pointer to a FILETIME structure that receives the exit time of the process.

lpKernelTime 
A pointer to a FILETIME structure that receives the amount of time that the process has executed in kernel mode. 

lpUserTime 
A pointer to a FILETIME structure that receives the amount of time that the process has executed in user mode. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function provides a way to know when the process has started.  
  
See also: [GetProcessIoCounters](../kernel32/GetProcessIoCounters.md), [GetProcessVersion](../kernel32/GetProcessVersion.md), [GetProcessMemoryInfo](../psapi/GetProcessMemoryInfo.md).  
  
***  

