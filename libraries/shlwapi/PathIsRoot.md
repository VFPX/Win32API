[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathIsRoot
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Parses a path to determine if it is a directory root.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathIsRoot(
    LPCTSTR pPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathIsRoot IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
pPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be validated.  
***  


## Return value:
Returns TRUE if the specified path is a root, or FALSE otherwise.  
***  

