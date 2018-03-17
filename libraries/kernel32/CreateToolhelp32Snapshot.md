<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateToolhelp32Snapshot
Group: Performance Monitoring - Library: kernel32    
***  


#### Takes a snapshot of the processes and the heaps, modules, and threads used by the processes.
***  


## Code examples:
[Enumerating Processes -- Win9*](../../samples/sample_164.md)  

## Declaration:
```foxpro  
HANDLE WINAPI CreateToolhelp32Snapshot(
  DWORD dwFlags,
  DWORD th32ProcessID
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateToolhelp32Snapshot IN kernel32;
	INTEGER dwFlags,;
	INTEGER th32ProcessID  
```  
***  


## Parameters:
```txt  
dwFlags
[in] Specifies portions of the system to include in the snapshot.

th32ProcessID
[in] Specifies the process identifier. This parameter can be zero to indicate the current process.  
```  
***  


## Return value:
Returns an open handle to the specified snapshot if successful or INVALID_HANDLE_VALUE (-1) otherwise.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows 2000 and later.  
Windows 95/98/Me: Included in Windows 95 and later.  
  
***  

