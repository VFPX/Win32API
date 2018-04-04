[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCreateFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function creates, opens, or truncates a file, pipe, communications resource, disk device, or console. It returns a handle that can be used to access the object. It can also open and return a handle to a directory.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
HANDLE CeCreateFile(
	LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCreateFile IN rapi;
	STRING @ lpFileName,;
	INTEGER  dwDesiredAccess,;
	INTEGER  dwShareMode,;
	INTEGER  lpSecurityAttr,;
	INTEGER  dwCreationDisposition,;
	INTEGER  dwFlagsAndAttributes,;
	INTEGER  hTemplateFile
  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that specifies the name of the object, such as file, COM port, disk device, or console, to create or open. 

dwDesiredAccess 
[in] Specifies the type of access to the object.

dwShareMode 
[in] Specifies how the object can be shared. 

lpSecurityAttributes 
[in] Ignored; set to NULL. 

dwCreationDisposition 
[in] Specifies which action to take on files that exist, and which action to take when files do not exist.

dwFlagsAndAttributes 
[in] Specifies the file attributes and flags for the file.

hTemplateFile 
This parameter is ignored.  
***  


## Return value:
An open handle to the specified file indicates success. INVALID_HANDLE_VALUE indicates failure.  
***  

