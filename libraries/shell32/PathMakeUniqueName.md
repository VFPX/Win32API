[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathMakeUniqueName
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Creates a unique path name from a template.
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  

## Declaration:
```foxpro  
BOOL PathMakeUniqueName(
	LPWSTR pszUniqueName,
	UINT cchMax,
	LPCWSTR pszTemplate,
	LPCWSTR pszLongPlate,
	LPCWSTR pszDir
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathMakeUniqueName IN shell32;
	STRING  @ pszUniqueName,;
	INTEGER   cchMax,;
	STRING    pszTemplate,;
	STRING    pszLongPlate,;
	STRING    pszDir
  
```  
***  


## Parameters:
pszUniqueName
[out] A buffer that receives a null-terminated Unicode string that contains the unique path name. 

cchMax
[in] The number of characters in the buffer pointed to by pszUniqueName.

pszTemplate
[in] A null-terminated Unicode string that contains a template that is used to construct the unique name. 

pszLongPlate
[in] A null-terminated Unicode string that contains a template that is used to construct the unique name. 

pszDir
[in] A null-terminated string that contains the directory in which the new file resides.  
***  


## Return value:
Returns TRUE if successful, FALSE otherwise.  
***  


## Comments:
See also PathYetAnotherMakeUniqueName function.  
  
***  

