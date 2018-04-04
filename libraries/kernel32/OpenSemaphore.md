[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenSemaphore
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The OpenSemaphore function returns a handle of an existing named semaphore object
***  


## Code examples:
[Using the Semaphore object](../../samples/sample_008.md)  
[Using the Semaphore object to allow only one instance of VFP application running](../../samples/sample_147.md)  

## Declaration:
```foxpro  
HANDLE OpenSemaphore(
  DWORD dwDesiredAccess,  // access
  BOOL bInheritHandle,    // inheritance option
  LPCTSTR lpName          // object name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenSemaphore IN kernel32;
	INTEGER dwDesiredAccess,;
	INTEGER bInheritHandle,;
	STRING  lpName
  
```  
***  


## Parameters:
fdwAccess
Specifies the requested access to the semaphore object

fInherit
Specifies whether the returned handle is inheritable

lpszSemName
Points to a null-terminated string that names the semaphore to be opened. Name comparisons are case sensitive  
***  


## Return value:
If the function succeeds, the return value is a handle of the semaphore object  
***  

