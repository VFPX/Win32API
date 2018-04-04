[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPriorityClass
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hProcess 
[in] Handle to the process.  
***  


## Return value:
If the function succeeds, the return value is the priority class of the specified process. If the function fails, the return value is zero.  
***  

