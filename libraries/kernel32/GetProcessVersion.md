[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcessVersion
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the major and minor version numbers of the system on which the specified process expects to run.
***  


## Code examples:
[GetProcessVersion points at target OS](../../samples/sample_170.md)  

## Declaration:
```foxpro  
DWORD GetProcessVersion(
  DWORD ProcessId  // process identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessVersion IN kernel32;
	INTEGER ProcessId  
```  
***  


## Parameters:
ProcessId 
[in] Process identifier that specifies the process of interest. A value of zero specifies the calling process.   
***  


## Return value:
If the function succeeds, the return value is the version of the system on which the process expects to run. If the function fails, the return value is zero.   
***  


## Comments:
The version number returned by this function is the version number stamped in the image header of the .exe file the process is running. Linker programs set this value.   
  
See also: [GetProcessIoCounters](../kernel32/GetProcessIoCounters.md), [GetProcessTimes](../kernel32/GetProcessTimes.md), [GetProcessMemoryInfo](../psapi/GetProcessMemoryInfo.md).  
  
***  

