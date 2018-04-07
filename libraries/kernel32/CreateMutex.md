[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateMutex
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates or opens a named or unnamed mutex object.
***  


## Code examples:
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  

## Declaration:
```foxpro  
HANDLE CreateMutex(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	BOOL bInitialOwner,
	LPCTSTR lpName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateMutex IN kernel32;
	INTEGER lpMutexAttributes,;
	INTEGER bInitialOwner,;
	STRING  lpName  
```  
***  


## Parameters:
lpMutexAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. If lpMutexAttributes is NULL, the handle cannot be inherited.

bInitialOwner 
[in] If this value is TRUE and the caller created the mutex, the calling thread obtains initial ownership of the mutex object.

lpName 
[in] Pointer to a null-terminated string specifying the name of the mutex object. If lpName is NULL, the mutex object is created without a name.  
***  


## Return value:
If the function succeeds, the return value is a handle to the newly created mutex object.  
***  


## Comments:
If the mutex is a named mutex and the object existed before this function call, the return value is a handle to the existing object and GetLastError returns ERROR_ALREADY_EXISTS.  
  
See also: [ReleaseMutex](../kernel32/ReleaseMutex.md), [CloseHandle](../kernel32/CloseHandle.md), [CreateSemaphore](../kernel32/CreateSemaphore.md), [WaitForSingleObject](../kernel32/WaitForSingleObject.md).  
  
***  

