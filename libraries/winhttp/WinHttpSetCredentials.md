<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WinHttpSetCredentials
Group: HTTP Functions (WinHTTP) - Library: winhttp    
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
```txt  
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
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise. For extended error information, call GetLastError.  
***  

