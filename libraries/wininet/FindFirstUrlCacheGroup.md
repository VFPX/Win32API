[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindFirstUrlCacheGroup
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Initiates the enumeration of the cache groups in the Internet cache.
***  


## Code examples:
[How to enumerate cookies and URL History entries in the cache of the local computer](../../samples/sample_350.md)  

## Declaration:
```foxpro  
HANDLE FindFirstUrlCacheGroup(
  DWORD dwFlags,
  DWORD dwFilter,
  LPVOID lpSearchCondition,
  DWORD dwSearchCondition,
  GROUPID* lpGroupId,
  LPVOID lpReserved
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindFirstUrlCacheGroup In wininet;
	LONG      dwFlags,;
	LONG      dwFilter,;
	LONG      lpSearchCond,;
	LONG      dwSearchCond,;
	STRING  @ lpGroupId,;
	INTEGER @ lpReserved
  
```  
***  


## Parameters:
dwFlags 
[in] Reserved. Must be zero. 

dwFilter 
[in] Filters to be used. 

lpSearchCondition 
[in] Reserved. Must be NULL. 

dwSearchCondition 
[in] Reserved. Must be zero. 

lpGroupId 
[out] Pointer to the ID of the first cache group that matches the search criteria. 

lpReserved 
[in, out] Reserved. Must be NULL.   
***  


## Return value:
Returns a valid handle if successful, or NULL otherwise. To get specific error information, call GetLastError. If the function finds no matching files, GetLastError returns ERROR_NO_MORE_FILES.  
***  

