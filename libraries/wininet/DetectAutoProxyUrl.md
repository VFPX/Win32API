[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DetectAutoProxyUrl
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Attempts to determine the location of a WPAD autoproxy script.
***  

## Code examples:
[The DetectAutoProxyUrl function identifies the auto-config script location](../../samples/sample_341.md)  

## Declaration:
```foxpro  
BOOL DetectAutoProxyUrl(
	LPSTR lpszAutoProxyUrl,
	DWORD dwAutoProxyUrlLength,
	DWORD dwDetectFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DetectAutoProxyUrl IN wininet;
	STRING @ lpszAutoProxyUrl,;
	LONG     dwAutoProxyUrlLength,;
	LONG     dwDetectFlags  
```  
***  


## Parameters:
lpszAutoProxyUrl 
[in, out] Pointer to a buffer to receive the URL from which a WPAD autoproxy script can be downloaded. 

dwAutoProxyUrlLength 
[in] Size of the buffer pointed to by lpszAutoProxyUrl, in bytes. 

dwDetectFlags 
[in] Automation detection type.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
DetectAutoProxyUrl is called to identify a location (WPAD) from which to obtain the auto-config script. WPAD stands for *Web Proxy Auto-Discovery*.  
  
***  

