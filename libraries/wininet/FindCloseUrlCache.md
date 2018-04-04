[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindCloseUrlCache
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
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
hEnumHandle 
[in] Handle returned by a previous call to the FindFirstUrlCacheEntry function.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.   
***  

