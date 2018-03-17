<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetFileAttributes
Group: File Management - Library: kernel32    
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
```txt  
lpFileName
[in] Pointer to a null-terminated string that specifies the name of a file or directory.  
```  
***  


## Return value:
If the function succeeds, the return value contains the attributes of the specified file or directory.  
***  


## Comments:
This function can be used for testing an access to a directory -- a key-turn DirectoryExists function.  
  
***  

