<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UrlUnescape
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Converts escape sequences back into ordinary characters.
***  


## Code examples:
[Converting characters in a URL into corresponding escape sequences and backwards](../../samples/sample_396.md)  

## Declaration:
```foxpro  
HRESULT UrlUnescape(
	LPTSTR pszURL,
	LPTSTR pszUnescaped,
	LPDWORD pcchUnescaped,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UrlUnescape IN shlwapi;
	STRING pszURL, STRING @pszUnescaped,;
	INTEGER @pcchUnescaped, INTEGER dwFlags  
```  
***  


## Parameters:
```txt  
pszURL
[in, out] Pointer to a null-terminated string with the URL.

pszUnescaped
[out] Pointer to a buffer that will receive a null-terminated string containing the unescaped version of pszURL.

pcchUnescaped
[in, out] Number of characters in the buffer pointed to by pcchUnescaped.

dwFlags
[in] Flags that control which characters are unescaped.  
```  
***  


## Return value:
Returns an OLE success code if successful.  
***  


## Comments:
See UrlEscape and InternetCanonicalizeUrl functions.  
  
***  

