[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPrivateProfileString
Group: [Registry](../../functions_group.md#Registry)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves a string from the specified section in an initialization file.
***  


## Code examples:
[Reading data from INI files](../../samples/sample_133.md)  

## Declaration:
```foxpro  
DWORD GetPrivateProfileString(
  LPCTSTR lpAppName,        // section name
  LPCTSTR lpKeyName,        // key name
  LPCTSTR lpDefault,        // default string
  LPTSTR lpReturnedString,  // destination buffer
  DWORD nSize,              // size of destination buffer
  LPCTSTR lpFileName        // initialization file name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPrivateProfileString IN kernel32;
	STRING   lpAppName,;
	STRING   lpKeyName,;
	STRING   lpDefault,;
	STRING @ lpReturnedString,;
	INTEGER  nSize,;
	STRING   lpFileName  
```  
***  


## Parameters:
lpAppName 
[in] Pointer to a null-terminated string that specifies the name of the section containing the key name.

lpKeyName 
[in] Pointer to the null-terminated string specifying the name of the key whose associated string is to be retrieved.

lpDefault 
[in] Pointer to a null-terminated default string.

lpReturnedString 
[out] Pointer to the buffer that receives the retrieved string. 

nSize 
[in] Specifies the size, in TCHARs, of the buffer pointed to by the lpReturnedString parameter. 

lpFileName 
[in] Pointer to a null-terminated string that specifies the name of the initialization file.  
***  


## Return value:
The return value is the number of characters copied to the buffer, not including the terminating null character.  
***  

