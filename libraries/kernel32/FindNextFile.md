<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindNextFile
Group: File Management - Library: kernel32    
***  


#### The FindNextFile function continues a file search from a previous call to the FindFirstFile function.
***  


## Code examples:
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  

## Declaration:
```foxpro  
BOOL FindNextFile(
  HANDLE hFindFile,                // search handle
  LPWIN32_FIND_DATA lpFindFileData // data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextFile IN kernel32;
	INTEGER   hFindFile,;
	STRING  @ lpFindFileData  
```  
***  


## Parameters:
```txt  
hFindFile
[in] Search handle returned by a previous call to the FindFirstFile function.

lpFindFileData
[out] Pointer to the WIN32_FIND_DATA structure that receives information about the found file or subdirectory.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

