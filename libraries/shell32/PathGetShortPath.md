[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathGetShortPath
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
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
pszLongPath
[in, out] A NULL-terminated Unicode string that contains the long path. When the function returns it contains the equivalent short path.  
***  


## Return value:
No return value.  
***  


## Comments:
Minimum OS: Windows 2000  
  
Note that same parameter is used for both input and output. The short name most of the times takes less space than the buffer allocates, so the trailing part has to be cut off.  
  
See also: [GetLongPathName](../kernel32/GetLongPathName.md), [GetShortPathName](../kernel32/GetShortPathName.md).  
  
***  

