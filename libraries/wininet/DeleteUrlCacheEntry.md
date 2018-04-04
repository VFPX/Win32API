[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteUrlCacheEntry
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Removes the file associated with the source name from the cache, if the file exists.
***  


## Code examples:
[How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory](../../samples/sample_471.md)  

## Declaration:
```foxpro  
BOOL DeleteUrlCacheEntry(
  LPCTSTR lpszUrlName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteUrlCacheEntry IN wininet;
	STRING lpszUrlName  
```  
***  


## Parameters:
lpszUrlName 
[in] Pointer to a string that contains the name of the source that corresponds to the cache entry.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

