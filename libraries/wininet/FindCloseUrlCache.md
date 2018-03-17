<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindCloseUrlCache
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Closes the specified cache enumeration handle.
***  


## Code examples:
[How to enumerate cookies and URL History entries in the cache of the local computer](../../samples/sample_350.md)  
[How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory](../../samples/sample_471.md)  

## Declaration:
```foxpro  
BOOL FindCloseUrlCache(
  HANDLE hEnumHandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindCloseUrlCache IN wininet;
	INTEGER hEnumHandle  
```  
***  


## Parameters:
```txt  
hEnumHandle
[in] Handle returned by a previous call to the FindFirstUrlCacheEntry function.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  

