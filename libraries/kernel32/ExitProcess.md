[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExitProcess
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The ExitProcess function ends a process and all its threads.
***  


## Declaration:
```foxpro  
VOID ExitProcess(
  UINT uExitCode   // exit code for all threads
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE ExitProcess IN kernel32 INTEGER uExitCode  
```  
***  


## Parameters:
uExitCode 
[in] Specifies the exit code for the process, and for all threads that are terminated as a result of this call.  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Use the GetExitCodeProcess function to retrieve the process"s exit value. Use the GetExitCodeThread function to retrieve a thread"s exit value.   
  
***  

