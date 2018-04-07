[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : VirtualAllocEx
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Reserves or commits a region of memory within the virtual address space of a specified process.
***  


## Code examples:
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
LPVOID WINAPI VirtualAllocEx(
  __in      HANDLE hProcess,
  __in_opt  LPVOID lpAddress,
  __in      SIZE_T dwSize,
  __in      DWORD flAllocationType,
  __in      DWORD flProtect
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER VirtualAllocEx IN kernel32;
	INTEGER hProcess,;
	INTEGER lpAddress,;
	LONG dwSize,;
	INTEGER flAllocationType,;
	INTEGER flProtect
  
```  
***  


## Parameters:
hProcess [in]
The handle to a process. The function allocates memory within the virtual address space of this process.

lpAddress [in, optional]
The pointer that specifies a desired starting address for the region of pages that you want to allocate.

dwSize [in]
The size of the region of memory to allocate, in bytes.

flAllocationType [in]
The type of memory allocation -- a predefined value.

flProtect [in]
The memory protection for the region of pages to be allocated.  
***  


## Return value:
If the function succeeds, the return value is the base address of the allocated region of pages.  
***  


## Comments:
The function initializes the memory it allocates to zero, unless MEM_RESET is used.  
  
See also: [VirtualFreeEx](../kernel32/VirtualFreeEx.md).  
  
***  

