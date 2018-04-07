[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LCIDToLocaleName
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Converts a locale identifier to a locale name.
***  


## Declaration:
```foxpro  
int LCIDToLocaleName(
  _In_       LCID Locale,
  _Out_opt_  LPWSTR lpName,
  _In_       int cchName,
  _In_       DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LCIDToLocaleName IN kernel32;
	INTEGER nLocale,;
	STRING @lpName,;
	INTEGER cchName,;
	INTEGER dwFlags  
```  
***  


## Parameters:
Locale [in]
Locale identifier to translate.

lpName [out, optional]
Pointer to a buffer in which this function retrieves the locale name, or one of predefined values.

cchName [in]
Size, in characters, of the locale name buffer. 

dwFlags [in]
Before Windows 7: Reserved; should always be 0.  
***  


## Return value:
Returns the count of characters, including the terminating null character, in the locale name if successful.   
***  


## Comments:
See also: [LocaleNameToLCID](../kernel32/LocaleNameToLCID.md), [GetUserDefaultLCID](../kernel32/GetUserDefaultLCID.md).  
  
***  

