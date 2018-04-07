[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHGetFolderPath
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Takes the CSIDL of a folder and returns the pathname.
***  


## Code examples:
[How to get the path to a Special Folder](../../samples/sample_415.md)  

## Declaration:
```foxpro  
HRESULT SHGetFolderPath(
	HWND hwndOwner,
	int nFolder,
	HANDLE hToken,
	DWORD dwFlags,
	LPTSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SHGetFolderPath IN shell32;
	INTEGER hwndOwner,;
	INTEGER nFolder,;
	INTEGER hToken,;
	INTEGER dwFlags,;
	STRING @pszPath  
```  
***  


## Parameters:
hwndOwner
[in] Handle to an owner window. This parameter is typically set to NULL. 

nFolder
[in] A CSIDL value that identifies the folder whose path is to be retrieved.

hToken
[in] 
An access token that can be used to represent a particular user.

dwFlags
[in] Flags to specify which path is to be returned.

pszPath
[out] Pointer to a null-terminated string of length MAX_PATH which will receive the path.  
***  


## Return value:
Returns standard HRESULT codes, including the following: S_FALSE, E_FAIL, E_INVALIDARG, SUCCESS (0).  
***  


## Comments:
CSIDL values provide a unique system-independent way to identify special folders used frequently by applications, but which may not have the same name or location on any given system. For example, the system folder may be "C:\Windows" on one system and "C:\Winnt" on another.  
  
<a href="http://msdn.microsoft.com/en-us/library/bb762494(v=vs.85).aspx">CSIDL list</a>.  
  
For Windows versions 98, NT4 the SHGetFolderPath is obtained through SHFolder.dll, not through Shell32.dll.   
  
SHFolder.dll continues to be included for backward compatibility, though the function is now implemented in Shell32.dll.  
  
See also: [SHGetSpecialFolderLocation](../shell32/SHGetSpecialFolderLocation.md), [SHGetKnownFolderPath](..//SHGetKnownFolderPath.md), [SHGetPathFromIDList](../shell32/SHGetPathFromIDList.md).  
  
***  

