[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindNextUrlCacheGroup
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves the next cache group in a cache group enumeration started by FindFirstUrlCacheGroup.
***  


## Code examples:
[How to enumerate cookies and URL History entries in the cache of the local computer](../../samples/sample_350.md)  

## Declaration:
```foxpro  
BOOL FindNextUrlCacheGroup(
  HANDLE hFind,
  GROUPID* lpGroupId,
  LPVOID lpReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextUrlCacheGroup IN wininet;
	INTEGER   hFind,;
	STRING  @ lpGroupId,;
	INTEGER @ lpReserved
  
```  
***  


## Parameters:
hFind 
[in] Handle to the cache group enumeration handle, which is returned by FindFirstUrlCacheGroup. 

lpGroupId 
[out] Pointer to a variable that receives the cache group identifier. 

lpReserved 
[in, out] Reserved. Must be NULL.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

