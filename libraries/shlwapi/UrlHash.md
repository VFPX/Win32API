<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UrlHash
Group: Shell Lightweight Utility APIs -- Path Functions - Library: shlwapi    
***  


#### Hashes a URL string.
***  


## Code examples:
[Creating two-byte hashes for a list of URLs](../../samples/sample_180.md)  

## Declaration:
```foxpro  
HRESULT UrlHash(
  LPCTSTR pszURL,
  LPBYTE pbHash,
  DWORD cbHash
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UrlHash IN shlwapi;
	STRING   pszURL,;
	STRING @ pbHash,;
	INTEGER  cbHash  
```  
***  


## Parameters:
```txt  
pszURL
[in] null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

pbHash
[out] Buffer to receive the hashed array.

cbHash
[in] Number of elements in pbHash. It should be no larger than 256.  
```  
***  


## Return value:
Returns S_OK (0) if successful, or a standard OLE error value otherwise.  
***  


## Comments:
See also HashData.  
  
***  

