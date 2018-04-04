[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegQueryInfoKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegQueryInfoKey function retrieves information about the specified registry key.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegQueryInfoKey(
  HKEY hKey,
  LPTSTR lpClass,
  LPDWORD lpcClass,
  LPDWORD lpReserved,
  LPDWORD lpcSubKeys,
  LPDWORD lpcMaxSubKeyLen,
  LPDWORD lpcMaxClassLen,
  LPDWORD lpcValues,
  LPDWORD lpcMaxValueNameLen,
  LPDWORD lpcMaxValueLen,
  LPDWORD lpcbSecurityDescriptor,
  PFILETIME lpftLastWriteTime
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegQueryInfoKey IN advapi32;
	INTEGER   hKey,;
	STRING  @ lpClass,;
	INTEGER @ lpcbClass,;
	INTEGER   lpReserved,;
	INTEGER @ lpcSubKeys,;
	INTEGER @ lpcbMaxSubKeyLen,;
	INTEGER @ lpcbMaxClassLen,;
	INTEGER @ lpcValues,;
	INTEGER @ lpcbMaxValueNameLen,;
	INTEGER @ lpcbMaxValueLen,;
	INTEGER   lpcbSecurityDescr,;
	INTEGER   lpftLastWriteTime
  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key. 

lpClass 
[out] Pointer to a buffer that receives the null-terminated class string of the key.

lpcClass 
[in, out] Pointer to a variable that specifies the size of the buffer pointed to by the lpClass parameter, in characters.

lpReserved 
Reserved; must be NULL. 

lpcSubKeys 
[out] Pointer to a variable that receives the number of subkeys contained by the specified key.

lpcMaxSubKeyLen 
[out] Pointer to a variable that receives the size of the key"s subkey with the longest name, in characters, not including the terminating null character.

lpcMaxClassLen 
[out] Pointer to a variable that receives the size of the longest string specifying a subkey class, in characters.

lpcValues 
[out] Pointer to a variable that receives the number of values associated with the key.

lpcMaxValueNameLen 
[out] Pointer to a variable that receives the size of the key"s longest value name, in characters.

lpcMaxValueLen 
[out] Pointer to a variable that receives the size of the longest data component among the key"s values, in bytes.

lpcbSecurityDescriptor 
[out] Pointer to a variable that receives the size of the key"s security descriptor, in bytes.

lpftLastWriteTime 
[out] Pointer to a FILETIME structure that receives the last write time.   
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
See also RegDeleteKey, RegEnumKeyEx, RegEnumValue, RegQueryValueEx.  
  
***  

