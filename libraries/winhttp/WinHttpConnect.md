[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpConnect
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### Specifies the initial target server of an HTTP request and returns an HINTERNET connection handle to an HTTP session for that initial target.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
HINTERNET WinHttpConnect(
  HINTERNET hSession,
  LPCWSTR pswzServerName,
  INTERNET_PORT nServerPort,
  DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpConnect IN winhttp;
	INTEGER hSession,;
	STRING  pswzServerName,;
	INTEGER nServerPort,;
	INTEGER dwReserved
  
```  
***  


## Parameters:
hSession 
[in] Valid HINTERNET WinHTTP session handle returned by a previous call to WinHttpOpen. 

pswzServerName 
[in] Pointer to a null-terminated string that contains the host name of an HTTP server.

nServerPort 
[in] Unsigned integer that specifies the TCP/IP port on the server to which a connection is made.

dwReserved 
[in] Reserved. Must be zero.
  
***  


## Return value:
Returns a valid connection handle to the HTTP session if the connection is successful, or NULL otherwise.  
***  


## Comments:
MSDN: After the calling application has finished using the HINTERNET handle returned by WinHttpConnect, it must be closed using the WinHttpCloseHandle function.  
  
WinHttpConnect specifies the target HTTP server, however a response can come from another server if the request was redirected. You can determine the URL of the server sending the response by calling WinHttpQueryOption with the WINHTTP_OPTION_URL flag.  
  
***  

