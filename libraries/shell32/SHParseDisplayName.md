[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHParseDisplayName
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Translates a Shell namespace object"s display name into an item identifier list and returns the attributes of the object. This function is the preferred method to convert a string to a pointer to an item identifier list (PIDL).
***  


## Code examples:
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  

## Declaration:
```foxpro  
HRESULT SHParseDisplayName(
	LPCWSTR pszName,
	IBindCtx *pbc,
	LPITEMIDLIST *ppidl,
	SFGAOF sfgaoIn,
	SFGAOF *psfgaoOut
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHParseDisplayName IN shell32;
	STRING    pszName,;
	INTEGER   pbc,;
	STRING  @ ppidl,;
	INTEGER   sfgaoIn,;
	INTEGER @ psfgaoOut
  
```  
***  


## Parameters:
pszName
[in] Pointer to a zero-terminated wide string that contains the display name to parse.

pbc
[in] A bind context that controls the parsing operation. This parameter is normally set to NULL.

ppidl
[out] Address of a pointer to a variable of type ITEMIDLIST that receives the item identifier list for the object.

sfgaoIn
[in] A ULONG value that specifies the attributes to query. 

psfgaoOut
[out] Pointer to a ULONG. On return, those attributes that are true for the object and were requested in sfgaoIn are set.  
***  


## Return value:
Returns S_OK (0) if successful, or an error value otherwise.  
***  


## Comments:
The calling application is responsible for freeing the returned PIDL.  
  
ITEMIDLIST structure contains a list of item identifiers.   
```cpp
typedef struct _ITEMIDLIST {  
	SHITEMID mkid;  
}
```
A pointer to this structure, called a PIDL, is used to identify objects in the Shell namespace.  
  
See also: [SHSimpleIDListFromPath](../shell32/SHSimpleIDListFromPath.md), [SHGetPathFromIDList](../shell32/SHGetPathFromIDList.md).  
  
***  

