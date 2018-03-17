<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessIoCounters
Group: Process and Thread - Library: kernel32    
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
```txt  
hProcess
A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right.

lpIoCounters
A pointer to an IO_COUNTERS structure that receives the I/O accounting information for the process.
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: GetProcessTimes, GetProcessVersion, GetProcessMemoryInfo   
  
***  

