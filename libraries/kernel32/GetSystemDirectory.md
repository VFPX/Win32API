[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemDirectory
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetSystemDirectory function retrieves the path of the system directory. The system directory contains such files as dynamic-link libraries, drivers, and font files.

***  


## Code examples:
[Obtaining the System and Windows folder names](../../samples/sample_005.md)  
[Using LoadLibrary](../../samples/sample_007.md)  
[Retrieving a handle to DLL and address of an exported function in it](../../samples/sample_085.md)  
[Using Shell for performing operations on files](../../samples/sample_093.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  
[How to display Windows On-Screen Keyboard](../../samples/sample_582.md)  

## Declaration:
```foxpro  
UINT GetSystemDirectory(
  LPTSTR lpBuffer,  // buffer for system directory
  UINT uSize        // size of directory buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemDirectory IN kernel32;
As GetSystemDirectoryA;
	STRING @ lpBuffer,;
	INTEGER  nSize  
```  
***  


## Parameters:
lpBuffer 
[out] Pointer to the buffer to receive the null-terminated string containing the path

uSize 
[in] Specifies the maximum size of the buffer  
***  


## Return value:
If the function succeeds, the return value specifies the number of characters written to the buffer, not including the terminating null character  
***  


## Comments:
See also: [GetWindowsDirectory](../kernel32/GetWindowsDirectory.md), [SHGetFolderPath](../shell32/SHGetFolderPath.md), [GetSystemWow64Directory](../kernel32/GetSystemWow64Directory.md).  
  
***  

