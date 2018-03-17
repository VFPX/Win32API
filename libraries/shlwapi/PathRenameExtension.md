<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathRenameExtension
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Replaces the extension of a file name with a new extension.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
BOOL PathRenameExtension(
    LPTSTR pszPath,
    LPCTSTR pszExt
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathRenameExtension IN shlwapi;
	STRING @ pszPath,;
	STRING   pszExt  
```  
***  


## Parameters:
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH in which to replace the extension.

pszExt
[in] Address of a character buffer that contains a "." followed by the new extension.  
```  
***  


## Return value:
Returns nonzero if successful, or zero if the new path and extension would exceed MAX_PATH characters.  
***  

