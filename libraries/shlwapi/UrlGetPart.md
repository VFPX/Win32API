[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UrlGetPart
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Accepts a URL string and returns a specified part of that URL.
***  


## Code examples:
[Winsock: retrieving Web pages using sockets (HTTP, port 80)](../../samples/sample_383.md)  

## Declaration:
```foxpro  
HRESULT UrlGetPart(
	LPCTSTR pszIn,
	LPTSTR pszOut,
	LPDWORD pcchOut,
	DWORD dwPart,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UrlGetPart IN shlwapi;
	STRING    pszIn,;
	STRING  @ pszOut,;
	INTEGER @ pcchOut,;
	INTEGER   dwPart,;
	INTEGER   dwFlags
  
```  
***  


## Parameters:
pszIn
[in] Null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL. 

pszOut
[out] A buffer that will receive a null-terminated string with the specified part of the URL.

pcchOut
[in, out] Address of a value set to the number of characters in the pszOut buffer. 

dwPart
[in] Flags that specify which part of the URL to retrieve.

dwFlags
[in] Flag that can be set to keep the URL scheme.  
***  


## Return value:
Returns an OLE success code if successful.  
***  

