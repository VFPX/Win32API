<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathIsURL
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
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
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the URL path to validate.  
```  
***  


## Return value:
Returns TRUE if pszPath has a valid URL format, or FALSE otherwise.  
***  

