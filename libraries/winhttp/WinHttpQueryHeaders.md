[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpQueryHeaders
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpQueryHeaders function retrieves header information associated with an HTTP request.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpQueryHeaders(
  HINTERNET hRequest,
  DWORD dwInfoLevel,
  LPCWSTR pwszName,
  LPVOID lpBuffer,
  LPDWORD lpdwBufferLength,
  LPDWORD lpdwIndex
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpQueryHeaders IN winhttp;
	INTEGER   hRequest,;
	INTEGER   dwInfoLevel,;
	INTEGER   pwszName,;
	STRING  @ lpBuffer,;
	INTEGER @ lpdwBufLen,;
	INTEGER   lpdwIndex
  
```  
***  


## Parameters:
hRequest 
[in] HINTERNET request handle returned by WinHttpOpenRequest.

dwInfoLevel 
[in] Value of type DWORD that specifies a combination of attribute and modifier flags.

pwszName 
[in, optional] Pointer to a string that contains the header name. 

lpBuffer 
[out] Pointer to the buffer that receives the information. 

lpdwBufferLength 
[in, out] Pointer to a value of type DWORD that specifies the length of the data buffer, in bytes.

lpdwIndex 
[in, out] Pointer to a zero-based header index used to enumerate multiple headers with the same name.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise. To get extended error information, call GetLastError.  
***  

