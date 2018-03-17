<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnmapViewOfFile
Group: File Mapping - Library: kernel32    
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
```txt  
lpBaseAddress
[in] Pointer to the base address of the mapped view of a file that is to be unmapped.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero, and all dirty pages within the specified range are written "lazily" to disk.  
***  


## Comments:
Although an application may close the file handle used to create a file mapping object, the system holds the corresponding file open until the last view of the file is unmapped.  
  
See also: MapViewOfFile, MapViewOfFileEx.  
  
***  

