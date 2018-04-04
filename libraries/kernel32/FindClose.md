[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindClose
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FindClose function closes the specified search handle. The FindFirstFile and FindNextFile functions use the search handle to locate files with names that match a given name.
***  


## Code examples:
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  

## Declaration:
```foxpro  
BOOL FindClose(
  HANDLE hFindFile   // file search handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindClose IN kernel32;
	INTEGER hFindFile  
```  
***  


## Parameters:
hFindFile 
[in/out] File search handle. This handle must have been previously opened by the FindFirstFile function.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

