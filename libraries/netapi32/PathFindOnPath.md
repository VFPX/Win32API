[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathFindOnPath
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Searches for a file.
***  


## Code examples:
[How to assemble an array of strings and pass it to external function](../../samples/sample_487.md)  

## Declaration:
```foxpro  
BOOL PathFindOnPath(
	LPTSTR pszFile,
	LPCTSTR *ppszOtherDirs
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathFindOnPath IN shlwapi;
	STRING @ pszFile,;
	STRING @ ppszOtherDirs
  
```  
***  


## Parameters:
pszFile
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the file name for which to search. If the search is successful, this parameter is used to return the fully qualified path name. 

ppszOtherDirs
[in] Optional null-terminated array of directories to be searched first.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

