[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetPriorityClass
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hProcess 
[in] Handle to the process. 

dwPriorityClass 
[in] Specifies the priority class for the process. This parameter can be one of the predefined values.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

