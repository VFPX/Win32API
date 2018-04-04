[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemRegistryQuota
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the current size of the registry and the maximum size that the registry is allowed to attain on the system.
***  


## Declaration:
```foxpro  
BOOL WINAPI GetSystemRegistryQuota(
  __out_opt  PDWORD pdwQuotaAllowed,
  __out_opt  PDWORD pdwQuotaUsed
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemRegistryQuota IN kernel32;
	LONG @pdwQuotaAllowed,;
	LONG @pdwQuotaUsed
  
```  
***  


## Parameters:
pdwQuotaAllowed [out, optional] 
A pointer to a variable that receives the maximum size that the registry is allowed to attain on this system, in bytes.

pdwQuotaUsed [out, optional] 
A pointer to a variable that receives the current size of the registry, in bytes.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

