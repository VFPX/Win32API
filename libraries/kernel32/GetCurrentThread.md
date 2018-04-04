[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrentThread
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetCurrentThread function retrieves a <Strong>pseudo</Strong> handle for the current thread.
***  


## Code examples:
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  

## Declaration:
```foxpro  
HANDLE GetCurrentThread(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentThread;
	IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is a <Strong>pseudo</Strong> handle for the current thread.  
***  


## Comments:
A pseudo handle is a special constant that is interpreted as the current thread handle. The calling thread can use this handle to specify itself whenever a thread handle is required. Pseudo handles are not inherited by child processes.  
  
***  

