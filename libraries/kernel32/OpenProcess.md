[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenProcess
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The OpenProcess function opens an existing process object.
***  


## Code examples:
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[How to find when the application started](../../samples/sample_534.md)  
[Obtaining I/O counts for the current process](../../samples/sample_535.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
HANDLE OpenProcess(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // handle inheritance option
  DWORD dwProcessId       // process identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenProcess IN kernel32;
	INTEGER dwDesiredAccessas,;
	INTEGER bInheritHandle,;
	INTEGER dwProcId  
```  
***  


## Parameters:
dwDesiredAccess 
[in] Specifies the access to the process object. 

bInheritHandle 
[in] Specifies whether the returned handle can be inherited by a new process created by the current process. 

dwProcessId 
[in] Specifies the identifier of the process to open.   
***  


## Return value:
If the function succeeds, the return value is an open handle to the specified process. If the function fails, the return value is NULL.  
***  


## Comments:
MSDN: the handle returned by the OpenProcess function can be used in any function that requires a handle to a process, such as the wait functions, provided the appropriate access rights were requested. When you are finished with the handle, be sure to close it using the CloseHandle function.  
  
***  

