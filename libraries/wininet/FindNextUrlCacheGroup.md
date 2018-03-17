<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindNextUrlCacheGroup
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
hFind
[in] Handle to the cache group enumeration handle, which is returned by FindFirstUrlCacheGroup.

lpGroupId
[out] Pointer to a variable that receives the cache group identifier.

lpReserved
[in, out] Reserved. Must be NULL.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

