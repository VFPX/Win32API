<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WinHttpSendRequest
Group: HTTP Functions (WinHTTP) - Library: winhttp    
***  


#### The WinHttpSendRequest function sends the specified request to the HTTP server.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpSendRequest(
  HINTERNET hRequest,
  LPCWSTR pwszHeaders,
  DWORD dwHeadersLength,
  LPVOID lpOptional,
  DWORD dwOptionalLength,
  DWORD dwTotalLength,
  DWORD_PTR dwContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpSendRequest IN winhttp;
	INTEGER   hRequest,;
	STRING  @ pwszHeaders,;
	INTEGER   dwHdrsLen,;
	STRING  @ lpOptional,;
	INTEGER   dwOptionalLen,;
	INTEGER   dwTotalLen,;
	INTEGER   dwContext
  
```  
***  


## Parameters:
```txt  
hRequest
[in] HINTERNET handle returned by WinHttpOpenRequest.

pwszHeaders
[in] Pointer to a string that contains the additional headers to append to the request.

dwHeadersLength
[in] Unsigned long integer value that contains the length, in characters, of the additional headers.

lpOptional
[in] Pointer to a buffer that contains any optional data to send immediately after the request headers.

dwOptionalLength
[in] Unsigned long integer value that contains the length, in bytes, of the optional data.

dwTotalLength
[in] Unsigned long integer value that contains the length, in bytes, of the total data sent.

dwContext
[in] Pointer to a pointer-sized variable that contains an application-defined value that is passed, along with the request handle, to any callback functions.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

