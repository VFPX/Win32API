[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegCreateKeyEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function creates the specified key. If the key already exists in the registry, the function opens it. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegCreateKeyEx(
  HKEY hKey,
  LPCWSTR lpszSubKey,
  DWORD Reserved,
  LPWSTR lpszClass,
  DWORD dwOptions,
  REGSAM samDesired,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  PHKEY phkResult,
  LPDWORD lpdwDisposition
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegCreateKeyEx IN rapi;
	INTEGER   hKey,;
	STRING    lpszSubKey,;
	INTEGER   Reserved,;
	STRING    lpszClass,;
	INTEGER   dwOptions,;
	INTEGER   samDesired,;
	INTEGER   lpSecurityAttr,;
	INTEGER @ phkResult,;
	INTEGER @ lpdwDisp
  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or one of the predefined reserved handle values.

lpszSubKey 
[in] Pointer to a null-terminated string specifying the name of a subkey that this function opens or creates. The subkey specified must be a subkey of the key identified by the hKey parameter. 

lpszClass 
[in] Pointer to a null-terminated string that specifies the class (object type) of this key.

dwOptions 
[in] Ignored; set to 0 to ensure compatibility with future versions of Windows CE. 

samDesired 
[in] Ignored; set to 0 to ensure compatibility with future versions of Windows CE. 

lpSecurityAttributes 
[in] Set to NULL. Windows CE automatically assigns the key a default security descriptor. 

phkResult 
[out] Pointer to a variable that receives a handle to the opened or created key. When you no longer need the returned handle, call the CeRegCloseKey function to close it. 
  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
In Windows CE, the maximum length of a key name is 255 characters, not including the terminating NULL character. You can also only nest 16 levels of sub-keys in Windows CE.  
  
***  

