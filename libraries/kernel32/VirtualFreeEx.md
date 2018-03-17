<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : VirtualFreeEx
Group: Memory Management - Library: kernel32    
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
```txt  
hProcess [in]
A handle to a process. The function frees memory within the virtual address space of the process.

lpAddress [in]
A pointer to the starting address of the region of memory to be freed.

dwSize [in]
The size of the region of memory to free, in bytes.

dwFreeType [in]
The type of free operation -- a predefined value.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
The entire range of pages originally reserved by VirtualAllocEx must be released at the same time.  
  
***  

