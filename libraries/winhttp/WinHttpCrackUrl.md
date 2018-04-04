[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpCrackUrl
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpCrackUrl function separates a URL into its component parts such as host name and path.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpCrackUrl(
  LPCWSTR pwszUrl,
  DWORD dwUrlLength,
  DWORD dwFlags,
  LPURL_COMPONENTS lpUrlComponents
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpCrackUrl IN winhttp;
	STRING    pwszUrl,;
	INTEGER   dwUrlLength,;
	INTEGER   dwFlags,;
	STRING  @ lpUrlComponents
  
```  
***  


## Parameters:
pwszUrl 
[in] Pointer to a LPCWSTR that contains the canonical URL to separate.

dwUrlLength 
[in] Value of type DWORD that contains the length of the pwszUrl string, in WCHARs.

dwFlags 
[in] Value of type DWORD that contains the flags that control the operation.

lpUrlComponents 
[in, out] Pointer to a URL_COMPONENTS structure that receives the URL components.
  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise.  
***  


## Comments:
For WinHttpCrackUrl to work properly, the size of the URL_COMPONENTS structure must be stored in the dwStructSize member of that structure.  
  
***  

