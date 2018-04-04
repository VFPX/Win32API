[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegDeleteKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegDeleteKey function deletes a subkey, including all of its values.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegDeleteKey(
  HKEY hKey,
  LPCTSTR lpSubKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegDeleteKey IN advapi32;
	INTEGER hKey,;
	STRING  lpSubKey  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key.

lpSubKey 
[in] Pointer to a null-terminated string specifying the name of the key to be deleted.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
The key must have been opened with the DELETE access right.  
  
<Em>hKey</Em> handle is returned by the RegCreateKeyEx or RegOpenKeyEx function, or it can be one of the following predefined keys:  
HKEY_CLASSES_ROOT  
HKEY_CURRENT_CONFIG  
HKEY_CURRENT_USER  
HKEY_LOCAL_MACHINE  
HKEY_USERS  
  
The subkey to be deleted must not have subkeys. To delete a key and all its subkeys, you need to recursively enumerate the subkeys and delete them individually. To recursively delete keys, use the SHDeleteKey function.  
  
***  

