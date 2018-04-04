[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CharUpper
Group: [String](../../functions_group.md#String)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Converts a character string or a single character to uppercase. If the operand is a character string, the function converts the characters in place.
***  


## Code examples:
[Converting characters to upper or lower case](../../samples/sample_075.md)  

## Declaration:
```foxpro  
LPTSTR CharUpper(
  LPTSTR lpsz   // single character or string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CharUpper IN user32 STRING @ lpsz  
```  
***  


## Parameters:
lpsz 
[in/out] Pointer to a null-terminated string or specifies a single character. If the high-order word of this parameter is zero, the low-order word must contain a single character to be converted.  
***  


## Return value:
If the operand is a character string, the function returns a pointer to the converted string. Since the string is converted in place, the return value is equal to lpsz. 

If the operand is a single character, the return value is a 32-bit value whose high-order word is zero, and low-order word contains the converted character. 
  
***  

