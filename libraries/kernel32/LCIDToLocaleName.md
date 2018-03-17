<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LCIDToLocaleName
Group: National Language Support - Library: kernel32    
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
```txt  
Locale [in]
Locale identifier to translate.

lpName [out, optional]
Pointer to a buffer in which this function retrieves the locale name, or one of predefined values.

cchName [in]
Size, in characters, of the locale name buffer.

dwFlags [in]
Before Windows 7: Reserved; should always be 0.  
```  
***  


## Return value:
Returns the count of characters, including the terminating null character, in the locale name if successful.   
***  


## Comments:
See also: LocaleNameToLCID, GetUserDefaultLCID   
  
***  

