[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapValidate
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Attempts to validate a specified heap. The function scans all the memory blocks in the heap, and verifies that the heap control structures maintained by the heap manager are in a consistent state.

You can also use the HeapValidate function to validate a single memory block within a specified heap, without checking the validity of the entire heap.
***  


## Code examples:
[Validating the heap of the calling process](../../samples/sample_200.md)  

## Declaration:
```foxpro  
BOOL HeapValidate(
  HANDLE hHeap,  // handle to heap
  DWORD dwFlags, // heap access options
  LPCVOID lpMem  // optional pointer to memory block
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapValidate IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags,;
	INTEGER lpMem  
```  
***  


## Parameters:
hHeap 
[in] Handle to the heap of interest. The HeapValidate function attempts to validate this heap, or a single memory block within this heap. 

dwFlags 
[in] Specifies heap access during function operation. 

lpMem 
[in] Pointer to a memory block within the specified heap. This parameter may be NULL. 
If this parameter is NULL, the function attempts to validate the entire heap specified by hHeap.  
***  


## Return value:
If the specified heap or memory block is valid, the return value is nonzero.  
***  


## Comments:
The HeapValidate function does not set the thread"s last error value. There is no extended error information for this function; do not call GetLastError.  
  
HeapValidate can only validate allocated memory blocks. Calling HeapValidate on a freed memory block will return FALSE because there are no control structures to validate.   
  
If you want to validate the heap elements enumerated by the HeapWalk function, you should only call HeapValidate on the elements that have PROCESS_HEAP_ENTRY_BUSY in the wFlags member of the PROCESS_HEAP_ENTRY structure. HeapValidate returns FALSE for all heap elements that do not have this bit set.   
  
***  

