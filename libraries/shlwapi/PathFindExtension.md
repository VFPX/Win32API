[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathFindExtension
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Searches a path for an extension.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
LPTSTR PathFindExtension(
    LPCTSTR pPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE STRING PathFindExtension IN shlwapi;
	STRING pPath  
```  
***  


## Parameters:
pPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path that contains the extension for which to search.   
***  


## Return value:
Returns the address of the "." preceding the extension within pPath if an extension is found, or the address of the trailing NULL character otherwise.  
***  

