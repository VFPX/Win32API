[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathSearchAndQualify
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Determines if a given path is correctly formatted and fully qualified.
***  


## Code examples:
[Converting path to original case](../../samples/sample_102.md)  

## Declaration:
```foxpro  
BOOL PathSearchAndQualify(
  __in   LPCTSTR pcszPath,
  __out  LPTSTR pszFullyQualifiedPath,
  __in   UINT cchFullyQualifiedPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathSearchAndQualify IN Shlwapi;
	STRING pcszPath,;
	STRING @pszFullyQualifiedPath,;
	INTEGER cchFullyQualifiedPath  
```  
***  


## Parameters:
pcszPath [in]
A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.

pszFullyQualifiedPath [out]
A pointer to a null-terminated string of length MAX_PATH that contains the path to be referenced.

cchFullyQualifiedPath [in]
The size of the buffer pointed to by pszFullyQualifiedPath, in characters.  
***  


## Return value:
Returns TRUE if the path is qualified, or FALSE otherwise.  
***  

