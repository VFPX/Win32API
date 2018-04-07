[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMappedFileName
Group: [File Mapping](../../functions_group.md#File_Mapping)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetMappedFileName function checks if the specified address is within a memory-mapped file in the address space of the specified process. If so, the function returns the name of the memory-mapped file.
***  


## Code examples:
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
DWORD GetMappedFileName(
  HANDLE hProcess,
  LPVOID lpv,
  LPTSTR lpFilename,
  DWORD nSize
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMappedFileName IN psapi;
	INTEGER  hProcess,;
	INTEGER  lpv,;
	STRING @ lpFilename,;
	INTEGER  nSize  
```  
***  


## Parameters:
hProcess 
[in] Handle to the process.

lpv 
[in] Address to be verified. 

lpFilename 
[out] Pointer to the buffer that receives the name of the memory-mapped file to which the address specified by lpv belongs. 

nSize 
[in] Size of the lpFilename buffer, in characters.   
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer, in characters.  
***  


## Comments:
See also: [EnumProcesses](../psapi/EnumProcesses.md), [GetCurrentProcess](../kernel32/GetCurrentProcess.md).  
  
***  

