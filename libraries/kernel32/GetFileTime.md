[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the date and time that a file was created, last accessed, and last modified.
***  


## Code examples:
[Comparing file times](../../samples/sample_171.md)  
[HOWTO: Use the Win32 API to Access File Dates and Times](../../samples/sample_177.md)  

## Declaration:
```foxpro  
BOOL GetFileTime(
  HANDLE hFile,                 // handle to file
  LPFILETIME lpCreationTime,    // creation time
  LPFILETIME lpLastAccessTime,  // last access time
  LPFILETIME lpLastWriteTime    // last write time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetFileTime IN kernel32;
	INTEGER  hFile,;
	STRING @ lpCreationTime,;
	STRING @ lpLastAccessTime,;
	STRING @ lpLastWriteTime  
```  
***  


## Parameters:
hFile 
[in] Handle to the files for which to get dates and times. 

lpCreationTime 
[out] Pointer to a FILETIME structure to receive the date and time the file was created. 

lpLastAccessTime 
[out] Pointer to a FILETIME structure to receive the date and time the file was last accessed. 

lpLastWriteTime 
[out] Pointer to a FILETIME structure to receive the date and time the file was last written to.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

