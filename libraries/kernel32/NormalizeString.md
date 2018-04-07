[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NormalizeString
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Normalizes characters of a text string according to Unicode 4.0 TR#15.
***  


## Declaration:
```foxpro  
int NormalizeString(
  _In_       NORM_FORM NormForm,
  _In_       LPCWSTR lpSrcString,
  _In_       int cwSrcLength,
  _Out_opt_  LPWSTR lpDstString,
  _In_       int cwDstLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NormalizeString IN kernel32;
	INTEGER NormForm,;
	STRING lpSrcString,;
	INTEGER cwSrcLength,;
	STRING @lpDstString,;
	INTEGER cwDstLength
  
```  
***  


## Parameters:
NormForm [in]
Normalization form to use. NORM_FORM specifies the standard Unicode normalization forms.

lpSrcString [in]
Pointer to the non-normalized source string.

cwSrcLength [in]
Length, in characters, of the buffer containing the source string. The application can set this parameter to -1 if the function should assume the string to be null-terminated and calculate the length automatically.

lpDstString [out, optional]
Pointer to a buffer in which the function retrieves the destination string.

cwDstLength [in]
Length, in characters, of the buffer containing the destination string. Alternatively, the application can set this parameter to 0 to request the function to return the required size for the destination buffer.  
***  


## Return value:
Returns the length of the normalized string in the destination buffer.  
***  


## Comments:
MSDN: <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/dd374126(v=vs.85).aspx">Using Unicode Normalization to Represent Strings</a>  
  
See also: [IsNormalizedString](..//IsNormalizedString.md).  
  
***  

