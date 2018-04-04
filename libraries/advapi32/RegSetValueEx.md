[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegSetValueEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegSetValueEx function sets the data and type of a specified value under a registry key.
***  


## Code examples:
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegSetValueEx(
  HKEY hKey,
  LPCTSTR lpValueName,
  DWORD Reserved,
  DWORD dwType,
  const BYTE* lpData,
  DWORD cbData
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegSetValueEx IN advapi32;
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
[in] Handle to an open key.

lpValueName 
[in] Pointer to a string containing the name of the value to set. 

Reserved 
Reserved; must be zero. 

dwType 
[in] Type of data pointed to by the lpData parameter.

lpData 
[in] Pointer to a buffer containing the data to be stored with the specified value name.

cbData 
[in] Size of the information pointed to by the lpData parameter, in bytes.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
See also RegCreateKeyEx, RegFlushKey, RegOpenKeyEx, RegQueryValueEx.  
  
***  

