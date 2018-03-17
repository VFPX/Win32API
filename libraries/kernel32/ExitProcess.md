<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ExitProcess
Group: Process and Thread - Library: kernel32    
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
```txt  
uExitCode
[in] Specifies the exit code for the process, and for all threads that are terminated as a result of this call.  
```  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Use the GetExitCodeProcess function to retrieve the process"s exit value. Use the GetExitCodeThread function to retrieve a thread"s exit value.   
  
***  

