[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrDup
Group: [Shell Lightweight Utility APIs -- string functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_string_functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Duplicates a string.
***  


## Code examples:
[StrDup returns a pointer to the duplicate of a source VFP string](../../samples/sample_181.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  

## Declaration:
```foxpro  
LPTSTR StrDup(
    LPCTSTR lpsz
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrDup IN shlwapi;
	STRING lpsz  
```  
***  


## Parameters:
lpsz 
[in] Pointer to a constant null-terminated character string.  
***  


## Return value:
Returns the address of the string that was copied, or NULL if the string cannot be copied.  
***  


## Comments:
MSDN: this function uses LocalAlloc to allocate storage space for the copy of the string. The calling application must free this memory by calling the LocalFree function on the pointer returned by the call to StrDup.   
  
StrDup will allocate storage the size of the original string. If storage allocation is successful, the original string is copied to the duplicate string.   
  
***  

