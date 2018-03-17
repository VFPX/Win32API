<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : StrToIntEx
Group: String - Library: shlwapi    
***  


#### Converts a decimal or hexadecimal string to an integer.
***  


## Code examples:
[OS version and revision](../../samples/sample_022.md)  
[Converting a hexadecimal string to an integer](../../samples/sample_107.md)  

## Declaration:
```foxpro  
BOOL StrToIntEx(
    LPCTSTR pszString,
    DWORD dwFlags,
    int FAR * piRet
    );
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT StrToIntEx IN Shlwapi;
	STRING    pszString,;
	INTEGER   dwFlags,;
	INTEGER @ pllRet
  
```  
***  


## Parameters:
```txt  
pszString
Address of a null-terminated string to be converted.

dwFlags
Specifies if pszString contains a decimal or hexadecimal value.

piRet
Address of an integer variable that receives the converted string.  
```  
***  


## Return value:
Returns TRUE if the string is converted, or FALSE otherwise.  
***  


## Comments:
When using STIF_SUPPORT_HEX for a hexadecimal value, the string must be prefixed with "0x", as in hexadecimal values in C++. E.g. 0x800  
  
See also: StrToInt, StrToInt64Ex   
  
***  

