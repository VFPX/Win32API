[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : wnsprintf
Group: [Shell Lightweight Utility APIs -- string functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_string_functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Takes a variable-length argument list and returns the values of the arguments as a printf-style formatted string. 
***  


## Code examples:
[Retrieving a handle to DLL and address of an exported function in it](../../samples/sample_085.md)  
[Printf-style formatted text output in VFP](../../samples/sample_259.md)  
[Converting an integer value to a hexadecimal string](../../samples/sample_260.md)  

## Declaration:
```foxpro  
int wnsprintf(
    LPTSTR lpOut,
    int cchLimitIn
    LPCTSTR pszFmt,
    ...
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER wnsprintf IN Shlwapi;
	STRING  @ lpOut,;
	INTEGER   cchLimitIn,;
	STRING    pszFmt  
```  
***  


## Parameters:
lpOut 
[out] Buffer to hold the output string. 

cchLimitIn 
[in] Maximum number of characters allowed in lpOut. 

pszFmt 
[in] printf-style format string.   
***  


## Return value:
Returns the number of characters written to the buffer, excluding any terminating NULL characters. A negative value is returned if an error occurs.   
***  


## Comments:
This is a quite rare situation in the Win32, when an indefinite number of parameters passed to a function.  
  
***  

