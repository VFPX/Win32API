[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathIsRelative
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Searches a path and determines if it is relative.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathIsRelative(
    LPCTSTR lpszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathIsRelative IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
lpszPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.  
***  


## Return value:
Returns TRUE if the path is relative, or FALSE if it is absolute.  
***  

