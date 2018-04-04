[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegSetValueEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function stores data in the value field of an open registry key. It can also set additional value and type information for the specified key. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegSetValueEx(
  HKEY hKey,
  LPCWSTR lpValueName,
  DWORD Reserved,
  DWORD dwType,
  const BYTE* lpData,
  DWORD cbData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegSetValueEx IN rapi;
	INTEGER   hKey,;
	STRING    lpValueName,;
	INTEGER   Reserved,;
	INTEGER   dwType,;
	STRING  @ lpData,;
	INTEGER   cbData
  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or any of the predefined reserved handle values.

lpValueName 
[in] Pointer to a string containing the name of the value to set. If a value with this name is not already present in the key, the function adds it to the key.

Reserved 
[in] Reserved; must be 0. 

dwType 
[in] Specifies the type of information to be stored as the value"s data.

lpData 
[in] Pointer to a buffer containing the data to be stored with the specified value name. 

cbData 
[in] Specifies the size, in bytes, of the information pointed to by the lpData parameter.  
***  


## Return value:
ERROR_SUCCESS indicates success.  
***  


## Comments:
The maximum size of data allowed in Windows CE is 4 KB.   
  
***  

