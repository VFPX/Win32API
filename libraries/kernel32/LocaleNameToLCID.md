<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LocaleNameToLCID
Group: National Language Support - Library: kernel32    
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
```txt  
lpName [in]
Pointer to a null-terminated string representing a locale name, or one of predefined values.

dwFlags [in]
Prior to Windows 7: Reserved; should always be 0.  
```  
***  


## Return value:
Returns the locale identifier corresponding to the locale name if successful.  
***  


## Comments:
See also: LCIDToLocaleName, GetUserDefaultLocaleName   
  
***  

