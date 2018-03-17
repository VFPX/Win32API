<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathFileExists
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the full path of the object to verify.  
```  
***  


## Return value:
Returns TRUE if the file exists, or FALSE otherwise. Call GetLastError for extended error information.  
***  

