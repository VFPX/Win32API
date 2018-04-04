[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathYetAnotherMakeUniqueName
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Creates a unique filename based on an existing filename.
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  

## Declaration:
```foxpro  
BOOL PathYetAnotherMakeUniqueName(
	LPWSTR pszUniqueName,
	LPCWSTR pszPath,
	LPCWSTR pszShort,
	LPCWSTR pszFileSpec
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathYetAnotherMakeUniqueName IN shell32;
	STRING @ pszUniqueName,;
	STRING   pszPath,;
	STRING   pszShort,;
	STRING   pszFileSpec  
```  
***  


## Parameters:
pszUniqueName
[out] A string buffer that receives a NULL-terminated Unicode string that contains the fully qualified path of the unique file name.

pszPath
[in] A NULL-terminated Unicode string containing the fully qualified path of folder that will contain the new file.

pszShort
[in] A NULL-terminated Unicode string containing the short file name that the unique name will be based on.

pszFileSpec
[in] A NULL-terminated Unicode string containing the long file name that the unique name will be based on.  
***  


## Return value:
Returns TRUE if a unique name was successfully created, FALSE if not.  
***  


## Comments:
See also PathMakeUniqueName function.  
  
***  

