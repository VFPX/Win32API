[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetInterfaceInfo
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetInterfaceInfo function obtains a list of the network interface adapters on the local system.
***  


## Code examples:
[How to release and renew a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP)](../../samples/sample_349.md)  

## Declaration:
```foxpro  
DWORD GetInterfaceInfo(
	PIP_INTERFACE_INFO pIfTable,
	PULONG dwOutBufLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetInterfaceInfo IN iphlpapi;
	STRING @ pIfTable,;
	LONG   @ dwOutBufLen  
```  
***  


## Parameters:
pIfTable 
[in] Pointer to a buffer that specifies a IP_INTERFACE_INFO structure that contains the list of adapters.

dwOutBufLen 
[out] Pointer to a DWORD variable. If the buffer pointed to by the pIfTable parameter is NULL, or is not large enough to contain the list of adapters, GetInterfaceInfo receives the required size in this DWORD variable.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
Normally this functionality is achieved through <Strong>IPCONFIG /all</Strong> call.  
  
***  

