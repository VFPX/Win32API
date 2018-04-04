[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHRegEnumUSKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Enumerates the subkeys of a user-specific key.
***  


## Code examples:
[Enumerating the subkeys of a user-specific key](../../samples/sample_129.md)  

## Declaration:
```foxpro  
DWORD SHRegEnumUSKey(
    HUSKEY hUSKey,
    DWORD dwIndex,
    LPSTR pszName,
    LPDWORD pcchName,
    SHREGENUM_FLAGS enumRegFlags
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHRegEnumUSKey IN shlwapi;
   	INTEGER   hUSKey,;
   	INTEGER   dwIndex,;
   	STRING  @ pszName,;
   	INTEGER @ pcchName,;
   	INTEGER   enumRegFlags  
```  
***  


## Parameters:
hUSKey 
Handle to the currently open user-specific key. 

dwIndex 
Index of the subkey to retrieve. This parameter should be zero for the first call and incremented for subsequent calls. 

pszName 
Address of a character buffer that receives the enumerated key name. 

pcchName 
Address of a DWORD that, on entry, contains the size of the buffer at pszName. On exit, this contains the number of characters that were copied to pszName. 

enumRegFlags 
One of the SHREGENUM_FLAGS that specifies the base key in which the enumeration should take place.  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code defined in Winerror.h otherwise.  
***  

