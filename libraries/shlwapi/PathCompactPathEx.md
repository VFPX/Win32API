<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PathCompactPathEx
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Truncates a path to fit within a certain number of characters by replacing path components with ellipses.
***  


## Declaration:
```foxpro  
BOOL PathCompactPathEx(
	LPTSTR pszOut,
	LPCTSTR pszSrc,
	UINT cchMax,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathCompactPathEx IN shlwapi;
	STRING @pszOut,;
	STRING pszSrc,;
	LONG cchMax,;
	LONG dwFlags
  
```  
***  


## Parameters:
```txt  
pszOut
[out] The address of the string that has been altered.

pszSrc
[in] A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be altered.

cchMax
[in] The maximum number of characters to be contained in the new string, including the terminating NULL character.

dwFlags
Reserved.
  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.
  
***  


## Comments:
To me the ellipses look rather like dots.  
  
***  

