[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapReAlloc
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The HeapReAlloc function reallocates a block of memory from a heap. This function enables you to resize a memory block and change other memory block properties. The allocated memory is not movable.
***  


## Code examples:
[Using the heap of the calling process to allocate memory blocks](../../samples/sample_199.md)  

## Declaration:
```foxpro  
LPVOID HeapReAlloc(
  HANDLE hHeap,   // handle to heap block
  DWORD dwFlags,  // heap reallocation options
  LPVOID lpMem,   // pointer to memory to reallocate
  SIZE_T dwBytes  // number of bytes to reallocate
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapReAlloc IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags,;
	INTEGER lpMem,;
	INTEGER dwBytes  
```  
***  


## Parameters:
hHeap 
[in] Heap from which the memory will be reallocated. This is a handle returned by the HeapCreate or GetProcessHeap function. 

dwFlags 
[in] Specifies several controllable aspects of heap reallocation. 

lpMem 
[in] Pointer to the block of memory that the function reallocates. This pointer is returned by an earlier call to the HeapAlloc or HeapReAlloc function. 

dwBytes 
[in] New size of the memory block, in bytes. A memory block"s size can be increased or decreased by using this function.   
***  


## Return value:
If the function succeeds, the return value is a pointer to the reallocated memory block. Otherwise the return is NULL or an exception generated if you have specified HEAP_GENERATE_EXCEPTIONS in dwFlags.  
***  


## Comments:
MSDN: If HeapReAlloc fails, the original memory is not freed, and the original handle and pointer are still valid. To free a block of memory allocated by HeapReAlloc, use the HeapFree function.  
  
***  

