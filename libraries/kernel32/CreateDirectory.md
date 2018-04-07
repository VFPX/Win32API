[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateDirectory
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates a new directory. If the underlying file system supports security on files and directories, the function applies a specified security descriptor to the new directory.

***  


## Code examples:
[Creating a folder](../../samples/sample_001.md)  

## Declaration:
```foxpro  
BOOL CreateDirectory(
  LPCTSTR lpPathName,                         // directory name
  LPSECURITY_ATTRIBUTES lpSecurityAttributes  // SD
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateDirectory IN kernel32;
	STRING  lpPathName,;
	INTEGER lpSecurityAttributes
  
```  
***  


## Parameters:
lpPathName 
[in] Pointer to a null-terminated string that specifies the path of the directory to be created

lpSecurityAttributes
Windows NT/2000: [in] Pointer to a SECURITY_ATTRIBUTES structure. The lpSecurityDescriptor member of the structure specifies a security descriptor for the new directory. If lpSecurityAttributes is NULL, the directory gets a default security descriptor. The target file system must support security on files and directories for this parameter to have an effect.  
***  


## Return value:
If the function succeeds, the return value is nonzero
  
***  


## Comments:
If one or more intermediate directories do not exist, no directory is created (error code 3). To create all intermediate directories on the path, use the SHCreateDirectory function.  
  
See also: [SHCreateDirectory](../shell32/SHCreateDirectory.md).  
  
***  

