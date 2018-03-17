<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessTimes
Group: Process and Thread - Library: kernel32    
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
```txt  
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
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function provides a way to know when the process has started.  
  
See also: GetProcessIoCounters, GetProcessVersion, GetProcessMemoryInfo   
  
***  

