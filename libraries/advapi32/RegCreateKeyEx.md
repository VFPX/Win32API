[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegCreateKeyEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegCreateKeyEx function creates the specified registry key. If the key already exists, the function opens it.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegCreateKeyEx(
  HKEY hKey,
  LPCTSTR lpSubKey,
  DWORD Reserved,
  LPTSTR lpClass,
  DWORD dwOptions,
  REGSAM samDesired,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  PHKEY phkResult,
  LPDWORD lpdwDisposition
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegCreateKeyEx IN advapi32;
	INTEGER   hKey,;
	STRING    lpSubKey,;
	INTEGER   Reserved,;
	STRING    lpClass,;
	INTEGER   dwOptions,;
	INTEGER   samDesired,;
	INTEGER   lpSecurityAttributes,;
	INTEGER @ phkResult,;
	INTEGER @ lpdwDisposition  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key.

lpSubKey 
[in] Pointer to a null-terminated string specifying the name of a subkey that this function opens or creates.

Reserved 
Reserved; must be zero. 

lpClass 
[in] Pointer to a null-terminated string that specifies the class (object type) of this key.

dwOptions 
[in] This parameter can be one of predefined values.

samDesired 
[in] Access mask that specifies the access rights for the key.

lpSecurityAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes.

phkResult 
[out] Pointer to a variable that receives a handle to the opened or created key.

lpdwDisposition 
[out] Pointer to a variable that receives a disposition value.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
See also RegCloseKey, RegDeleteKey, RegSaveKey, RegOpenKeyEx.  
  
***  

