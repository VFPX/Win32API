[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegEnumValue
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function enumerates the values for the specified open registry key. CeRegEnumValue copies one indexed value name and data block for the key each time it is called.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegEnumValue(
  HKEY hKey,
  DWORD dwIndex,
  LPWSTR lpszValueName,
  LPDWORD lpcbValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE lpData,
  LPDWORD lpcbData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegEnumValue IN rapi;
	INTEGER   hKey,;
	INTEGER   dwIndex,;
	STRING  @ lpszValueName,;
	INTEGER @ lpcbValueName,;
	INTEGER   lpReserved,;
	INTEGER @ lpType,;
	STRING  @ lpData,;
	INTEGER @ lpcbData  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or predefined reserved handle value.

dwIndex 
[in] Specifies the index of the value to retrieve. This parameter should be 0 for the first call to the CeRegEnumValue function and then be incremented for subsequent calls.

lpszValueName 
[out] Pointer to a buffer that receives the name of the value, including the terminating null character. 

lpcbValueName 
[in, out] Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the lpValueName parameter. 

lpReserved 
[in] Reserved; set to NULL. 

lpType 
[out] Pointer to a variable that receives the type code for the value entry.

lpData 
[out] Pointer to a buffer that receives the data for the value entry. This parameter can be NULL if the data is not required. 

lpcbData 
[in, out] Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the lpData parameter. 
  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
To enumerate values, an application should initially call the CeRegEnumValue function with the dwIndex parameter set to 0. The application should then increment dwIndex and call the CeRegEnumValue function until there are no more values (until the function returns ERROR_NO_MORE_ITEMS).   
  
***  

