[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetStringTypeEx
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves character type information for the characters in the specified source string. For each character in the string, the function sets one or more bits in the corresponding 16-bit element of the output array. Each bit identifies a given character type, for example, letter, digit, or neither.
***  


## Code examples:
[Analyzing character types in a specified string](../../samples/sample_600.md)  

## Declaration:
```foxpro  
BOOL GetStringTypeEx(
  _In_   LCID Locale,
  _In_   DWORD dwInfoType,
  _In_   LPCTSTR lpSrcStr,
  _In_   int cchSrc,
  _Out_  LPWORD lpCharType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetStringTypeEx IN kernel32;
	INTEGER Locale,;
	INTEGER dwInfoType,;
	STRING lpSrcStr,;
	INTEGER cchSrc,;
	STRING @lpCharType  
```  
***  


## Parameters:
Locale [in]
Locale identifier that specifies the locale.

dwInfoType [in]
Flags specifying the character type information to retrieve.

lpSrcStr [in]
Pointer to the string for which to retrieve the character types. The string is assumed to be null-terminated if cchSrc is set to any negative value.

cchSrc [in]
Size, in characters, of the string indicated by lpSrcStr. The size refers to bytes for the ANSI version of the function or wide characters for the Unicode version.

lpCharType [out]
Pointer to an array of 16-bit values. The length of this array must be large enough to receive one 16-bit value for each character in the source string.   
***  


## Return value:
Returns a nonzero value if successful, or 0 otherwise.   
***  

