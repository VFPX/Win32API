<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserDefaultLocaleName
Group: National Language Support - Library: kernel32    
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
```txt  
lpLocaleName [out]
Pointer to a buffer in which this function retrieves the locale name.

cchLocaleName [in]
Size, in characters, of the buffer indicated by lpLocaleName.  
```  
***  


## Return value:
Returns the size of the buffer containing the locale name, including the terminating null character, if successful.  
***  


## Comments:
See also: GetSystemDefaultLocaleName, GetUserDefaultLCID   
  
***  

