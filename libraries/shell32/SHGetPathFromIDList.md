[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHGetPathFromIDList
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Converts an item identifier list to a file system path.

***  


## Code examples:
[Accessing the list of Windows Recent Documents](../../samples/sample_094.md)  
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
BOOL SHGetPathFromIDList(
	LPCITEMIDLIST pidl,
    LPTSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHGetPathFromIDList IN shell32;
	INTEGER   pidl,;
	STRING  @ pszPath  
```  
***  


## Parameters:
pidl
Address of an item identifier list that specifies a file or directory location relative to the root of the namespace (the desktop). 

pszPath
Address of a buffer to receive the file system path. This buffer must be at least MAX_PATH characters in size.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  


## Comments:
See also: [SHSimpleIDListFromPath](../shell32/SHSimpleIDListFromPath.md), [SHParseDisplayName](../shell32/SHParseDisplayName.md).  
  
***  

