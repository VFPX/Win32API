[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetCrackUrl
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Cracks a URL into its component parts.
***  


## Code examples:
[URL: splitting into its component parts](../../samples/sample_184.md)  

## Declaration:
```foxpro  
BOOL InternetCrackUrl(
	LPCTSTR lpszUrl,
	DWORD dwUrlLength,
	DWORD dwFlags,
	LPURL_COMPONENTS lpUrlComponents
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetCrackUrl IN wininet;
	STRING    lpszUrl,;
	INTEGER   dwUrlLength,;
	INTEGER   dwFlags,;
	STRING  @ lpUrlComponents  
```  
***  


## Parameters:
lpszUrl
[in] Pointer to a string that contains the canonical URL to crack.

dwUrlLength
[in] Unsigned long integer value that contains the length of the lpszUrl string in TCHAR, or zero if lpszUrl is an ASCIIZ string.

dwFlags
[in] Unsigned long integer value that contains the flags controlling the operation. 

lpUrlComponents
[in, out] Pointer to a URL_COMPONENTS structure that receives the URL components.
  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise.   
***  


## Comments:
There is nothing related to Internet site cracking here.  
  
***  

