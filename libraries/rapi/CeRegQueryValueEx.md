<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRegQueryValueEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function retrieves the type and data for a specified value name associated with an open registry key. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegQueryValueEx(
  HKEY hKey,
  LPCWSTR lpValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE lpData,
  LPDWORD lpcbData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegQueryValueEx IN rapi;
	INTEGER   hKey,;
	STRING    lpValueName,;
	INTEGER   lpReserved,;
	INTEGER @ lpType,;
	STRING  @ lpData,;
	INTEGER @ lpcbData
  
```  
***  


## Parameters:
```txt  
hKey
[in] Handle to a currently open key or predefined reserved handle value.

lpValueName
[in] Pointer to a string containing the name of the value to query. If this parameter is NULL or an empty string, the function retrieves the type and data for the key"s unnamed value.

lpReserved
[in] Reserved; set to NULL.

lpType
[out] Pointer to a variable that receives the type of data associated with the specified value.

lpData
[out] Pointer to a buffer that receives the value"s data.

lpcbData
[in, out] Pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the lpData parameter. When the function returns, this variable contains the size of the data copied to lpData.  
```  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.   
***  


## Comments:
The key identified by hKey must have been opened with KEY_QUERY_VALUE access. To open the key, use the CeRegCreateKeyEx (RAPI) or CeRegOpenKeyEx (RAPI) function.  
  
A registry key does not automatically have an unnamed or default value. Unnamed values can be of any type.   
  
***  

