[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UrlUnescape
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
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
pszURL
[in, out] Pointer to a null-terminated string with the URL. 

pszUnescaped
[out] Pointer to a buffer that will receive a null-terminated string containing the unescaped version of pszURL.

pcchUnescaped
[in, out] Number of characters in the buffer pointed to by pcchUnescaped.

dwFlags
[in] Flags that control which characters are unescaped.   
***  


## Return value:
Returns an OLE success code if successful.  
***  


## Comments:
See also: [UrlEscape](UrlEscape.md) and [InternetCanonicalizeUrl](../wininet/InternetCanonicalizeUrl.md) functions.  
  
***  

