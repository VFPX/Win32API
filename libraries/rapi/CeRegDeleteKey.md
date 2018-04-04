[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegDeleteKey
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
hKey 
[in] Handle to a currently open key or one of the predefined reserved handle values.

lpszSubKey 
[in] Pointer to a null-terminated string specifying the name of the key to delete.  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
While testing this function I noticed that you are still able to delete a key with subkeys.  
  
***  

