<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetTimeFromSystemTime
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Formats a date and time according to the HTTP version 1.0 specification.
***  


## Code examples:
[Converting an HTTP time/date string to a SYSTEMTIME structure](../../samples/sample_328.md)  
[How to retrieve information about a cache entry (Internet Explorer)](../../samples/sample_332.md)  

## Declaration:
```foxpro  
BOOL InternetTimeFromSystemTime(	const SYSTEMTIME* pst,
	DWORD dwRFC,
	LPTSTR lpszTime,
	DWORD cbTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetTimeFromSystemTime IN wininet;
	STRING  @ pst,;
	INTEGER   dwRFC,;
	STRING  @ lpszTime,;
	INTEGER   cbTime
  
```  
***  


## Parameters:
```txt  
pst
[in] Pointer to a SYSTEMTIME structure that contains the date and time to format.

dwRFC
[in] Unsigned long integer value that contains the RFC format used. Currently, the only valid format is INTERNET_RFC1123_FORMAT.

lpszTime
[out] Pointer to a string buffer that receives the formatted date and time. The buffer should be of size INTERNET_RFC1123_BUFSIZE.

cbTime
[in] Unsigned long integer value that contains the size, in bytes, of the lpszTime buffer.  
```  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise.  
***  

