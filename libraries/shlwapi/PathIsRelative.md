<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathIsRelative
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
lpszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.  
```  
***  


## Return value:
Returns TRUE if the path is relative, or FALSE if it is absolute.  
***  

