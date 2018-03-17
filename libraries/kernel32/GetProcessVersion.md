<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessVersion
Group: Process and Thread - Library: kernel32    
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
```txt  
ProcessId
[in] Process identifier that specifies the process of interest. A value of zero specifies the calling process.  
```  
***  


## Return value:
If the function succeeds, the return value is the version of the system on which the process expects to run. If the function fails, the return value is zero.   
***  


## Comments:
The version number returned by this function is the version number stamped in the image header of the .exe file the process is running. Linker programs set this value.   
  
See also: GetProcessIoCounters, GetProcessTimes,  GetProcessMemoryInfo   
  
***  

