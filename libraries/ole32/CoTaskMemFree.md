[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CoTaskMemFree
Group: [COM](../../functions_group.md#COM)  -  Library: [ole32](../../Libraries.md#ole32)  
***  


#### Frees a block of task memory previously allocated through a call to the CoTaskMemAlloc or CoTaskMemRealloc function.
***  


## Code examples:
[Reading and setting explicit Application User Model ID for the current process (Win7)](../../samples/sample_038.md)  
[Accessing the list of Windows Recent Documents](../../samples/sample_094.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
void CoTaskMemFree(
	__in_opt  LPVOID pv
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE CoTaskMemFree IN Ole32;
	INTEGER hMem  
```  
***  


## Parameters:
pv [in, optional]
A pointer to the memory block to be freed. If this parameter is NULL, the function has no effect.  
***  


## Return value:
This function does not return a value.  
***  

