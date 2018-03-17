<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SHCreateDirectory
Group: Shell Functions - Library: shell32    
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
```txt  
hwnd
[in] Handle to a parent window. This parameter can be set to NULL if no user interface is displayed.

pszPath
[in] Pointer to a NULL-terminated Unicode string that contains the fully-qualified path of the directory.  
```  
***  


## Return value:
Returns ERROR_SUCCESS (0) if successful.  
***  


## Comments:
For setting security attributes on a new folder, use SHCreateDirectoryEx.  
  
This function creates directory even if one or more intermediate directories on the path do not exist.  
  
See also: CreateDirectory   
  
***  

