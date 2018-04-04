[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegEnumValue
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Enumerates the values for the specified open registry key.
***  


## Code examples:
[Reading VFP settings from the Windows Registry](../../samples/sample_131.md)  
[Saving local machine ODBC Registry Entries to XML file](../../samples/sample_379.md)  
[How to obtain Content-Type value for a file type from the System Registry](../../samples/sample_468.md)  
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegEnumValue(
  HKEY hKey,             // handle to key to query
  DWORD dwIndex,         // index of value to query
  LPTSTR lpValueName,    // value buffer
  LPDWORD lpcValueName,  // size of value buffer
  LPDWORD lpReserved,    // reserved
  LPDWORD lpType,        // type buffer
  LPBYTE lpData,         // data buffer
  LPDWORD lpcbData       // size of data buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegEnumValue IN advapi32;
	INTEGER   hKey,;
	INTEGER   dwIndex,;
	STRING  @ lpValueName,;
	INTEGER @ lpcValueName,;
	INTEGER   lpReserved,;
	INTEGER @ lpType,;
	STRING  @ lpData,;
	INTEGER @ lpcbData  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or a predefined reserved handle value.

dwIndex 
[in] Specifies the index of the value to retrieve. This parameter should be zero for the first call to the RegEnumValue function and then be incremented for subsequent calls. 

lpValueName 
[out] Pointer to a buffer that receives the name of the value, including the terminating null character. 

lpcValueName 
[in/out] Pointer to a variable that specifies the size, in TCHARs, of the buffer pointed to by the lpValueName parameter. This size should include the terminating null character. 

lpReserved 
Reserved; must be NULL. 

lpType 
[out] Pointer to a variable that receives a code indicating the type of data stored in the specified value. 

lpData 
[out] Pointer to a buffer that receives the data for the value entry. 

lpcbData 
[in/out] Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the lpData parameter.  
***  


## Return value:
If the function succeeds, the return value is 0 (ERROR_SUCCESS).  
***  


## Comments:
The function copies one indexed value name and data block for the key each time it is called.  
  
***  

