<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetNetworkParams
Group: IP Helper - Library: iphlpapi    
***  


#### The GetNetworkParams function retrieves network parameters for the local computer.
***  


## Code examples:
[How to retrieve network parameters for the local computer (including Host name, Domain name, and DNS Server)](../../samples/sample_348.md)  

## Declaration:
```foxpro  
DWORD GetNetworkParams(
	PFIXED_INFO pFixedInfo,
	PULONG pOutBufLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNetworkParams IN iphlpapi;
	STRING @ pFixedInfo,;
	LONG   @ pOutBufLen  
```  
***  


## Parameters:
```txt  
pFixedInfo
[out] Pointer to a FIXED_INFO structure that receives the network parameters for the local computer.

pOutBufLen
[in] Pointer to a ULONG variable that specifies the size of the FIXED_INFO structure.  
```  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is one of predefined error codes.
  
***  

