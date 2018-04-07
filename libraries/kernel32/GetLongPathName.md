[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetLongPathName
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetLongPathName function converts the specified path to its long form. If no long path is found, this function simply returns the specified name. 
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  
[Using the GetTempFileName](../../samples/sample_016.md)  
[Converting long file names to the short format and vice versa](../../samples/sample_055.md)  
[Converting path to original case](../../samples/sample_102.md)  

## Declaration:
```foxpro  
DWORD GetLongPathName(
  LPCTSTR lpszShortPath, // file name
  LPTSTR lpszLongPath,   // path buffer
  DWORD cchBuffer        // size of path buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetLongPathName IN kernel32;
	STRING    lpszShortPath,;
	STRING  @ lpszLongPath,;
	INTEGER   cchBuffer  
```  
***  


## Parameters:
lpszShortPath 
[in] Pointer to a null-terminated path to be converted. 

lpszLongPath 
[out] Pointer to the buffer to receive the long path. You can use the same buffer you used for the lpszShortPath parameter. 

cchBuffer 
[in] Specifies the size of the buffer, in TCHARs.   
***  


## Return value:
If the function succeeds, the return value is the length of the string copied to the lpszLongPath parameter, in TCHARs.   
***  


## Comments:
See also: [GetShortPathName](../kernel32/GetShortPathName.md), [PathGetShortPath](../shell32/PathGetShortPath.md), [GetFullPathName](../kernel32/GetFullPathName.md).  
  
***  

