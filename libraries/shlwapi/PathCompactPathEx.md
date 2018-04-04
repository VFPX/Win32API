[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathCompactPathEx
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
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
pszOut
[out] The address of the string that has been altered.

pszSrc
[in] A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be altered.

cchMax
[in] The maximum number of characters to be contained in the new string, including the terminating NULL character.

dwFlags
Reserved.
  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.
  
***  


## Comments:
To me the ellipses look rather like dots.  
  
***  

