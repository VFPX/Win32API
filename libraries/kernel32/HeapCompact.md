<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : HeapCompact
Group: Memory Management - Library: kernel32    
***  


#### Attempts to compact a specified heap. It compacts the heap by coalescing adjacent free blocks of memory and decommitting large free blocks of memory.
***  


## Code examples:
[Validating the heap of the calling process](../../samples/sample_200.md)  

## Declaration:
```foxpro  
UINT HeapCompact(
  HANDLE hHeap,  // handle to heap
  DWORD dwFlags  // heap access options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapCompact IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags  
```  
***  


## Parameters:
```txt  
hHeap
[in] Handle to the heap that the function will attempt to compact.

dwFlags
[in] Specifies heap access during function operation.  
```  
***  


## Return value:
If the function succeeds, the return value is the size, in bytes, of the largest committed free block in the heap. If the function fails, the return value is zero. 
  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

