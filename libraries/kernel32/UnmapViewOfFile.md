[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnmapViewOfFile
Group: [File Mapping](../../functions_group.md#File_Mapping)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The UnmapViewOfFile function unmaps a mapped view of a file from the calling process"s address space.
***  


## Code examples:
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  

## Declaration:
```foxpro  
BOOL UnmapViewOfFile(
  LPCVOID lpBaseAddress
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnmapViewOfFile IN kernel32;
	LONG lpBaseAddress  
```  
***  


## Parameters:
lpBaseAddress 
[in] Pointer to the base address of the mapped view of a file that is to be unmapped.  
***  


## Return value:
If the function succeeds, the return value is nonzero, and all dirty pages within the specified range are written "lazily" to disk.  
***  


## Comments:
Although an application may close the file handle used to create a file mapping object, the system holds the corresponding file open until the last view of the file is unmapped.  
  
See also: [MapViewOfFile](../kernel32/MapViewOfFile.md), [MapViewOfFileEx](..//MapViewOfFileEx.md).  
  
***  

