[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Validating the heap of the calling process

## Code:
```foxpro  
DO decl

#DEFINE HEAP_ZERO_MEMORY   8

* MSDN: the HEAP_NO_SERIALIZE value can, be safely used
* the process has only one thread -- this is how the VFP is
#DEFINE HEAP_NO_SERIALIZE  1

LOCAL hProcHeap, lnFreeSize

* retrieving a handle to the heap of the calling process
hProcHeap = GetProcessHeap()
? "Calling process heap handle:", hProcHeap

* making an attempt to compact the calling process heap
* supported in Windows NT/2000/XP, not in Windows 95/98/Me
lnFreeSize = HeapCompact (hProcHeap, HEAP_NO_SERIALIZE)
IF lnFreeSize = 0
* 120 = This function is not supported on this system.
	? "Error code:", GetLastError()
ELSE
	? "The largest committed free block in the heap:",;
			ALLTRIM(TRANS(lnFreeSize, "999,999,999,999,999")), "bytes"
ENDIF

* validating the calling process heap
? "The heap is valid:",;
	Iif(HeapValidate (hProcHeap, HEAP_NO_SERIALIZE, 0)=0, "No","Yes")

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetProcessHeap IN kernel32

	DECLARE INTEGER HeapCompact IN kernel32;
		INTEGER hHeap, INTEGER dwFlags

	DECLARE INTEGER HeapValidate IN kernel32;
		INTEGER hHeap, INTEGER dwFlags, INTEGER lpMem  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProcessHeap](../libraries/kernel32/GetProcessHeap.md)  
[HeapCompact](../libraries/kernel32/HeapCompact.md)  
[HeapValidate](../libraries/kernel32/HeapValidate.md)  
