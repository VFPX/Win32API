<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetPriorityClass
Group: Process and Thread - Library: kernel32    
***  


#### Sets the priority class for the specified process. This value together with the priority value of each thread of the process determines each thread"s base priority level.
***  


## Code examples:
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  

## Declaration:
```foxpro  
BOOL SetPriorityClass(
  HANDLE hProcess,        // handle to process
  DWORD dwPriorityClass   // priority class
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetPriorityClass IN kernel32;
	INTEGER hProcess,;
	INTEGER dwPriorityClass  
```  
***  


## Parameters:
```txt  
hProcess
[in] Handle to the process.

dwPriorityClass
[in] Specifies the priority class for the process. This parameter can be one of the predefined values.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

