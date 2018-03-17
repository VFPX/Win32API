<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathGetShortPath
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shell32    
***  


#### Retrieves the short path form of a specified input path.

***  


## Declaration:
```foxpro  
void PathGetShortPath(
	LPWSTR pszLongPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE PathGetShortPath IN shell32;
	STRING @pszLongPath  
```  
***  


## Parameters:
```txt  
pszLongPath
[in, out] A NULL-terminated Unicode string that contains the long path. When the function returns it contains the equivalent short path.  
```  
***  


## Return value:
No return value.  
***  


## Comments:
Minimum OS: Windows 2000  
  
Note that same parameter is used for both input and output. The short name most of the times takes less space than the buffer allocates, so the trailing part has to be cut off.  
  
See also: GetLongPathName, GetShortPathName.  
  
***  

