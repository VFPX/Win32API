[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpOpenRequest
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpOpenRequest function creates an HTTP request handle.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
HINTERNET WinHttpOpenRequest(
  HINTERNET hConnect,
  LPCWSTR pwszVerb,
  LPCWSTR pwszObjectName,
  LPCWSTR pwszVersion,
  LPCWSTR pwszReferrer,
  LPCWSTR* ppwszAcceptTypes,
  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpOpenRequest IN winhttp;
	INTEGER hConnect,;
	STRING  pwszVerb,;
	STRING  pwszObjName,;
	STRING  pwszVersion,;
	INTEGER pwszReferrer,;
	INTEGER ppwszAcceptTypes,;
	INTEGER dwFlags
  
```  
***  


## Parameters:
hConnect 
[in] HINTERNET connection handle to an HTTP session returned by WinHttpConnect. 

pwszVerb 
[in] Pointer to a string that contains the HTTP verb to use in the request.

pwszObjectName 
[in] Pointer to a string that contains the name of the target resource of the specified HTTP verb.

pwszVersion 
[in] Pointer to a string that contains the HTTP version. If this parameter is NULL, the function uses HTTP/1.1. 

pwszReferrer 
[in] Pointer to a string that specifies the URL of the document from which the URL in the request pwszObjectName was obtained.

ppwszAcceptTypes 
[in] Pointer to a null-terminated array of string pointers that specifies media types accepted by the client.

dwFlags 
[in] Unsigned long integer value that contains the Internet flag values.  
***  


## Return value:
Returns a valid HTTP request handle if successful, or NULL if not.  
***  


## Comments:
MSDN: After the calling application finishes using the HINTERNET handle returned by WinHttpOpenRequest, it must be closed using the WinHttpCloseHandle function.  
  
***  

