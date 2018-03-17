<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsWow64Process
Group: Process and Thread - Library: kernel32    
***  


#### Determines whether the specified process is running under WOW64.
***  


## Code examples:
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[How to check whether the system is 32-bit or 64-bit](../../samples/sample_580.md)  

## Declaration:
```foxpro  
BOOL WINAPI IsWow64Process(
  __in   HANDLE hProcess,
  __out  PBOOL Wow64Process
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsWow64Process IN kernel32;
	INTEGER hProcess,;
	INTEGER @Wow64Process  
```  
***  


## Parameters:
```txt  
hProcess [in]
A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right.

Wow64Process [out]
A pointer to a value that is set to TRUE if the process is running under WOW64.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

