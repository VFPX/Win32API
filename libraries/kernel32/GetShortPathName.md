[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetShortPathName
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the short path form of a specified input path
***  


## Code examples:
[Converting long file names to the short format and vice versa](../../samples/sample_055.md)  
[Converting path to original case](../../samples/sample_102.md)  

## Declaration:
```foxpro  
DWORD GetShortPathName(
  LPCTSTR lpszLongPath,  // null-terminated path string
  LPTSTR lpszShortPath,  // short form buffer
  DWORD cchBuffer        // size of short form buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetShortPathName IN kernel32;
	STRING    lpszLongPath,;
	STRING  @ lpszShortPath,;
	INTEGER   cchBuffer  
```  
***  


## Parameters:
lpszLongPath 
[in] Pointer to a null-terminated path string

lpszShortPath 
[out] Pointer to a buffer to receive the null-terminated short form of the path specified by lpszLongPath

cchBuffer 
[in] Specifies the size, in TCHARs, of the buffer pointed to by lpszShortPath  
***  


## Return value:
If the function succeeds, the return value is the length of the string copied to lpszShortPath  
***  


## Comments:
The short path means the 8.3 compliant path/filename.  
  
See also: [PathGetShortPath](../shell32/PathGetShortPath.md), [GetLongPathName](../kernel32/GetLongPathName.md), [GetFullPathName](../kernel32/GetFullPathName.md).  
  
***  

