[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHRegCloseUSKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Closes a handle to a user-specific registry key.
***  


## Code examples:
[Enumerating the subkeys of a user-specific key](../../samples/sample_129.md)  

## Declaration:
```foxpro  
DWORD SHRegCloseUSKey(
    HUSKEY hUSKey,
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHRegCloseUSKey IN shlwapi;
	INTEGER hUSKey  
```  
***  


## Parameters:
hUSKey 
Handle to a user-specific key that is currently open.  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code defined in Winerror.h otherwise.  
***  

