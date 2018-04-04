[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileAttributes
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves attributes for a specified file or directory.
***  


## Code examples:
[How to test file attributes (key method for FileExists and DirectoryExists routines)](../../samples/sample_097.md)  
[Changing file attributes](../../samples/sample_103.md)  

## Declaration:
```foxpro  
DWORD GetFileAttributes(
  LPCTSTR lpFileName   // name of file or directory
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileAttributes IN kernel32;
	STRING lpFileName  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that specifies the name of a file or directory.  
***  


## Return value:
If the function succeeds, the return value contains the attributes of the specified file or directory.  
***  


## Comments:
This function can be used for testing an access to a directory -- a key-turn DirectoryExists function.  
  
***  

