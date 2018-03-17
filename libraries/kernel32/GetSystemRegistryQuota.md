<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetSystemRegistryQuota
Group: System Information - Library: kernel32    
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
```txt  
pdwQuotaAllowed [out, optional]
A pointer to a variable that receives the maximum size that the registry is allowed to attain on this system, in bytes.

pdwQuotaUsed [out, optional]
A pointer to a variable that receives the current size of the registry, in bytes.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

