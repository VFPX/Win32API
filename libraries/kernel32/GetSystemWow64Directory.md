[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemWow64Directory
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.
***  


## Declaration:
```foxpro  
UINT WINAPI GetSystemWow64Directory(
  __out  LPTSTR lpBuffer,
  __in   UINT uSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemWow64Directory IN kernel32;
	STRING @lpBuffer,;
	LONG uSize  
```  
***  


## Parameters:
lpBuffer [out] 
A pointer to the buffer to receive the path. This path does not end with a backslash.

uSize [in] 
The maximum size of the buffer, in TCHARs.  
***  


## Return value:
If the function succeeds, the return value is the length, in TCHARs, of the string copied to the buffer, not including the terminating null character.  
***  


## Comments:
Example: C:\Windows\SysWOW64  
  
WoW64 means <Em><a href="http://en.wikipedia.org/wiki/WOW64">Windows-on-Windows 64-bit</a></Em>.  
  
See also: [GetSystemDirectory](../kernel32/GetSystemDirectory.md).  
  
***  

