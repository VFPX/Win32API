[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsWow64Process
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hProcess [in]
A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right.

Wow64Process [out]
A pointer to a value that is set to TRUE if the process is running under WOW64.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

