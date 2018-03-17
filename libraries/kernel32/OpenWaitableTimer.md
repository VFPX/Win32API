<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : OpenWaitableTimer
Group: Synchronization - Library: kernel32    
***  


#### Opens an existing named waitable timer object.
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
HANDLE WINAPI OpenWaitableTimer(
	DWORD dwDesiredAccess,
	BOOL bInheritHandle,
	LPCTSTR lpTimerName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenWaitableTimer IN kernel32;
	LONG dwDesiredAccess,;
	INTEGER bInheritHandle,;
	STRING lpTimerName  
```  
***  


## Parameters:
```txt  
dwDesiredAccess
[in] Access to the timer object. The function fails if the security descriptor of the specified object does not permit the requested access for the calling process.

bInheritHandle
[in] If this value is TRUE, processes created by this process will inherit the handle.

lpTimerName
[in] Pointer to a null-terminated string specifying the name of the timer object.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the timer object.  
***  


## Comments:
The OpenWaitableTimer function enables multiple processes to open handles to the same timer object. The function succeeds only if some process has already created the timer using the CreateWaitableTimer function.  
  
The returned handle can be duplicated by using the DuplicateHandle function. Use the CloseHandle function to close the handle. The system closes the handle automatically when the process terminates. The timer object is destroyed when its last handle has been closed.  
  
***  

