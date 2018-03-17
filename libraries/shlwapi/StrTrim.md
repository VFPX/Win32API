<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : StrTrim
Group: String - Library: shlwapi    
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
```txt  
pszSource
[in/out] Pointer to the string to be trimmed. On return, pszSource will hold the trimmed string.

pszTrimChars
[in] Pointer to a null-terminated string containing the characters that will be trimmed from psz.  
```  
***  


## Return value:
Returns TRUE if any characters were removed, or FALSE otherwise.  
***  


## Comments:
Unlike the native ALLTRIM, this function can remove not only blanks but any other characters included into the trim character list.   
  
For this function, like for the most String functions, StrTrimA and StrTrimW flavours are available.  
  
***  

