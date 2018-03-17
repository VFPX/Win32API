<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRegDeleteValue
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
hKey
[in] Handle to a currently open key or any of the predefined reserved handle values.

lpszValueName
[in] Pointer to a null-terminated string that names the value to remove.  
```  
***  


## Return value:
ERROR_SUCCESS indicates success.  
***  


## Comments:
If <Em>lpszValueName</Em> parameter is NULL or points to an empty string, the default value of the key is removed. A default value is created by calling CeRegSetValueEx (RAPI) with a NULL or empty string value name.   
  
***  

