[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHCreateDirectory
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Creates a folder.
***  


## Code examples:
[Creating a folder](../../samples/sample_001.md)  

## Declaration:
```foxpro  
int SHCreateDirectory(
	HWND hwnd,
	LPCWSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHCreateDirectory IN shell32;
	INTEGER hwnd,;
	STRING  pszPath
  
```  
***  


## Parameters:
hwnd
[in] Handle to a parent window. This parameter can be set to NULL if no user interface is displayed.

pszPath
[in] Pointer to a NULL-terminated Unicode string that contains the fully-qualified path of the directory.   
***  


## Return value:
Returns ERROR_SUCCESS (0) if successful.  
***  


## Comments:
For setting security attributes on a new folder, use SHCreateDirectoryEx.  
  
This function creates directory even if one or more intermediate directories on the path do not exist.  
  
See also: [CreateDirectory](../kernel32/CreateDirectory.md).  
  
***  

