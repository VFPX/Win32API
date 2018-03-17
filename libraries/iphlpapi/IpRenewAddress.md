<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IpRenewAddress
Group: IP Helper - Library: iphlpapi    
***  


#### The IpRenewAddress function renews a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP).
***  


## Code examples:
[How to release and renew a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP)](../../samples/sample_349.md)  

## Declaration:
```foxpro  
DWORD IpRenewAddress(
	PIP_ADAPTER_INDEX_MAP AdapterInfo
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IpRenewAddress IN iphlpapi;
	STRING @ AdapterInfo  
```  
***  


## Parameters:
```txt  
AdapterInfo
[in] Pointer to an IP_ADAPTER_INDEX_MAP structure that specifies the adapter associated with the IP address to renew.
  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
Normally this functionality is achieved through <Strong>IPCONFIG /renew</Strong> call.  
  
***  

