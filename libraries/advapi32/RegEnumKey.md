[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegEnumKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegEnumKey function enumerates subkeys of the specified open registry key. The function retrieves the name of one subkey each time it is called.
***  


## Code examples:
[Saving local machine ODBC Registry Entries to XML file](../../samples/sample_379.md)  
[How to obtain Content-Type value for a file type from the System Registry](../../samples/sample_468.md)  

## Declaration:
```foxpro  
LONG RegEnumKey(
  HKEY hKey,
  DWORD dwIndex,
  LPTSTR lpName,
  DWORD cchName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegEnumKey IN advapi32;
	INTEGER   hKey,;
	INTEGER   dwIndex,;
	STRING  @ lpName,;
	INTEGER   cchName  
```  
***  


## Parameters:
hKey 
[in] Handle to an open key.

dwIndex 
[in] Index of the subkey of hKey to be retrieved. 

lpName 
[out] Pointer to a buffer that receives the name of the subkey.

cchName 
[in] Size of the buffer pointed to by the lpName parameter.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
MSDN: This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the RegEnumKeyEx function.  
  
***  

