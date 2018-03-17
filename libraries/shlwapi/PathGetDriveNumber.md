<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathGetDriveNumber
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Searches a path for a drive letter within the range of "A" to "Z" and returns the corresponding drive number.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
int PathGetDriveNumber(
    LPCTSTR lpsz
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathGetDriveNumber IN shlwapi;
	STRING lpsz  
```  
***  


## Parameters:
```txt  
lpsz
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be searched.  
```  
***  


## Return value:
Returns 0 through 25 (corresponding to "A" through "Z") if the path has a drive letter, or -1 otherwise.  
***  

