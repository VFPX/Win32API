<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindNextUrlCacheEntry
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Retrieves the next entry in the Internet cache.
***  


## Code examples:
[How to enumerate cookies and URL History entries in the cache of the local computer](../../samples/sample_350.md)  
[How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory](../../samples/sample_471.md)  

## Declaration:
```foxpro  
BOOL FindNextUrlCacheEntry(
  HANDLE hEnumHandle,
  LPINTERNET_CACHE_ENTRY_INFO lpNextCacheEntryInfo,
  LPWORD lpdwNextCacheEntryInfoBufferSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextUrlCacheEntry IN wininet;
	INTEGER hEnumHandle,;
	LONG    lpNextCacheEntryInfo,;
	LONG  @ lpdwNextCacheEntryInfoBufferSize
  
```  
***  


## Parameters:
```txt  
hEnumHandle
[in] Handle to the enumeration obtained from a previous call to FindFirstUrlCacheEntry.

lpNextCacheEntryInfo
[out] Pointer to an INTERNET_CACHE_ENTRY_INFO structure that receives information about the cache entry.

lpdwNextCacheEntryInfoBufferSize
[in, out] Pointer to a variable that specifies the size of the lpNextCacheEntryInfo buffer.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  

