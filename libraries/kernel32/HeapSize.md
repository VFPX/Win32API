[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapSize
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The HeapSize function retrieves the size of a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.
***  


## Code examples:
[Using the heap of the calling process to allocate memory blocks](../../samples/sample_199.md)  

## Declaration:
```foxpro  
DWORD HeapSize(
  HANDLE hHeap,  // handle to heap
  DWORD dwFlags, // heap size options
  LPCVOID lpMem  // pointer to memory
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapSize IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags,;
	INTEGER lpMem  
```  
***  


## Parameters:
hHeap 
[in] Specifies the heap in which the memory block resides. This handle is returned by the HeapCreate or GetProcessHeap function. 

dwFlags 
[in] Specifies several controllable aspects of accessing the memory block. 

lpMem 
[in] Pointer to the memory block whose size the function will obtain. This is a pointer returned by the HeapAlloc or HeapReAlloc function.   
***  


## Return value:
If the function succeeds, the return value is the size, in bytes, of the allocated memory block.

If the function fails, the return value is -1. The function does not call SetLastError. An application cannot call GetLastError for extended error information.  
***  

