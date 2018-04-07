[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrencyFormat
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Formats a number string as a currency string for a locale specified by identifier.
***  


## Declaration:
```foxpro  
int GetCurrencyFormat(
  _In_       LCID Locale,
  _In_       DWORD dwFlags,
  _In_       LPCTSTR lpValue,
  _In_opt_   const CURRENCYFMT *lpFormat,
  _Out_opt_  LPTSTR lpCurrencyStr,
  _In_       int cchCurrency
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrencyFormat IN kernel32;
	INTEGER Locale,;
	INTEGER dwFlags,;
	STRING lpValue,;
	INTEGER lpFormat,;
	STRING @lpCurrencyStr,;
	INTEGER cchCurrency  
```  
***  


## Parameters:
Locale [in]
Locale identifier that specifies the locale for which this function formats the currency string.

dwFlags [in]
Flags controlling currency format. The application must set this parameter to 0 if lpFormat is not set to NULL.

lpValue [in]
Pointer to a null-terminated string containing the number string to format: characters "0" through "9", one decimal point (dot) if the number is a floating-point value, A minus sign in the first character position if the number is a negative value.

lpFormat [in, optional]
Pointer to a CURRENCYFMT structure that contains currency formatting information.

lpCurrencyStr [out, optional]
Pointer to a buffer in which this function retrieves the formatted currency string.

cchCurrency [in]
Size, in characters, of the lpCurrencyStr buffer.  
***  


## Return value:
Returns the number of characters retrieved in the buffer indicated by lpCurrencyStr if successful. 

If the cchCurrency parameter is set to 0, the function returns the size of the buffer required to hold the formatted currency string, including a terminating null character.  
***  


## Comments:
See also: [GetNumberFormat](../kernel32/GetNumberFormat.md), [GetDateFormat](../kernel32/GetDateFormat.md).  
  
***  

