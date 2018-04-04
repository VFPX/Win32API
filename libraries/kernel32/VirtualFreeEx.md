[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : VirtualFreeEx
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Releases, decommits, or releases and decommits a region of memory within the virtual address space of a specified process.
***  


## Code examples:
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
BOOL WINAPI VirtualFreeEx(
  __in  HANDLE hProcess,
  __in  LPVOID lpAddress,
  __in  SIZE_T dwSize,
  __in  DWORD dwFreeType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER VirtualFreeEx IN kernel32;
	INTEGER hProcess,;
	INTEGER lpAddress,;
	LONG dwSize,;
	INTEGER dwFreeType  
```  
***  


## Parameters:
hProcess [in]
A handle to a process. The function frees memory within the virtual address space of the process.

lpAddress [in]
A pointer to the starting address of the region of memory to be freed.

dwSize [in]
The size of the region of memory to free, in bytes.

dwFreeType [in]
The type of free operation -- a predefined value.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The entire range of pages originally reserved by VirtualAllocEx must be released at the same time.  
  
***  

