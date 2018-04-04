[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetModuleFileName
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the full path and file name for the file containing the specified module.
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  
[Finding the path to the VFP executable running](../../samples/sample_086.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Using GetBinaryType (WinNT only) to determine the type of an executable file](../../samples/sample_115.md)  
[Retrieving information about the specified icon](../../samples/sample_206.md)  
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Retrieving file information for the VFP executable running](../../samples/sample_242.md)  
[How to display the Properties dialog box for a file (ShellExecuteEx)](../../samples/sample_320.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[GDI+: custom Clock Control](../../samples/sample_597.md)  

## Declaration:
```foxpro  
DWORD GetModuleFileName(
  HMODULE hModule,    // handle to module
  LPTSTR lpFilename,  // file name of module
  DWORD nSize         // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetModuleFileName IN kernel32;
	INTEGER  hModule,;
	STRING @ lpFilename,;
	INTEGER  nSize  
```  
***  


## Parameters:
hModule 
[in] Handle to the module whose file name is being requested. If this parameter is NULL, GetModuleFileName returns the path for the file containing the current process. 

lpFilename 
[out] Pointer to a buffer that receives the path and file name of the specified module. 

nSize 
[in] Specifies the length, in TCHARs, of the lpFilename buffer. If the length of the path and file name exceeds this limit, the string is truncated.  
***  


## Return value:
If the function succeeds, the return value is the length, in TCHARs, of the string copied to the buffer.  
***  

