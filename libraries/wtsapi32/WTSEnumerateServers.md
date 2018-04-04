[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSEnumerateServers
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
***  


#### Returns a list of all terminal servers within the specified Windows NT domain.

***  


## Code examples:
[How to enumerate terminal servers within the specified Windows domain](../../samples/sample_520.md)  

## Declaration:
```foxpro  
BOOL WTSEnumerateServers(
	LPTSTR pDomainName,
	DWORD Reserved,
	DWORD Version,
	PWTS_SERVER_INFO* ppServerInfo,
	DWORD* pCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSEnumerateServers IN Wtsapi32;
	STRING pDomainName,;
	LONG Reserved,;
	LONG RqVersion,;
	LONG @ppServerInfo,;
	LONG @SICount  
```  
***  


## Parameters:
pDomainName 
[in] Pointer to the name of the Windows NT domain to be queried. 

Reserved 
[in] Reserved. The value of this parameter must be 0. 

Version 
[in] Version of the enumeration request. The value of the parameter must be 1. 

ppServerInfo 
Points to an array of WTS_SERVER_INFO structures, which contains the returned results of the enumeration.

pCount 
Pointer to a variable that receives the number of WTS_SERVER_INFO structures returned in the ppServerInfo buffer.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
If <Em>pDomainName</Em> is NULL, the specified domain is the current domain.   
  
After use, the memory used by <Em>ppServerInfo</Em> should be freed by calling WTSFreeMemory.   
  
***  

