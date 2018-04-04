[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrCpy
Group: [Shell Lightweight Utility APIs -- string functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_string_functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Copies one string to another.
***  


## Code examples:
[StrDup returns a pointer to the duplicate of a source VFP string](../../samples/sample_181.md)  

## Declaration:
```foxpro  
LPTSTR StrCpy(
    LPTSTR psz1,
    LPCTSTR psz2
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrCpyW IN shlwapi AS StrCpy;
	STRING  @ psz1,;
	INTEGER   psz2  
```  
***  


## Parameters:
psz1 
[out] Pointer to the destination string. 

psz2 
[in] Pointer to the null-terminated source string.  
***  


## Return value:
Returns a pointer to psz1.  
***  


## Comments:
MSDN suggests some security problems related to this function and recommends using StrCpyN instead.  
  
***  

