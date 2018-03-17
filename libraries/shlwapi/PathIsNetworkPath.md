<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathIsNetworkPath
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path.  
```  
***  


## Return value:
Returns TRUE if the string represents a network resource, or FALSE otherwise.  
***  

