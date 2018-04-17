[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HttpSendRequest
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### This function sends the specified request to the HTTP server.
***  


## Code examples:
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  

## Declaration:
```foxpro  
BOOL WINAPI HttpSendRequest(
	HINTERNET hRequest,
	LPCTSTR lpszHeaders,
	DWORD dwHeadersLength,
	LPVOID lpOptional,
	DWORD dwOptionalLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HttpSendRequest IN wininet;
	INTEGER hRequest,;
	STRING @lpszHeaders,;
	INTEGER dwHeadersLength,;
	STRING @lpOptional,;
	INTEGER dwOptionalLength
  
```  
***  


## Parameters:
hRequest 
[in] Open HTTP request handle returned by HttpOpenRequest. 

lpszHeaders 
[in] Long pointer to null-terminated strings that contain additional headers to be appended to the request. This parameter can be NULL if there are no additional headers to append. 

dwHeadersLength 
[in] Specifies the length, in characters, of the additional headers. 

lpOptional 
[in] Long pointer to any optional data to send immediately after the request headers. 

dwOptionalLength 
[in] Specifies the length, in bytes, of the optional data.   
***  


## Return value:
TRUE indicates success. FALSE indicates failure.   
***  

## Comments:
See also: [HttpOpenRequest](HttpOpenRequest.md), [InternetQueryDataAvailable](InternetQueryDataAvailable.md), [InternetReadFile](InternetReadFile.md), [InternetCloseHandle](InternetCloseHandle.md).  
  
***  

