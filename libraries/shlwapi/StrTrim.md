[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrTrim
Group: [String](../../functions_group.md#String)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Removes (trims) specified leading and trailing characters from a string.
***  


## Code examples:
[High-powered ALLTRIM](../../samples/sample_104.md)  

## Declaration:
```foxpro  
BOOL StrTrim(
    LPTSTR pszSource,
    LPCTSTR pszTrimChars
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrTrim IN Shlwapi As StrTrim;
   	STRING @ pszSource,;
   	STRING   pszTrimChars  
```  
***  


## Parameters:
pszSource 
[in/out] Pointer to the string to be trimmed. On return, pszSource will hold the trimmed string. 

pszTrimChars 
[in] Pointer to a null-terminated string containing the characters that will be trimmed from psz.  
***  


## Return value:
Returns TRUE if any characters were removed, or FALSE otherwise.  
***  


## Comments:
Unlike the native ALLTRIM, this function can remove not only blanks but any other characters included into the trim character list.   
  
For this function, like for the most String functions, StrTrimA and StrTrimW flavours are available.  
  
***  

