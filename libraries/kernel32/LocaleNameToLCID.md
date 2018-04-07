[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LocaleNameToLCID
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Converts a locale name to a locale identifier.
***  


## Declaration:
```foxpro  
LCID LocaleNameToLCID(
  _In_  LPCWSTR lpName,
  _In_  DWORD dwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LocaleNameToLCID IN kernel32;
	STRING lpName,;
	INTEGER dwFlags  
```  
***  


## Parameters:
lpName [in]
Pointer to a null-terminated string representing a locale name, or one of predefined values.

dwFlags [in]
Prior to Windows 7: Reserved; should always be 0.  
***  


## Return value:
Returns the locale identifier corresponding to the locale name if successful.  
***  


## Comments:
See also: [LCIDToLocaleName](../kernel32/LCIDToLocaleName.md), [GetUserDefaultLocaleName](../kernel32/GetUserDefaultLocaleName.md).  
  
***  

