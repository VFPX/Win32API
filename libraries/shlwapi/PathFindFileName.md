[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathFindFileName
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Searches a path for a file name.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
LPTSTR PathFindFileName(
    LPCTSTR pPath
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE STRING  PathFindFileName IN shlwapi;
	STRING pPath  
```  
***  


## Parameters:
pPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.   
***  


## Return value:
Returns a pointer to the address in the string if successful, or a pointer to the beginning of the path otherwise.   
***  

