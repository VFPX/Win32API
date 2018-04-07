[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFullPathName
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the full path and file name of a specified file.

***  


## Declaration:
```foxpro  
DWORD GetFullPathName(
  LPCTSTR lpFileName,  // file name
  DWORD nBufferLength, // size of path buffer
  LPTSTR lpBuffer,     // path buffer
  LPTSTR *lpFilePart   // address of file name in path
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFullPathName IN kernel32;
	STRING    lpFileName,;
	INTEGER   nBufferLength,;
	STRING  @ lpBuffer,;
	INTEGER @ lpFilePart  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that specifies a valid file name. This string can use either short (the 8.3 form) or long file names. 

nBufferLength 
[in] Specifies the size, in TCHARs, of the buffer for the drive and path. 

lpBuffer 
[out] Pointer to a buffer that receives the null-terminated string for the name of the drive and path. 

lpFilePart 
[out] Pointer to a buffer that receives the address (in lpBuffer) of the final file name component in the path. 
  
***  


## Return value:
If the function succeeds, the return value is the length, in TCHARs, of the string copied to lpBuffer, not including the terminating null character.  
***  


## Comments:
See also: [GetLongPathName](../kernel32/GetLongPathName.md), [GetShortPathName](../kernel32/GetShortPathName.md), [GetModuleFileName](../kernel32/GetModuleFileName.md), [GetTempFileName](../kernel32/GetTempFileName.md), [PathFindFileName](../shlwapi/PathFindFileName.md), [FindExecutable](../shell32/FindExecutable.md).  
  
***  

