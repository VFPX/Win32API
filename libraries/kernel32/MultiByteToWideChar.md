[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MultiByteToWideChar
Group: [Unicode and Character Set](../../functions_group.md#Unicode_and_Character_Set)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The MultiByteToWideChar function maps a character string to a wide-character (Unicode) string.
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  
[Creating an Open dialog box to specify the drive, directory, and name of a file to open (Shell32 version)](../../samples/sample_365.md)  

## Declaration:
```foxpro  
int MultiByteToWideChar(
  UINT CodePage,         // code page
  DWORD dwFlags,         // character-type options
  LPCSTR lpMultiByteStr, // string to map
  int cbMultiByte,       // number of bytes in string
  LPWSTR lpWideCharStr,  // wide-character buffer
  int cchWideChar        // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MultiByteToWideChar IN kernel32;
	INTEGER   CodePg,;
	LONG      dwFlags,;
	STRING    lpMultiByteStr,;
	INTEGER   cbMultiByte,;
	STRING  @ lpWideCharStr,;
	INTEGER   cchWideChar
  
```  
***  


## Parameters:
CodePage 
[in] Specifies the code page to be used to perform the conversion.

dwFlags 
[in] A combination of the following flag constants. 

lpMultiByteStr 
[in] Points to the character string to be converted. 

cbMultiByte 
[in] Specifies the size in bytes of the string pointed to by the lpMultiByteStr parameter, or it can be -1 if the string is null terminated. Note that if cbMultiByte is 0, the function fails. 

lpWideCharStr 
[out] Points to a buffer that receives the translated string. 

cchWideChar 
[in] Specifies the size, in wide characters, of the buffer pointed to by the lpWideCharStr parameter.   
***  


## Return value:
If the function succeeds, and cchWideChar is nonzero, the return value is the number of wide characters written to the buffer pointed to by lpWideCharStr.   
***  


## Comments:
FoxPro function StrConv() with Unicode support added in VFP7 makes this call redundant.  
  
***  

