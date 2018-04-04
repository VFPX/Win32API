[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IpRenewAddress
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
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
AdapterInfo 
[in] Pointer to an IP_ADAPTER_INDEX_MAP structure that specifies the adapter associated with the IP address to renew. 
  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
Normally this functionality is achieved through <Strong>IPCONFIG /renew</Strong> call.  
  
***  

