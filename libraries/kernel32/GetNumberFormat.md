[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNumberFormat
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Formats a number string as a number string customized for a locale specified by identifier.
***  


## Declaration:
```foxpro  
int GetNumberFormat(
  _In_       LCID Locale,
  _In_       DWORD dwFlags,
  _In_       LPCTSTR lpValue,
  _In_opt_   const NUMBERFMT *lpFormat,
  _Out_opt_  LPTSTR lpNumberStr,
  _In_       int cchNumber
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNumberFormat IN kernel32;
	INTEGER Locale,;
	INTEGER dwFlags,;
	STRING lpValue,;
	INTEGER lpFormat,;
	STRING @lpNumberStr,;
	INTEGER cchNumber
  
```  
***  


## Parameters:
Locale [in]
Locale identifier that specifies the locale. 

dwFlags [in]
Flags controlling the operation of the function. The application must set this parameter to 0 if lpFormat is not set to NULL.

lpValue [in]
Pointer to a null-terminated string containing the number string to format: characters "0" through "9", one decimal point (dot) if the number is a floating-point value, A minus sign in the first character position if the number is a negative value.

lpFormat [in, optional]
Pointer to a NUMBERFMT structure that contains number formatting information, with all members set to appropriate values.

lpNumberStr [out, optional]
Pointer to a buffer in which this function retrieves the formatted number string.

cchNumber [in]
Size, in TCHAR values, for the number string buffer indicated by lpNumberStr.  
***  


## Return value:
Returns the number of TCHAR values retrieved in the buffer indicated by lpNumberStr if successful. 

If the cchNumber parameter is set to 0, the function returns the number of characters required to hold the formatted number string, including a terminating null character.  
***  


## Comments:
See also: [GetCurrencyFormat](../kernel32/GetCurrencyFormat.md), [GetDateFormat](../kernel32/GetDateFormat.md).  
  
***  

