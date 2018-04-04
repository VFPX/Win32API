[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegDeleteValue
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegDeleteValue function removes a named value from the specified registry key.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegDeleteValue(
  HKEY hKey,
  LPCTSTR lpValueName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegDeleteValue IN advapi32;
	INTEGER hKey,;
	STRING  lpValueName  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key.

lpValueName 
[in] Pointer to a null-terminated string that names the value to remove.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
The key must have been opened with the KEY_SET_VALUE access right.  
  
<Em>hKey</Em> handle is returned by the RegCreateKeyEx or RegOpenKeyEx function, or it can be one of the following predefined keys:  
     HKEY_CLASSES_ROOT  
     HKEY_CURRENT_CONFIG  
     HKEY_CURRENT_USER  
     HKEY_LOCAL_MACHINE  
     HKEY_USERS  
  
If <Em>lpValueName</Em> parameter is NULL or an empty string, the value set by the RegSetValue function is removed.   
  
***  

