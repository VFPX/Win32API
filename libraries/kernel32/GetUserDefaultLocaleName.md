[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserDefaultLocaleName
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the user default locale name.
***  


## Declaration:
```foxpro  
int GetUserDefaultLocaleName(
  _Out_  LPWSTR lpLocaleName,
  _In_   int cchLocaleName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUserDefaultLocaleName;
IN kernel32;
	STRING @lpLocaleName,;
	INTEGER cchLocaleName
  
```  
***  


## Parameters:
lpLocaleName [out]
Pointer to a buffer in which this function retrieves the locale name.

cchLocaleName [in]
Size, in characters, of the buffer indicated by lpLocaleName.  
***  


## Return value:
Returns the size of the buffer containing the locale name, including the terminating null character, if successful.  
***  


## Comments:
See also: [GetSystemDefaultLocaleName](../kernel32/GetSystemDefaultLocaleName.md), [GetUserDefaultLCID](../kernel32/GetUserDefaultLCID.md).  
  
***  

