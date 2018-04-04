[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapFree
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The HeapFree function frees a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.
***  


## Code examples:
[Using the heap of the calling process to allocate memory blocks](../../samples/sample_199.md)  

## Declaration:
```foxpro  
BOOL HeapFree(
  HANDLE hHeap,  // handle to heap
  DWORD dwFlags, // heap free options
  LPVOID lpMem   // pointer to memory
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapFree IN kernel32;
	INTEGER hHeap,;
	INTEGER dwFlags,;
	INTEGER lpMem  
```  
***  


## Parameters:
hHeap 
[in] Specifies the heap whose memory block the function frees. This parameter is a handle returned by the HeapCreate or GetProcessHeap function. 

dwFlags 
[in] Specifies several controllable aspects of freeing a memory block. 

lpMem 
[in] Pointer to the memory block to free. This pointer is returned by the HeapAlloc or HeapReAlloc function. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

