<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DeleteUrlCacheEntry
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
lpszUrlName
[in] Pointer to a string that contains the name of the source that corresponds to the cache entry.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

