[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : TerminateProcess
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The TerminateProcess function terminates the specified process and all of its threads.
***  


## Code examples:
[Start an executable from VFP application by using the CreateProcess](../../samples/sample_003.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
BOOL TerminateProcess(
  HANDLE hProcess, // handle to the process
  UINT uExitCode   // exit code for the process
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER TerminateProcess IN kernel32;
	INTEGER hProcess,;
	INTEGER uExitCode  
```  
***  


## Parameters:
hProcess 
[in] Handle to the process to terminate. 

uExitCode 
[in] Specifies the exit code for the process and for all threads terminated as a result of this call.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

