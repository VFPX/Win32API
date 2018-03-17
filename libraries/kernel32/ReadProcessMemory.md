<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ReadProcessMemory
Group: Debugging - Library: kernel32    
***  


#### Reads data from an area of memory in a specified process. 
***  


## Code examples:
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
BOOL WINAPI ReadProcessMemory(
  __in   HANDLE hProcess,
  __in   LPCVOID lpBaseAddress,
  __out  LPVOID lpBuffer,
  __in   SIZE_T nSize,
  __out  SIZE_T *lpNumberOfBytesRead
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReadProcessMemory IN kernel32;
	INTEGER hProcess,;
	INTEGER lpBaseAddress,;
	INTEGER lpBuffer,;
	LONG nSize,;
	LONG @ lpNumberOfBytesRead  
```  
***  


## Parameters:
```txt  
hProcess [in]
A handle to the process with memory that is being read. The handle must have PROCESS_VM_READ access to the process.

lpBaseAddress [in]
A pointer to the base address in the specified process from which to read.

lpBuffer [out]
A pointer to a buffer that receives the contents from the address space of the specified process.

nSize [in]
The number of bytes to be read from the specified process.

lpNumberOfBytesRead [out]
A pointer to a variable that receives the number of bytes transferred into the specified buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The entire area to be read must be accessible or the operation fails.  
  
See also: WriteProcessMemory, VirtualAllocEx, OpenProcess    
  
***  

