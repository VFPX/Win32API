<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CoTaskMemFree
Group: COM - Library: ole32    
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
```txt  
pv [in, optional]
A pointer to the memory block to be freed. If this parameter is NULL, the function has no effect.  
```  
***  


## Return value:
This function does not return a value.  
***  

