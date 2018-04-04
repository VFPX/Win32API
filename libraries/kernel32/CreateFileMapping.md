[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateFileMapping
Group: [File Mapping](../../functions_group.md#File_Mapping)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CreateFileMapping function creates or opens a named or unnamed file mapping object for the specified file.
***  


## Code examples:
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  

## Declaration:
```foxpro  
HANDLE CreateFileMapping(
  HANDLE hFile,
  LPSECURITY_ATTRIBUTES lpAttributes,
  DWORD flProtect,
  DWORD dwMaximumSizeHigh,
  DWORD dwMaximumSizeLow,
  LPCTSTR lpName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateFileMapping IN kernel32;
	INTEGER hFile,;
	INTEGER lpAttributes,;
	INTEGER flProtect,;
	LONG    dwMaximumSizeHi,;
	LONG    dwMaximumSizeLo,;
	STRING  lpName
  
```  
***  


## Parameters:
hFile 
[in] Handle to the file from which to create a mapping object; can be INVALID_HANDLE_VALUE.

lpAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure; can be NULL.

flProtect 
[in] Protection desired for the file view, when the file is mapped.

dwMaximumSizeHigh 
[in] High-order DWORD of the maximum size of the file mapping object. 

dwMaximumSizeLow 
[in] Low-order DWORD of the maximum size of the file mapping object.

lpName 
[in] Pointer to a null-terminated string specifying the name of the mapping object; can be NULL.  
***  


## Return value:
If the function succeeds, the return value is a handle to the file mapping object.  
***  


## Comments:
If <Em>dwMaximumSizeHigh</Em> and <Em>dwMaximumSizeHigh</Em> are zero, the maximum size of the file mapping object is equal to the current size of the file identified by hFile.   
  
If <Em>lpName</Em> is NULL, the mapping object is created without a name.  
  
***  

