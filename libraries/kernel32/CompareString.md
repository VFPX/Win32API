[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CompareString
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Compares two character strings, for a locale specified by identifier.
***  


## Declaration:
```foxpro  
int CompareString(
  _In_  LCID Locale,
  _In_  DWORD dwCmpFlags,
  _In_  LPCTSTR lpString1,
  _In_  int cchCount1,
  _In_  LPCTSTR lpString2,
  _In_  int cchCount2
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CompareString IN kernel32;
	INTEGER Locale,;
	INTEGER dwCmpFlags,;
	STRING lpString1,;
	INTEGER cchCount1,;
	STRING lpString2,;
	INTEGER cchCount2  
```  
***  


## Parameters:
Locale [in]
Locale identifier of the locale used for the comparison.

dwCmpFlags [in]
Flags that indicate how the function compares the two strings.

lpString1 [in]
Pointer to the first string to compare.

cchCount1 [in]
Length of the string indicated by lpString1, excluding the terminating null character.

lpString2 [in]
Pointer to the second string to compare.

cchCount2 [in]
Length of the string indicated by lpString2, excluding the terminating null character.  
***  


## Return value:
CSTR_LESS_THAN = 1
CSTR_EQUAL = 2 -- The two strings are equivalent for sorting purposes, although not necessarily identical.
CSTR_GREATER_THAN = 3  
***  


## Comments:
The usage example shows two strings, which are equivalent in lexical value in the context of chosen comparison flags.  
  
#DEFINE LOCALE_CUSTOM_DEFAULT 0x0C00  
#DEFINE LOCALE_CUSTOM_UI_DEFAULT 0x1400  
#DEFINE LOCALE_CUSTOM_UNSPECIFIED 0x1000  
  
#DEFINE LOCALE_INVARIANT 0x007F  
#DEFINE LOCALE_SYSTEM_DEFAULT 0x0800  
#DEFINE LOCALE_USER_DEFAULT 0x0400  
  
#DEFINE LINGUISTIC_IGNORECASE 0x00000010  
#DEFINE LINGUISTIC_IGNOREDIACRITIC 0x00000020  
#DEFINE NORM_IGNORECASE 0x00000001  
  
#DEFINE CSTR_LESS_THAN 1  
#DEFINE CSTR_EQUAL 2  
#DEFINE CSTR_GREATER_THAN 3  
  
***  

