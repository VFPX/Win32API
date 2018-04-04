[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WritePrivateProfileSection
Group: [Registry](../../functions_group.md#Registry)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Replaces the keys and values for the specified section in an initialization file.
***  


## Code examples:
[Writing to INI file](../../samples/sample_137.md)  

## Declaration:
```foxpro  
BOOL WritePrivateProfileSection(
  LPCTSTR lpAppName,  // section name
  LPCTSTR lpString,   // data
  LPCTSTR lpFileName  // file name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE WritePrivateProfileSection IN kernel32;
	STRING lpAppName,;
	STRING lpString,;
	STRING lpFileName  
```  
***  


## Parameters:
lpAppName 
[in] Pointer to a null-terminated string specifying the name of the section in which data is written.

lpString 
[in] Pointer to a buffer containing the new key names and associated values that are to be written to the named section.

lpFileName 
[in] Pointer to a null-terminated string containing the name of the initialization file.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

