[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindFirstFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FindFirstFile function searches a directory for a file whose name matches the specified file name. FindFirstFile examines subdirectory names as well as file names.
***  


## Code examples:
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  

## Declaration:
```foxpro  
HANDLE FindFirstFile(
  LPCTSTR lpFileName,               // file name
  LPWIN32_FIND_DATA lpFindFileData  // data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindFirstFile IN kernel32;
	STRING   lpFileName,;
	STRING @ lpFindFileData  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that specifies a valid directory or path and file name, which can contain wildcard characters (* and ?). 

lpFindFileData 
[out] Pointer to the WIN32_FIND_DATA structure that receives information about the found file or subdirectory.   
***  


## Return value:
If the function succeeds, the return value is a search handle used in a subsequent call to FindNextFile or FindClose.  
***  

