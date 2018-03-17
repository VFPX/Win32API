<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetFileTime
Group: Time - Library: kernel32    
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
```txt  
hFile
[in] Handle to the files for which to get dates and times.

lpCreationTime
[out] Pointer to a FILETIME structure to receive the date and time the file was created.

lpLastAccessTime
[out] Pointer to a FILETIME structure to receive the date and time the file was last accessed.

lpLastWriteTime
[out] Pointer to a FILETIME structure to receive the date and time the file was last written to.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

