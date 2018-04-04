[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetModuleHandle
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves a module handle for the specified module if the file has been mapped into the address space of the calling process.
***  


## Code examples:
[Retrieving a handle to DLL and address of an exported function in it](../../samples/sample_085.md)  
[Finding the path to the VFP executable running](../../samples/sample_086.md)  
[Retrieving information about the main VFP window](../../samples/sample_111.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Retrieving Window Class information for the VFP window](../../samples/sample_201.md)  
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  
[GDI+: Storing DLL icon resources in image files](../../samples/sample_501.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
HMODULE GetModuleHandle(
  LPCTSTR lpModuleName   // module name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetModuleHandle IN kernel32;
	STRING lpModuleName  
```  
***  


## Parameters:
lpModuleName 
[in] Pointer to a null-terminated string that contains the name of the module (either a .dll or .exe file).  
***  


## Comments:
If this parameter is NULL, the GetModuleHandle returns a handle to the file used to create the calling process. This is a direct way to get a handle to the running VFP application.  
  
Equivalent result can be achieved through the GetWindowLong call.  
  
***  

