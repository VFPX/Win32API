<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SHRegCloseUSKey
Group: Registry - Library: shlwapi    
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
```txt  
hUSKey
Handle to a user-specific key that is currently open.  
```  
***  


## Return value:
Returns 0 (ERROR_SUCCESS) if successful, or a nonzero error code defined in Winerror.h otherwise.  
***  

