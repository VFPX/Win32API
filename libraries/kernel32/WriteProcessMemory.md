[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WriteProcessMemory
Group: [Debugging](../../functions_group.md#Debugging)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Writes data to an area of memory in a specified process. 
***  


## Code examples:
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
BOOL WINAPI WriteProcessMemory(
  __in   HANDLE hProcess,
  __in   LPVOID lpBaseAddress,
  __in   LPCVOID lpBuffer,
  __in   SIZE_T nSize,
  __out  SIZE_T *lpNumberOfBytesWritten
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WriteProcessMemory IN kernel32;
	INTEGER hProcess,;
	INTEGER lpBaseAddress,;
	INTEGER lpBuffer,;
	LONG nSize,;
	LONG @ lpNumberOfBytesWritten
  
```  
***  


## Parameters:
hProcess [in]
A handle to the process memory to be modified. The handle must have PROCESS_VM_WRITE and PROCESS_VM_OPERATION access to the process.

lpBaseAddress [in]
A pointer to the base address in the specified process to which data is written.

lpBuffer [in]
A pointer to the buffer that contains data to be written in the address space of the specified process.

nSize [in]
The number of bytes to be written to the specified process.

lpNumberOfBytesWritten [out]
A pointer to a variable that receives the number of bytes transferred into the specified process.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The entire area to be written to must be accessible or the operation fails.  
  
See also: [ReadProcessMemory](../kernel32/ReadProcessMemory.md), [VirtualAllocEx](../kernel32/VirtualAllocEx.md).  
  
***  

