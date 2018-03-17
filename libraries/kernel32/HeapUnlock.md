<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : HeapUnlock
Group: Memory Management - Library: kernel32    
***  


#### Releases ownership of the critical section object, or lock, that is associated with a specified heap. The HeapUnlock function reverses the action of the HeapLock function.
***  


## Code examples:
[Obtaining heap handles and enumerating memory blocks for the current VFP session (WinNT only)](../../samples/sample_176.md)  

## Declaration:
```foxpro  
BOOL HeapUnlock(
  HANDLE hHeap   // handle to heap
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapUnlock IN kernel32;
	INTEGER hHeap  
```  
***  


## Parameters:
```txt  
hHeap
[in] Handle to the heap to unlock.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
The HeapLock function is primarily useful for preventing the allocation and release of heap memory by other threads while the calling thread uses the HeapWalk function. The HeapUnlock function is the inverse of HeapLock.  
  
***  

