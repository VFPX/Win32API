[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHEnumKeyEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Enumerates the subkeys of the specified open registry key.
***  


## Code examples:
[Enumerating the subkeys for a given registry key](../../samples/sample_130.md)  

## Declaration:
```foxpro  
DWORD SHEnumKeyEx(
    HKEY hkey,
    DWORD dwIndex,
    LPTSTR pszName,
    LPDWORD pcchName
    );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHEnumKeyEx IN shlwapi;
   	INTEGER   hkey,;
   	INTEGER   dwIndex,;
   	STRING  @ pszName,;
   	INTEGER @ pcchName  
```  
***  


## Parameters:
hkey 
Handle to the currently open key, or a predefined value.

dwIndex 
Index of the subkey to retrieve. This parameter should be zero for the first call and incremented for subsequent calls. 

pszName 
Address of a character buffer that receives the enumerated key name. 

pcchName 
Address of a DWORD that, on entry, contains the size of the buffer at pszName. On exit, this contains the number of characters that were copied to pszName.  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code otherwise.  
***  

