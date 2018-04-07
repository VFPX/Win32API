[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHSimpleIDListFromPath
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Returns a pointer to an ITEMIDLIST structure when passed a path.
***  


## Code examples:
[Accessing the list of Windows Recent Documents](../../samples/sample_094.md)  

## Declaration:
```foxpro  
PIDLIST_ABSOLUTE SHSimpleIDListFromPath(
  __in  PCWSTR pszPath
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHSimpleIDListFromPath IN shell32;
	STRING pszPath  
```  
***  


## Parameters:
pszPath [in]
A pointer to a null-terminated string that contains the path to be converted to a PIDL.  
***  


## Return value:
Returns a pointer to an ITEMIDLIST structure if successful, or NULL otherwise.  
***  


## Comments:
See also: [SHGetPathFromIDList](../shell32/SHGetPathFromIDList.md), [SHParseDisplayName](../shell32/SHParseDisplayName.md).  
  
***  

