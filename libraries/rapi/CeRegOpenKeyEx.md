<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRegOpenKeyEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function opens the specified key.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegOpenKeyEx(
  HKEY hKey,
  LPCWSTR lpszSubKey,
  DWORD ulOptions,
  REGSAM samDesired,
  PHKEY phkResult
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegOpenKeyEx IN rapi;
	INTEGER   hKey,;
	STRING    lpszSubKey,;
	INTEGER   ulOptions,;
	INTEGER   samDesired,;
	INTEGER @ phkResult  
```  
***  


## Parameters:
```txt  
hKey
[in] Handle to a currently open key or any of the predefined reserved handle values

lpszSubKey
[in] Pointer to a null-terminated string containing the name of the subkey to open.

ulOptions
[in] Reserved; set to 0.

samDesired
[in] Not supported; set to 0.

phkResult
[out] Pointer to a variable that receives a handle to the opened key.  
```  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
When you no longer need the returned handle, call the CeRegCloseKey function to close it.   
  
***  

