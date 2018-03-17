<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRegDeleteKey
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function deletes a named subkey from the specified registry key. The subkey to be deleted cannot have any subkeys.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegDeleteKey(
  HKEY hKey,
  LPCWSTR lpszSubKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegDeleteKey IN rapi;
	INTEGER hKey,;
	STRING  lpszSubKey  
```  
***  


## Parameters:
```txt  
hKey
[in] Handle to a currently open key or one of the predefined reserved handle values.

lpszSubKey
[in] Pointer to a null-terminated string specifying the name of the key to delete.  
```  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
While testing this function I noticed that you are still able to delete a key with subkeys.  
  
***  

