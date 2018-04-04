[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpOpen
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### Initializes an application"s use of the WinHTTP functions and returns a WinHTTP-session handle.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
HINTERNET WinHttpOpen(
  LPCWSTR pwszUserAgent,
  DWORD dwAccessType,
  LPCWSTR pwszProxyName,
  LPCWSTR pwszProxyBypass,
  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpOpen IN winhttp;
	STRING  pwszUserAgent,;
	INTEGER dwAccessType,;
	STRING  pwszProxy,;
	STRING  pwszProxyBypass,;
	INTEGER dwFlags
  
```  
***  


## Parameters:
pwszUserAgent 
[in] Pointer to a string variable that contains the name of the application or entity calling the WinHTTP functions.

dwAccessType 
[in] Type of access required -- a predefined value.

pwszProxyName 
[in] Pointer to a string variable that contains the name of the proxy server to use.

pwszProxyBypass 
[in] Pointer to a string variable that contains an optional list of host names or Internet Protocol (IP) addresses.

dwFlags 
[in] Unsigned long integer value that contains the flags that indicate various options affecting the behavior of this function.  
***  


## Return value:
Returns a valid session handle if successful, or NULL if not.  
***  


## Comments:
MSDN: The WinHttpOpen function is the first of the WinHTTP functions called by an application. It initializes internal WinHTTP data structures and prepares for future calls from the application.   
  
When the application finishes using the WinHTTP functions, it must call WinHttpCloseHandle to free the session handle and any associated resources.  
  
***  

