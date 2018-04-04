[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegQueryInfoKey
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function retrieves information about a specified registry key.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegQueryInfoKey(
  HKEY hKey,
  LPWSTR lpClass,
  LPDWORD lpcbClass,
  LPDWORD lpReserved,
  LPDWORDlpcSubKeys,
  LPDWORD lpcbMaxSubKeyLen,
  LPDWORD lpcbMaxClassLen,
  LPDWORD lpcValues,
  LPDWORD lpcbMaxValueNameLen,
  LPDWORD lpcbMaxValueLen,
  LPDWORD lpcbSecurityDescriptor,
  PFILETIME lpftLastWriteTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegQueryInfoKey IN rapi;
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
[in] Handle to a currently open key or predefined reserved handle value.

lpClass 
[out] Pointer to a buffer that receives the key"s class name. This parameter can be NULL. 

lpcbClass 
[in, out] Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the lpClass parameter.

lpReserved 
[in] Reserved; set to NULL. 

lpcSubKeys 
[out] Pointer to a variable that receives the number of subkeys contained by the specified key. This parameter can be NULL. 

lpcbMaxSubKeyLen 
[out] Pointer to a variable that receives the length, in characters, of the key"s subkey with the longest name.

lpcbMaxClassLen 
[out] Pointer to a variable that receives the length, in characters, of the longest string specifying a subkey class.

lpcValues 
[out] Pointer to a variable that receives the number of values associated with the key. This parameter can be NULL. 

lpcbMaxValueNameLen 
[out] Pointer to a variable that receives the length, in characters, of the key"s longest value name. 

lpcbMaxValueLen 
[out] Pointer to a variable that receives the length, in bytes, of the longest data component among the values of the key. This parameter can be NULL. 

lpcbSecurityDescriptor 
[in] Not used; set to NULL. 

lpftLastWriteTime 
[in] Ignored; set to NULL.   
***  


## Return value:
ERROR_SUCCESS indicates success (0).  
***  

