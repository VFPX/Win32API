<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetCanonicalizeUrl
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.
***  


## Code examples:
[URL: converting unsafe characters and spaces into escape sequences](../../samples/sample_183.md)  

## Declaration:
```foxpro  
BOOL InternetCanonicalizeUrl(
	LPCTSTR lpszUrl,
	LPTSTR lpszBuffer,
	LPDWORD lpdwBufferLength,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetCanonicalizeUrl IN wininet;
	STRING    lpszUrl,;
	STRING  @ lpszBuffer,;
	INTEGER @ lpdwBufferLength,;
	INTEGER   dwFlags  
```  
***  


## Parameters:
```txt  
lpszUrl
[in] Pointer to the string that contains the URL to canonicalize.

lpszBuffer
[out] Pointer to the buffer that receives the resulting canonicalized URL.

lpdwBufferLength
[in, out] Pointer to an unsigned long integer value that contains the length, in bytes, of the lpszBuffer buffer.

dwFlags
[in] Unsigned long integer value that contains the flags that control canonicalization.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  


## Comments:
If no flags are specified (dwFlags = 0), the function converts all unsafe characters and meta sequences (such as \.,\ .., and \...) to escape sequences.   
  
See UrlEscape and UrlUnescape functions.  
  
***  

