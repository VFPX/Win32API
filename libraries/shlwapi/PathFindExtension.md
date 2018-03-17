<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathFindExtension
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path that contains the extension for which to search.  
```  
***  


## Return value:
Returns the address of the "." preceding the extension within pPath if an extension is found, or the address of the trailing NULL character otherwise.  
***  

