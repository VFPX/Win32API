<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathFindFileName
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.  
```  
***  


## Return value:
Returns a pointer to the address in the string if successful, or a pointer to the beginning of the path otherwise.   
***  

