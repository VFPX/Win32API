[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapAlloc
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The HeapAlloc function allocates a block of memory from a heap. The allocated memory is <Strong>not movable</Strong>.
***  


## Code examples:
[Using the heap of the calling process to allocate memory blocks](../../samples/sample_199.md)  

## Declaration:
```foxpro  
LPVOID HeapAlloc(
  HANDLE hHeap,   // handle to private heap block
  DWORD dwFlags,  // heap allocation control
  SIZE_T dwBytes  // number of bytes to allocate
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapAlloc IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags,;
	INTEGER dwBytes  
```  
***  


## Parameters:
hHeap 
[in] Specifies the heap from which the memory will be allocated. This parameter is a handle returned by the HeapCreate or GetProcessHeap function. 

dwFlags 
[in] Specifies several controllable aspects of heap allocation. Specifying any of these values will override the corresponding value specified when the heap was created with HeapCreate. 

dwBytes 
[in] Specifies the number of bytes to be allocated.   
***  


## Return value:
If the function succeeds, the return value is a pointer to the allocated memory block. If the function fails the return value is NULL or an exception generated if you have specified HEAP_GENERATE_EXCEPTIONS in dwFlags.
  
***  


## Comments:
MSDN: To determine the actual size of the allocated block, use the HeapSize function. To free a block of memory allocated by HeapAlloc, use the HeapFree function. Memory allocated by HeapAlloc is not movable. Since the memory is not movable, it is possible for the heap to become fragmented.  
  
***  

