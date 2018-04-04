[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHRegOpenUSKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Opens a user-specific registry key.
***  


## Code examples:
[Enumerating the subkeys of a user-specific key](../../samples/sample_129.md)  

## Declaration:
```foxpro  
LONG SHRegOpenUSKey(
    LPCTSTR  pszPath,
    REGSAM   samDesired,
    HUSKEY   hRelativeUSKey,
    PHUSKEY  phNewUSKey,
    BOOL     fIgnoreHKCU
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHRegOpenUSKey IN shlwapi;
   	STRING    pszPath,;
   	INTEGER   samDesired,;
   	INTEGER   hRelativeUSKey,;
   	INTEGER @ phNewUSKey,;
   	SHORT     fIgnoreHKCU  
```  
***  


## Parameters:
pszPath 
[in] Pointer to a null-terminated string with the name of the subkey. 

samDesired 
[in] Desired security access. For more information on security access, see REGSAM. 

hRelativeUSKey 
[in] Key to be used as a base for relative paths. 

phNewUSKey 
[out] Pointer to the handle of the opened key. 

fIgnoreHKCU 
[in] Variable that specifies which key to look under. When set to TRUE, SHRegGetUSValue ignores HKCU and returns a value from HKLM.  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code defined in Winerror.h otherwise.  
***  

