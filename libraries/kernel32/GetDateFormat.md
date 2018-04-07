[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDateFormat
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Formats a date as a date string for a locale specified by the locale identifier. The function formats either a specified date or the local system date.
***  


## Declaration:
```foxpro  
int GetDateFormat(
  _In_       LCID Locale,
  _In_       DWORD dwFlags,
  _In_opt_   const SYSTEMTIME *lpDate,
  _In_opt_   LPCTSTR lpFormat,
  _Out_opt_  LPTSTR lpDateStr,
  _In_       int cchDate
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDateFormat IN kernel32;
	INTEGER Locale,;
	INTEGER dwFlags,;
	STRING @lpDate,;
	STRING lpFormat,;
	STRING @lpDateStr,;
	INTEGER cchDate  
```  
***  


## Parameters:
Locale [in]
Locale identifier that specifies the locale this function formats the date string for.

dwFlags [in]
Flags specifying date format options.

lpDate [in, optional]
Pointer to a SYSTEMTIME structure that contains the date information to format. Set this parameter to NULL if the function is to use the current local system date.

pFormat [in, optional]
Pointer to a format picture string that is used to form the date. E.g. "MM/dd/yyyy".

lpDateStr [out, optional]
Pointer to a buffer in which this function retrieves the formatted date string.

cchDate [in]
Size, in characters, of the lpDateStr buffer.  
***  


## Return value:
Returns the number of characters written to the lpDateStr buffer if successful.   
***  


## Comments:
See also: [GetCurrencyFormat](../kernel32/GetCurrencyFormat.md), [GetNumberFormat](../kernel32/GetNumberFormat.md).  
  
***  

