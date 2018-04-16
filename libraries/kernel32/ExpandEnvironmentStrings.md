[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExpandEnvironmentStrings
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Expands environment-variable strings and replaces them with their defined values.
***  


## Code examples:
[Converting path to original case](../../samples/sample_102.md)  
[One more way to retrieve environment strings](../../samples/sample_132.md)  

## Declaration:
```foxpro  
DWORD ExpandEnvironmentStrings(
  LPCTSTR lpSrc, // string with envir.variables
  LPTSTR lpDst,  // string with expanded strings
  DWORD nSize    // max. characters in expanded string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ExpandEnvironmentStrings IN kernel32;
	STRING   lpSrc,;
	STRING @ lpDst,;
	INTEGER  nSize  
```  
***  


## Parameters:
lpSrc 
[in] Pointer to a null-terminated string that contains environment-variable strings of the form: %variableName%. 

lpDst 
[out] Pointer to a buffer to receive a copy of the source buffer after all environment-variable name substitutions have been performed. 

nSize 
[in] Specifies the maximum number of TCHARs that can be stored in the buffer pointed to by the lpDst parameter, including the terminating null character.  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs stored in the destination buffer, including the terminating null character.  
***  


## Comments:
See also: [GetEnvironmentStrings](GetEnvironmentStrings.md), [GetSystemInfo](GetSystemInfo.md).  
  
***  

