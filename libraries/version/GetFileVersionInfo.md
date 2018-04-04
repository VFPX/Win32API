[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileVersionInfo
Group: [Version Information](../../functions_group.md#Version_Information)  -  Library: [version](../../Libraries.md#version)  
***  


#### Retrieves version information for the specified file.
***  


## Code examples:
[How to retrieve version information for the specified file](../../samples/sample_480.md)  

## Declaration:
```foxpro  
BOOL GetFileVersionInfo(
	LPTSTR lptstrFilename,
	DWORD dwHandle,
	DWORD dwLen,
	LPVOID lpData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileVersionInfo IN version.dll;
	STRING   lptstrFilename,;
	INTEGER  dwHandle,;
	INTEGER  dwLen,;
	STRING @ lpData
  
```  
***  


## Parameters:
lptstrFilename
[in] Pointer to a null-terminated string that specifies the name of the file of interest.

dwHandle
This parameter is ignored. 

dwLen
[in] Specifies the size, in bytes, of the buffer pointed to by the lpData parameter. 

lpData
[out] Pointer to a buffer that receives the file-version information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Call the GetFileVersionInfoSize function first to determine the size, in bytes, of a file"s version information. The <Em>dwLen</Em> member should be equal to or greater than that value.   
  
***  

