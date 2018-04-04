[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetThreadPriority
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the priority value for the specified thread. This value, together with the priority class of the thread"s process, determines the thread"s base priority level.
***  


## Code examples:
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  

## Declaration:
```foxpro  
BOOL SetThreadPriority(
  HANDLE hThread, // handle to the thread
  int nPriority   // thread priority level
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetThreadPriority IN kernel32;
	INTEGER hThread,;
	INTEGER nPriority  
```  
***  


## Parameters:
hThread 
[in] Handle to the thread whose priority value is to be set. 

nPriority 
[in] Specifies the priority value for the thread. This parameter can be one of the predefined values.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

