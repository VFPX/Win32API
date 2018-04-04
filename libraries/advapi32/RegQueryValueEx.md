[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegQueryValueEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves the type and data for a specified value name associated with an open registry key.
***  


## Code examples:
[Obtaining current Internet Explorer browser version and UserAgent](../../samples/sample_142.md)  
[Enumerating Performance Counters](../../samples/sample_565.md)  

## Declaration:
```foxpro  
LONG RegQueryValueEx(
  HKEY hKey,            // handle to key
  LPCTSTR lpValueName,  // value name
  LPDWORD lpReserved,   // reserved
  LPDWORD lpType,       // type buffer
  LPBYTE lpData,        // data buffer
  LPDWORD lpcbData      // size of data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegQueryValueEx IN advapi32;
	INTEGER   hKey,;
	STRING    lpValueName,;
	INTEGER   lpReserved,;
	INTEGER @ lpType,;
	STRING  @ lpData,;
	INTEGER @ lpcbData
  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or a predefined reserved handle value.

lpValueName 
[in] Pointer to a null-terminated string containing the name of the value to query.

lpReserved 
Reserved; must be NULL. 

lpType 
[out] Pointer to a variable that receives a code indicating the type of data stored in the specified value.

lpData 
[in, out] Pointer to a buffer that receives the value"s data.

lpcbData 
[in/out] Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the lpData parameter. When the function returns, this variable contains the size of the data copied to lpData.
  
***  


## Return value:
If the function succeeds, the return value is 0 (ERROR_SUCCESS). If the function fails, the return value is a nonzero error code.
  
***  

