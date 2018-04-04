[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegSaveKey
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegSaveKey function saves the specified key and all of its subkeys and values to a new file.
***  


## Code examples:
[How to save registry key including its subkeys and values to a file](../../samples/sample_135.md)  

## Declaration:
```foxpro  
LONG RegSaveKey(
  HKEY hKey,                                  // handle to key
  LPCTSTR lpFile,                             // data file
  LPSECURITY_ATTRIBUTES lpSecurityAttributes  // SD
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegSaveKey IN advapi32;
	INTEGER hKey,;
	STRING  lpFile,;
	INTEGER lpSecurityAttributes  
```  
***  


## Parameters:
hKey 
[in] Specifies a handle to the key where the save operation is to begin, or a predefined reserved handle value.

lpFile 
[in] Pointer to a null-terminated string containing the name of the file in which the specified key and subkeys are saved.

lpSecurityAttributes 
Windows NT/2000 or later: [in] Pointer to a structure that specifies a security descriptor for the new file.  
***  


## Return value:
If the function succeeds, the return value is 0 (ERROR_SUCCESS).  
***  

