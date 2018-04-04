[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileVersionInfoSize
Group: [Version Information](../../functions_group.md#Version_Information)  -  Library: [version](../../Libraries.md#version)  
***  


#### The GetFileVersionInfoSize function determines whether the operating system can retrieve version information for a specified file.
***  


## Code examples:
[How to retrieve version information for the specified file](../../samples/sample_480.md)  

## Declaration:
```foxpro  
DWORD GetFileVersionInfoSize(
	LPTSTR lptstrFilename,
	LPDWORD lpdwHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileVersionInfoSize IN version.dll;
	STRING  lptstrFilename,;
	INTEGER lpdwHandle
  
```  
***  


## Parameters:
lptstrFilename
[in] Pointer to a null-terminated string that specifies the name of the file of interest.

lpdwHandle
[out] Pointer to a variable that the function sets to zero.   
***  


## Return value:
If the function succeeds, the return value is the size, in bytes, of the file"s version information.  
***  


## Comments:
If version information is available, GetFileVersionInfoSize returns the size, in bytes, of that information.   
  
***  

