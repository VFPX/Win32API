[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpSetCredentials
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpSetCredentials function passes the required authorization credentials to the server.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpSetCredentials(
  HINTERNET hRequest,
  DWORD AuthTargets,
  DWORD AuthScheme,
  LPCWSTR pwszUserName,
  LPCWSTR pwszPassword,
  LPVOID pAuthParams
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpSetCredentials IN winhttp;
	INTEGER hRequest,;
	INTEGER AuthTargets,;
	INTEGER AuthScheme,;
	STRING  pwszUserName,;
	STRING  pwszPassword,;
	INTEGER pAuthParams
  
```  
***  


## Parameters:
hRequest 
[in] Valid HINTERNET handle returned by WinHttpOpenRequest. 

AuthTargets 
[in] An unsigned integer that specifies a flag that contains the authentication target.

AuthScheme 
[in] An unsigned integer that specifies a flag that contains the authentication scheme.

pwszUserName 
[in] Pointer to a string that contains a valid user name. 

pwszPassword 
[in] Pointer to a string that contains a valid password. The password can be blank. 

pAuthParams 
[in] Reserved. Must be NULL.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise. For extended error information, call GetLastError.  
***  

