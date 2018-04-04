[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathIsNetworkPath
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Determines whether a path string represents a network resource.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathIsNetworkPath(
  LPCTSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathIsNetworkPath IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
pszPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path.   
***  


## Return value:
Returns TRUE if the string represents a network resource, or FALSE otherwise.  
***  

