[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathCombine
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Concatenates two strings that represent properly formed paths into one path; also concatenates any relative path elements.
***  


## Code examples:
[How to display Windows On-Screen Keyboard](../../samples/sample_582.md)  

## Declaration:
```foxpro  
LPTSTR PathCombine(
  __out     LPTSTR lpszDest,
  __in_opt  LPCTSTR lpszDir,
  __in      LPCTSTR lpszFile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathCombine IN shlwapi;
	STRING @lpszDest,;
	STRING lpszDir,;
	STRING lpszFile  
```  
***  


## Parameters:
lpszDest [out]
Type: LPTSTR
A pointer to a buffer with the null-terminated string to hold the combined path string.

lpszDir [in, optional]
Type: LPCTSTR
A pointer to a null-terminated string of maximum length MAX_PATH that contains the directory path. This value can be NULL.

lpszFile [in]
Type: LPCTSTR
A pointer to a null-terminated string of maximum length MAX_PATH that contains the file path. This value can be NULL.  
***  


## Return value:
Returns a pointer to a string with the concatenated path if successful, or NULL otherwise.  
***  


## Comments:
The directory path should be in the form of A:,B:, ..., Z:.   
  
The file path should be in a correct form that represents the file part of the path. The file path must not be null, and if it ends with a backslash, the backslash will be maintained.  
  
***  

