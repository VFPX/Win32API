[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AssignProcessToJobObject
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Assigns a process to an existing job object.
***  


## Code examples:
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  

## Declaration:
```foxpro  
BOOL AssignProcessToJobObject(
	HANDLE hJob,
	HANDLE hProcess
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AssignProcessToJobObject IN kernel32;
	INTEGER hJob,;
	INTEGER hProcess  
```  
***  


## Parameters:
hJob 
[in] Handle to the job object to which the process will be associated.

hProcess 
[in] Handle to the process to associate with the job object.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A process can be associated only with a single job.  
  
***  

