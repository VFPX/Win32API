[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegEnumKeyEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function enumerates subkeys of the specified open registry key. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegEnumKeyEx(
  HKEY hKey,
  DWORD dwIndex,
  LPWSTR lpName,
  LPDWORD lpcbName,
  LPDWORD lpReserved,
  LPWSTR lpClass,
  LPDWORD lpcbClass,
  PFILETIME lpftLastWriteTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegEnumKeyEx IN rapi;
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
[in] Handle to a currently open key or a predefined reserved handle value

dwIndex 
[in] Specifies the index of the subkey to retrieve. This parameter should be 0 for the first call to the CeRegEnumKeyEx function and then incremented for subsequent calls.

lpName 
[out] Pointer to a buffer that receives the name of the subkey, including the terminating null character. 

lpcbName 
[in, out] Pointer to a variable that specifies the size, in characters, of the buffer specified by the lpName parameter. 

lpReserved 
[in] Reserved; set to NULL. 

lpClass 
[out] Pointer to a buffer that contains the class of the enumerated subkey when the function returns.

lpcbClass 
[in, out] Pointer to a variable that specifies the size, in characters, of the buffer specified by the lpClass parameter.

lpftLastWriteTime 
[in] Ignored; set to NULL. 
  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
To enumerate subkeys, an application should initially call the CeRegEnumKeyEx function with the dwIndex parameter set to 0. An application should then increment the dwIndex parameter and call CeRegEnumKeyEx until there are no more subkeys (until the function returns ERROR_NO_MORE_ITEMS).   
  
***  

