[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : TerminateJobObject
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Terminates all processes currently associated with the job.

***  


## Code examples:
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  

## Declaration:
```foxpro  
BOOL TerminateJobObject(
	HANDLE hJob,
	UINT uExitCode
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER TerminateJobObject IN kernel32;
	INTEGER hJob,;
	LONG    uExitCode
  
```  
***  


## Parameters:
hJob 
[in] Handle to the job whose processes will be terminated. The CreateJobObject or OpenJobObject function returns this handle. 

uExitCode 
[in] Exit code to be used by all processes and threads in the job object.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
It is not possible for any of the processes associated with the job to postpone or handle the termination. It is as if TerminateProcess were called for each process associated with the job.  
  
***  

