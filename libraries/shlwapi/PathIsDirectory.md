<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathIsDirectory
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Verifies that a path is a valid directory.
***  


## Code examples:
[Converting path to original case](../../samples/sample_102.md)  
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathIsDirectory(
    LPCTSTR pszPath
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathIsDirectory IN shlwapi;
	STRING pszPath  
```  
***  


## Parameters:
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to verify.  
```  
***  


## Return value:
Returns TRUE if the path is a valid directory, or FALSE otherwise.  
***  

