[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RemoveDirectory
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The RemoveDirectory function deletes an existing empty directory. To recursively delete files and subdirectories in a directory, use the SHFileOperation function.
***  


## Declaration:
```foxpro  
BOOL RemoveDirectory(
  LPCTSTR lpPathName   // directory name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RemoveDirectory IN kernel32;
	STRING lpPathName  
```  
***  


## Parameters:
lpPathName 
[in] Pointer to a null-terminated string that specifies the path of the directory to be removed. The path must specify an empty directory, and the calling process must have delete access to the directory  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
To recursively delete the files in a directory, use the SHFileOperation function.  
  
See also: [RemoveDirectoryTransacted](../kernel32/RemoveDirectoryTransacted.md).  
  
***  

