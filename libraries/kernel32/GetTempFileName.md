[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTempFileName
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetTempFileName function creates a name for a temporary file.

The specified integer can be nonzero, in which case, the function creates the file name but does not create the file. If you specify zero for the integer, the function creates a unique file name and creates the file in the specified directory.
***  


## Code examples:
[Using the GetTempFileName](../../samples/sample_016.md)  

## Declaration:
```foxpro  
UINT GetTempFileName(
  LPCTSTR lpPathName,      // directory name
  LPCTSTR lpPrefixString,  // file name prefix
  UINT uUnique,            // integer
  LPTSTR lpTempFileName    // file name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTempFileName IN kernel32;
	STRING   lpszPath,;
	STRING   lpPrefixString,;
	INTEGER  wUnique,;
	STRING @ lpTempFileName
  
```  
***  


## Parameters:
lpPathName 
[in] Pointer to a null-terminated string that specifies the directory path for the file name

lpPrefixString 
[in] Pointer to a null-terminated prefix string. The function uses the first three characters of this string as the prefix of the file name

uUnique 
[in] Specifies an unsigned integer that the function converts to a hexadecimal string for use in creating the temporary file name

lpTempFileName 
[out] Pointer to the buffer that receives the temporary file name  
***  


## Return value:
If the function succeeds, the return value specifies the unique numeric value used in the temporary file name. If the uUnique parameter is nonzero, the return value specifies that same number  
***  

