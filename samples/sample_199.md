[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the heap of the calling process to allocate memory blocks

## Code:
```foxpro  
DO decl
#DEFINE HEAP_ZERO_MEMORY 8

LOCAL lnAlloc0, lnAlloc1, hProcHeap, hMem

* retrieving a handle to the heap of the calling process
hProcHeap = GetProcessHeap()

? "Retrieving the handle of the calling process heap:", hProcHeap
?

* three number of bytes values to allocate
lnAlloc0 = 4096
lnAlloc1 = 0x20000
lnAlloc2 = 0xffff

? "Allocating and resizing a memory block from the process heap:"
hMem = HeapAlloc (hProcHeap, HEAP_ZERO_MEMORY, lnAlloc0)
? "   - allocated:",;
	HeapSize(hProcHeap, 0, hMem), ", handle: ", hMem

* resizing the memory block - the first try
hMem = HeapReAlloc (hProcHeap, HEAP_ZERO_MEMORY, hMem, lnAlloc1)
? "   - reallocated:",;
	HeapSize(hProcHeap, 0, hMem), ", handle: ", hMem

* resizing the memory block - the second try
hMem = HeapReAlloc (hProcHeap, HEAP_ZERO_MEMORY, hMem, lnAlloc2)
? "   - reallocated:",;
	HeapSize(hProcHeap, 0, hMem), ", handle: ", hMem

?
? "Releasing allocated memory block:",;
	Iif (HeapFree(hProcHeap, 0,hMem)=0, "failed", "Ok")

PROCEDURE  decl
	DECLARE INTEGER GetProcessHeap IN kernel32

	DECLARE INTEGER HeapAlloc IN kernel32;
		INTEGER hHeap, INTEGER dwFlags, INTEGER dwBytes

	DECLARE INTEGER HeapSize IN kernel32;
		INTEGER hHeap, INTEGER dwFlags, INTEGER lpMem

	DECLARE INTEGER HeapFree IN kernel32;
		INTEGER hHeap, INTEGER dwFlags, INTEGER lpMem

	DECLARE INTEGER HeapReAlloc IN kernel32;
		INTEGER hHeap, INTEGER dwFlags, INTEGER lpMem,;
		INTEGER dwBytes  
```  
***  


## Listed functions:
[GetProcessHeap](../libraries/kernel32/GetProcessHeap.md)  
[HeapAlloc](../libraries/kernel32/HeapAlloc.md)  
[HeapFree](../libraries/kernel32/HeapFree.md)  
[HeapReAlloc](../libraries/kernel32/HeapReAlloc.md)  
[HeapSize](../libraries/kernel32/HeapSize.md)  
