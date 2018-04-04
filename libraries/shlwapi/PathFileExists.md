[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathFileExists
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Determines whether a path to a file system object such as a file or directory is valid.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  

## Declaration:
```foxpro  
BOOL PathFileExists(
    LPCTSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathFileExists IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
pszPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the full path of the object to verify.  
***  


## Return value:
Returns TRUE if the file exists, or FALSE otherwise. Call GetLastError for extended error information.  
***  

