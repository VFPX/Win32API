
## Function name : WinHttpAddRequestHeaders
Group: HTTP Functions (WinHTTP) - Library: winhttp    
***  


#### The WinHttpAddRequestHeaders function adds one or more HTTP request headers to the HTTP request handle.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpAddRequestHeaders(
  HINTERNET hRequest,
  LPCWSTR pwszHeaders,
  DWORD dwHeadersLength,
  DWORD dwModifiers
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpAddRequestHeaders IN winhttp;
	INTEGER hRequest,;
	STRING  pwszHeaders,;
	INTEGER dwHeadersLength,;
	INTEGER dwModifiers
  
```  
***  


## Parameters:
hRequest 
[in] HINTERNET handle returned by a call to the WinHttpOpenRequest function.

pwszHeaders 
[in] Pointer to a string variable that contains the headers to append to the request.

dwHeadersLength 
[in] Unsigned long integer value that contains the length, in bytes, of pwszHeaders.

dwModifiers 
[in] Unsigned long integer value that contains the flags used to modify the semantics of this function.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise. For extended error information, call GetLastError.   
***  

