<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : HeapWalk
Group: Memory Management - Library: kernel32    
***  


#### Enumerates the memory blocks in a specified heap created or manipulated by heap memory allocators such as HeapAlloc, HeapReAlloc, and HeapFree.
***  


## Code examples:
[Obtaining heap handles and enumerating memory blocks for the current VFP session (WinNT only)](../../samples/sample_176.md)  

## Declaration:
```foxpro  
BOOL HeapWalk(
  HANDLE hHeap,                 // heap to enumerate
  LPPROCESS_HEAP_ENTRY lpEntry  // state information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HeapWalk IN kernel32;
	INTEGER   hHeap,;
	STRING  @ lpEntry  
```  
***  


## Parameters:
```txt  
hHeap
[in] Handle to the heap whose memory blocks you wish to enumerate.

lpEntry
[in/out] Pointer to a PROCESS_HEAP_ENTRY structure that maintains state information for a particular heap enumeration.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.5 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

