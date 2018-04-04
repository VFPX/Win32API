[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HeapLock
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Attempts to acquire the critical section object, or lock, that is associated with a specified heap. 
***  


## Code examples:
[Obtaining heap handles and enumerating memory blocks for the current VFP session (WinNT only)](../../samples/sample_176.md)  

## Declaration:
```foxpro  
BOOL HeapLock(
  HANDLE hHeap   // handle to heap
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapLock IN kernel32;
	INTEGER hHeap  
```  
***  


## Parameters:
hHeap 
[in] Handle to the heap to lock for exclusive access by the calling thread.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
The HeapLock function is primarily useful for preventing the allocation and release of heap memory by other threads while the calling thread uses the HeapWalk function.  
  
Each call to HeapLock must be matched by a corresponding call to the HeapUnlock function.   
  
***  

