[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WideCharToMultiByte
Group: [Unicode and Character Set](../../functions_group.md#Unicode_and_Character_Set)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The WideCharToMultiByte function maps a wide-character string (Unicode) to a new character string.
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  
[Converting Unicode data from the Clipboard to a character string using a given code page](../../samples/sample_316.md)  
[Creating an Open dialog box to specify the drive, directory, and name of a file to open (Shell32 version)](../../samples/sample_365.md)  

## Declaration:
```foxpro  
int WideCharToMultiByte(
  UINT CodePage,            // code page
  DWORD dwFlags,            // performance and mapping flags
  LPCWSTR lpWideCharStr,    // wide-character string
  int cchWideChar,          // number of chars in string
  LPSTR lpMultiByteStr,     // buffer for new string
  int cbMultiByte,          // size of buffer
  LPCSTR lpDefaultChar,     // default for unmappable chars
  LPBOOL lpUsedDefaultChar  // set when default char used
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WideCharToMultiByte IN kernel32;
	INTEGER   CodePage,;
	INTEGER   dwFlags,;
	STRING    lpWideCharStr,;
	INTEGER   cchWideChar,;
	STRING  @ lpMultiByteStr,;
	INTEGER   cbMultiByte,;
	STRING    lpDefaultChar,;
	INTEGER   lpUsedDefaultChar  
```  
***  


## Parameters:
CodePage 
[in] Specifies the code page used to perform the conversion. 

dwFlags 
[in] Specifies the handling of unmapped characters.

lpWideCharStr 
[in] Points to the wide-character string to be converted. 

cchWideChar 
[in] Specifies the number of wide characters in the string pointed to by the lpWideCharStr parameter. 

lpMultiByteStr 
[out] Points to the buffer to receive the translated string. 

cbMultiByte 
[in] Specifies the size, in bytes, of the buffer pointed to by the lpMultiByteStr parameter. 

lpDefaultChar 
[in] Points to the character used if a wide character cannot be represented in the specified code page.

lpUsedDefaultChar 
[in] Points to a flag that indicates whether a default character was used. 
  
***  


## Return value:
If the function succeeds, and cbMultiByte is nonzero, the return value is the number of bytes written to the buffer pointed to by lpMultiByteStr. The number includes the byte for the null terminator.  
***  


## Comments:
FoxPro function StrConv() with Unicode support added in VFP7 makes this call redundant.  
  
***  

