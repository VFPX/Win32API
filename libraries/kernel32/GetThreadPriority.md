<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetThreadPriority
Group: Process and Thread - Library: kernel32    
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
```txt  
hThread
[in] Handle to the thread.  
```  
***  


## Return value:
If the function succeeds, the return value is the thread"s priority level. If the function fails, the return value is THREAD_PRIORITY_ERROR_RETURN = MAXLONG = 0x7FFFFFFF.  
***  

