[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UrlEscape
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Converts characters in a URL that might be altered during transport across the Internet ("unsafe" characters) into their corresponding escape sequences.
***  


## Code examples:
[Converting characters in a URL into corresponding escape sequences and backwards](../../samples/sample_396.md)  

## Declaration:
```foxpro  
HRESULT UrlEscape(
	LPCTSTR pszURL,
	LPTSTR pszEscaped,
	LPDWORD pcchEscaped,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UrlEscape IN shlwapi;
	STRING pszURL, STRING @pszEscaped,;
	INTEGER @pcchEscaped, INTEGER dwFlags
  
```  
***  


## Parameters:
pszURL
[in] Null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains a full or partial URL.

pszEscaped
[out] Buffer that receives the converted string, with the unsafe characters converted to their escape sequences.

pcchEscaped
[in, out] Pointer to a DWORD value containing the number of characters in the pszEscaped buffer.

dwFlags
[in] Flags that indicate which portion of the URL is being provided in pszURL and which characters in that string should be converted to their escape sequences.
  
***  


## Return value:
Returns S_OK (0) if successful.  
***  


## Comments:
See UrlUnescape and InternetCanonicalizeUrl functions.  
  
***  

