[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WritePrivateProfileString
Group: [Registry](../../functions_group.md#Registry)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The WritePrivateProfileString function copies a string into the specified section of an initialization file.
***  


## Code examples:
[Writing to INI file](../../samples/sample_137.md)  

## Declaration:
```foxpro  
BOOL WritePrivateProfileString(
  LPCTSTR lpAppName,  // section name
  LPCTSTR lpKeyName,  // key name
  LPCTSTR lpString,   // string to add
  LPCTSTR lpFileName  // initialization file
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE WritePrivateProfileString IN kernel32;
	STRING lpAppName,;
	STRING lpKeyName,;
	STRING lpString,;
	STRING lpFileName  
```  
***  


## Parameters:
lpAppName 
[in] Pointer to a null-terminated string containing the name of the section to which the string will be copied.

lpKeyName 
[in] Pointer to the null-terminated string containing the name of the key to be associated with a string. 

lpString 
[in] Pointer to a null-terminated string to be written to the file.

lpFileName 
[in] Pointer to a null-terminated string that specifies the name of the initialization file.  
***  


## Return value:
If the function successfully copies the string to the initialization file, the return value is nonzero.  
***  

