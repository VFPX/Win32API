[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHGetSpecialFolderLocation
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves a pointer to the ITEMIDLIST structure of a special folder.
***  


## Code examples:
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
HRESULT SHGetSpecialFolderLocation(
  __in   HWND hwndOwner,
  __in   int nFolder,
  __out  PIDLIST_ABSOLUTE *ppidl
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHGetSpecialFolderLocation IN shell32;
	INTEGER hwndOwner,;
	INTEGER nFolder,;
	INTEGER @ppidl
  
```  
***  


## Parameters:
hwndOwner [in]
Reserved.

nFolder [in]
A CSIDL value that identifies the folder of interest.

ppidl [out]
A PIDL specifying the folder"s location relative to the root of the namespace (the desktop).  
***  


## Return value:
If the method succeeds, it returns S_OK (0). Otherwise, it returns an HRESULT error code.  
***  


## Comments:
 It is the responsibility of the calling application to free the returned IDList by using CoTaskMemFree.  
  
See also: [SHGetFolderPath](../shell32/SHGetFolderPath.md), [SHGetKnownFolderPath](..//SHGetKnownFolderPath.md), [SHGetPathFromIDList](../shell32/SHGetPathFromIDList.md).  
  
***  

