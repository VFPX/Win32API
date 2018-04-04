[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetThreadPriority
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base-priority level.
***  


## Code examples:
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  

## Declaration:
```foxpro  
int GetThreadPriority(
  HANDLE hThread   // handle to thread
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetThreadPriority IN kernel32;
	INTEGER hThread  
```  
***  


## Parameters:
hThread 
[in] Handle to the thread.   
***  


## Return value:
If the function succeeds, the return value is the thread"s priority level. If the function fails, the return value is THREAD_PRIORITY_ERROR_RETURN = MAXLONG = 0x7FFFFFFF.  
***  

