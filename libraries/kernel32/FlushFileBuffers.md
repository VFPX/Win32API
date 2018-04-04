[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FlushFileBuffers
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Flushes the buffers of a specified file and causes all buffered data to be written to a file.
***  


## Code examples:
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL FlushFileBuffers(
	HANDLE hFile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FlushFileBuffers IN kernel32;
	INTEGER hFile
  
```  
***  


## Parameters:
hFile 
[in] A handle to an open file.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Parameter <Em>hFile</Em> is different from the handle returned by VFP low-level file functions FOPEN() and FCREATE().  
  
Typically the WriteFile and WriteFileEx functions write data to an internal buffer that the OS writes to a disk on a regular basis. The FlushFileBuffers function writes to a disk all the buffered information for a specified file.  
  
***  

