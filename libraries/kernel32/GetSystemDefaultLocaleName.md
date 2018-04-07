[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemDefaultLocaleName
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the system default locale name.
***  


## Declaration:
```foxpro  
int GetSystemDefaultLocaleName(
  _Out_  LPWSTR lpLocaleName,
  _In_   int cchLocaleName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemDefaultLocaleName;
IN kernel32;
	STRING @lpLocaleName,;
	INTEGER cchLocaleName
  
```  
***  


## Parameters:
lpLocaleName [out]
Pointer to a buffer in which this function retrieves the locale name.

cchLocaleName [in]
Size, in characters, of the output buffer indicated by lpLocaleName.  
***  


## Return value:
Returns a value greater than 0 that indicates the length of the locale name, including the terminating null character, if successful.  
***  


## Comments:
See also: [GetUserDefaultLocaleName](../kernel32/GetUserDefaultLocaleName.md), [GetSystemDefaultLCID](../kernel32/GetSystemDefaultLCID.md).  
  
***  

