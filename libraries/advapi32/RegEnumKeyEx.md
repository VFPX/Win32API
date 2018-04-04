[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegEnumKeyEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegEnumKeyEx function enumerates subkeys of the specified open registry key. The function retrieves information about one subkey each time it is called.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegEnumKeyEx(
  HKEY hKey,
  DWORD dwIndex,
  LPTSTR lpName,
  LPDWORD lpcName,
  LPDWORD lpReserved,
  LPTSTR lpClass,
  LPDWORD lpcClass,
  PFILETIME lpftLastWriteTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegEnumKeyEx IN advapi32;
	INTEGER   hKey,;
	INTEGER   dwIndex,;
	STRING  @ lpName,;
	INTEGER @ lpcbName,;
	INTEGER   lpReserved,;
	STRING  @ lpClass,;
	INTEGER @ lpcbClass,;
	INTEGER   lpftLastWriteTime
  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key.

dwIndex 
[in] Index of the subkey to retrieve.

lpName 
[out] Pointer to a buffer that receives the name of the subkey, including the terminating null character.

lpcName 
[in, out] Pointer to a variable that specifies the size of the buffer specified by the lpName parameter, in TCHARs. 

lpReserved 
Reserved; must be NULL. 

lpClass 
[in, out] Pointer to a buffer that receives the null-terminated class string of the enumerated subkey.

lpcClass 
[in, out] Pointer to a variable that specifies the size of the buffer specified by the lpClass parameter, in TCHARs.

lpftLastWriteTime 
[out] Pointer to a variable that receives the time at which the enumerated subkey was last written.   
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
See also RegQueryInfoKey, RegCreateKeyEx.  
  
***  

