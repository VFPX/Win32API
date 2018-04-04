[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HttpOpenRequest
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### This function opens an HTTP request handle.
***  


## Code examples:
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  

## Declaration:
```foxpro  
HINTERNET WINAPI HttpOpenRequest(
	HINTERNET hConnect,
	LPCTSTR lpszVerb,
	LPCTSTR lpszObjectName,
	LPCTSTR lpszVersion,
	LPCTSTR lpszReferrer,
	LPCTSTR *lplpszAcceptTypes,
	DWORD dwFlags,
	DWORD dwContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HttpOpenRequest IN wininet;
	INTEGER hConnect,;
	STRING  lpszVerb,;
	STRING  lpszObjectName,;
	STRING  lpszVersion,;
	STRING  lpszReferer,;
	INTEGER lpszAcceptTypes,;
	INTEGER dwFlags,;
	INTEGER dwContext  
```  
***  


## Parameters:
hConnect 
[in] Handle to an HTTP session returned by InternetConnect. 

lpszVerb 
[in] Long pointer to a null-terminated string that contains the verb to use in the request. 

lpszObjectName 
[in] Long pointer to a null-terminated string that contains the name of the target object of the specified verb: GET, POST

lpszVersion 
[in] Long pointer to a null-terminated string that contains the HTTP version. 

lpszReferrer 
[in] Long pointer to a null-terminated string that specifies the address (URL) of the document from which the URL in the request (lpszObjectName) was obtained. 

lplpszAcceptTypes 
[in] Long pointer to a null-terminated array of string pointers indicating content types accepted by the client. 

dwFlags 
[in] Specifies a bitmask of Internet flags. 

dwContext 
[in] Specifies the application-defined value that associates this operation with any application data.   
***  


## Return value:
A valid, non-NULL HTTP request handle indicates success. NULL indicates failure.  
***  

