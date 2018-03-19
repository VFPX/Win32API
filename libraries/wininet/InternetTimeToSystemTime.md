
## Function name : InternetTimeToSystemTime
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Converts an HTTP time/date string to a SYSTEMTIME structure.
***  


## Code examples:
[Converting an HTTP time/date string to a SYSTEMTIME structure](../../samples/sample_328.md)  

## Declaration:
```foxpro  
BOOL InternetTimeToSystemTime(
	LPCTSTR lpszTime,
	SYSTEMTIME* pst,
	DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetTimeToSystemTime IN wininet;
	STRING    lpszTime,;
	STRING  @ pst,;
	INTEGER   dwReserved
  
```  
***  


## Parameters:
lpszTime
[in] Pointer to a null-terminated date/time string to convert.

pst
[out] Pointer to a SYSTEMTIME structure that receives the converted time.

dwReserved
[in] Reserved. Must be set to 0.  
***  


## Return value:
Returns TRUE if the string was converted, or FALSE otherwise.  
***  

