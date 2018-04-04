[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrentThreadId
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetCurrentThreadId function retrieves the thread identifier of the calling thread.
***  


## Code examples:
[Obtaining a handle to the desktop associated with the calling thread](../../samples/sample_239.md)  
[Retrieveing information about the active window (even if it is not owned by the calling process)](../../samples/sample_371.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
DWORD GetCurrentThreadId(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentThreadId;
	IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is the thread identifier of the calling thread.  
***  


## Comments:
Until the thread terminates, the thread identifier uniquely identifies the thread throughout the system.  
  
***  

