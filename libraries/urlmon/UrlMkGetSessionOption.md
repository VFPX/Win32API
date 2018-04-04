[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UrlMkGetSessionOption
Group: [URL Monikers](../../functions_group.md#URL_Monikers)  -  Library: [urlmon](../../Libraries.md#urlmon)  
***  


#### Retrieves options for the current Internet session.
***  


## Code examples:
[Obtaining current Internet Explorer browser version and UserAgent](../../samples/sample_142.md)  

## Declaration:
```foxpro  
HRESULT UrlMkGetSessionOption(
	DWORD dwOption,
	LPVOID pBuffer,
	DWORD dwBufferLength,
	DWORD *pdwBufferLength,
	DWORD dwReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UrlMkGetSessionOption IN urlmon;
	INTEGER   dwOption,;
	STRING  @ pBuffer,;
	INTEGER   dwBufferLen,;
	INTEGER @ pdwBufferLen,;
	INTEGER   dwReserved
  
```  
***  


## Parameters:
dwOption
[in] Unsigned long integer value containing the session options to be retrieved.

pBuffer
[in] Pointer to the buffer containing the session settings to be retrieved. 

dwBufferLength
[in] Unsigned long integer value containing the size of pBuffer. 

pdwBufferLength
[out] Pointer to an unsigned long integer value containing the size of the data stored in the buffer or the size required to store the data if the buffer size was insufficient. 

dwReserved
[in] Reserved. Must be set to 0.
  
***  


## Return value:
Returns one of the following values: S_OK, E_FAIL, E_INVALIDARG  
***  


## Comments:
Being called with dwOption = URLMON_OPTION_USERAGENT this function returns current User Agent string.  
  
Even if this function returns an error code, check <Strong>pdwBufferLength</Strong> parameter. If it is not zero then there is some result returned in <Strong>pBuffer</Strong>.  
  
***  

