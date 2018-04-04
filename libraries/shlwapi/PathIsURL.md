[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathIsURL
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Tests a given string to determine if it conforms to a valid URL format.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathIsURL(
    LPCTSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathIsURL IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
pszPath 
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the URL path to validate.  
***  


## Return value:
Returns TRUE if pszPath has a valid URL format, or FALSE otherwise.  
***  

