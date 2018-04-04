[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadLibraryEx
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Maps the specified executable module into the address space of the calling process. The executable module can be a .dll or an .exe file. The specified module may cause other modules to be mapped into the address space.

***  


## Code examples:
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
HMODULE LoadLibraryEx(
	LPCTSTR lpFileName,
	HANDLE hFile,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadLibraryEx IN kernel32;
	STRING  lpFileName,;
	INTEGER hFile,;
	INTEGER dwFlags
  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a null-terminated string that names the executable module (either a .dll or an .exe file). 

hFile 
This parameter is reserved for future use. It must be NULL.

dwFlags 
[in] Action to take when loading the module. If no flags are specified, the behavior of this function is identical to that of the LoadLibrary function.  
***  


## Return value:
If the function succeeds, the return value is a handle to the mapped executable module.  
***  

