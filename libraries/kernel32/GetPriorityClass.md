<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetPriorityClass
Group: Process and Thread - Library: kernel32    
***  


#### Retrieves the priority class for the specified process. This value, together with the priority value of each thread of the process, determines each thread"s base priority level.
***  


## Code examples:
[Retrieving the priority class for the current process](../../samples/sample_173.md)  
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  

## Declaration:
```foxpro  
DWORD GetPriorityClass(
  HANDLE hProcess   // handle to process
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPriorityClass IN kernel32;
	INTEGER hProcess  
```  
***  


## Parameters:
```txt  
hProcess
[in] Handle to the process.  
```  
***  


## Return value:
If the function succeeds, the return value is the priority class of the specified process. If the function fails, the return value is zero.  
***  

