[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileAttributesEx
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves attributes for a specified file or directory.
***  


## Code examples:
[A procedure for setting file times](../../samples/sample_128.md)  

## Declaration:
```foxpro  
BOOL GetFileAttributesEx(
  LPCTSTR lpFileName,                   // file or directory name
  GET_FILEEX_INFO_LEVELS fInfoLevelId,  // attribute
  LPVOID lpFileInformation              // attribute information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileAttributesEx IN kernel32;
	STRING    lpFileName,;
	INTEGER   fInfoLevelId,;
	STRING  @ lpFileInformation  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that specifies a file or directory. 

fInfoLevelId 
[in] Specifies a GET_FILEEX_INFO_LEVELS enumeration type that gives the set of attribute information to obtain. 

lpFileInformation 
[out] Pointer to a buffer that receives the attribute information. The type of attribute information stored into this buffer is determined by the value of fInfoLevelId.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero. 
  
***  


## Comments:
Same as the GetFileAttributes this function is a good basis for DirectoryExists and FileExists algorithms.  
  
***  

