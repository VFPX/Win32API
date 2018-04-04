[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegDeleteValue
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function removes a named value from the specified registry key. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegDeleteValue(
  HKEY hKey,
  LPCWSTR lpszValueName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegDeleteValue IN rapi;
	INTEGER hKey,;
	STRING  lpszValueName  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or any of the predefined reserved handle values.

lpszValueName 
[in] Pointer to a null-terminated string that names the value to remove.  
***  


## Return value:
ERROR_SUCCESS indicates success.  
***  


## Comments:
If <Em>lpszValueName</Em> parameter is NULL or points to an empty string, the default value of the key is removed. A default value is created by calling CeRegSetValueEx (RAPI) with a NULL or empty string value name.   
  
***  

