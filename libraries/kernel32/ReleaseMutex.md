[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReleaseMutex
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Releases ownership of the specified mutex object.
***  


## Code examples:
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  

## Declaration:
```foxpro  
BOOL ReleaseMutex(
	HANDLE hMutex
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReleaseMutex IN kernel32;
	INTEGER hMutex  
```  
***  


## Parameters:
hMutex 
[in] Handle to the mutex object. The CreateMutex or OpenMutex function returns this handle.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A thread obtains ownership of a mutex either by creating it with the bInitialOwner parameter set to TRUE or by specifying its handle in a call to one of the wait functions, like WaitForSingleObject.   
  
When the thread no longer needs to own the mutex object, it calls the ReleaseMutex function so that another thread can acquire ownership.  
  
Use the CloseHandle function to close the handle of a mutex object. The system closes the handle automatically when the process terminates. The mutex object is destroyed when its last handle has been closed.  
  
See also: [CreateMutex](../kernel32/CreateMutex.md), [CreateSemaphore](../kernel32/CreateSemaphore.md).  
  
***  

