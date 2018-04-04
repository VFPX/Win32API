[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalReAlloc
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Changes the size or attributes of a specified global memory object. The size can increase or decrease.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  

## Declaration:
```foxpro  
HGLOBAL GlobalReAlloc(
	HGLOBAL hMem,
	SIZE_T dwBytes,
	UINT uFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalReAlloc IN kernel32;
	INTEGER hMem,;
	LONG dwBytes,;
	LONG uFlags
  
```  
***  


## Parameters:
hMem 
[in] A handle to the global memory object to be reallocated. This handle is returned by either the GlobalAlloc or GlobalReAlloc function. 

dwBytes 
[in] The new size of the memory block, in bytes. If uFlags specifies GMEM_MODIFY, this parameter is ignored. 

uFlags 
[in] The reallocation options.  
***  


## Return value:
If the function succeeds, the return value is a handle to the reallocated memory object, otherwise it is NULL.  
***  


## Comments:
If GlobalReAlloc reallocates a movable object, the return value is a handle to the memory object. To convert the handle to a pointer, use the GlobalLock function.  
  
If GlobalReAlloc reallocates a fixed object, the value of the handle returned is the address of the first byte of the memory block. To access the memory, a process can simply cast the return value to a pointer.  
  
***  

