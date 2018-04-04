[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUrlCacheEntryInfo
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves information about a cache entry.
***  


## Code examples:
[How to retrieve information about a cache entry (Internet Explorer)](../../samples/sample_332.md)  

## Declaration:
```foxpro  
BOOL GetUrlCacheEntryInfo(
	LPCTSTR lpszUrlName,
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntryInfo,
	LPDWORD lpdwCacheEntryInfoBufferSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUrlCacheEntryInfo IN wininet;
	STRING    lpszUrlName,;
	STRING  @ lpCacheEntryInfo,;
	INTEGER @ lpdwCacheEntryInfoBufferSize  
```  
***  


## Parameters:
lpszUrlName
[in] Pointer to a string that contains the name of the cache entry.

lpCacheEntryInfo
[in] Pointer to an INTERNET_CACHE_ENTRY_INFO structure that receives information about the cache entry.

lpdwCacheEntryInfoBufferSize
[in, out] Pointer to an unsigned long integer variable that specifies the size of the lpCacheEntryInfo buffer, in bytes.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
Use local cache file to access dwonloaded pages offline.  
  
***  

