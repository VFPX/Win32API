<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SHEnumKeyEx
Group: Registry - Library: shlwapi    
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
```txt  
hkey
Handle to the currently open key, or a predefined value.

dwIndex
Index of the subkey to retrieve. This parameter should be zero for the first call and incremented for subsequent calls.

pszName
Address of a character buffer that receives the enumerated key name.

pcchName
Address of a DWORD that, on entry, contains the size of the buffer at pszName. On exit, this contains the number of characters that were copied to pszName.  
```  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code otherwise.  
***  

