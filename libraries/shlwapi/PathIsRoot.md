<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathIsRoot
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be validated.  
```  
***  


## Return value:
Returns TRUE if the specified path is a root, or FALSE otherwise.  
***  

