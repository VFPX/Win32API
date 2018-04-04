[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindNextFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hFindFile 
[in] Search handle returned by a previous call to the FindFirstFile function. 

lpFindFileData 
[out] Pointer to the WIN32_FIND_DATA structure that receives information about the found file or subdirectory.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

