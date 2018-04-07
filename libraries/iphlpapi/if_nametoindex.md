[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : if_nametoindex
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Converts the ANSI interface name for a network interface to the local index for the interface.
***  


## Declaration:
```foxpro  
NET_IFINDEX WINAPI if_nametoindex(
  __in  PCSTR InterfaceName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER if_nametoindex IN Iphlpapi;
	STRING InterfaceName  
```  
***  


## Parameters:
InterfaceName 
A pointer to a NULL-terminated ANSI string containing the interface name.
  
***  


## Return value:
On success, if_nametoindex returns the local interface index. On failure, zero is returned.  
***  


## Comments:
Minimum OS: Vista.  
  
See also: [if_indextoname](../iphlpapi/if_indextoname.md), [GetNumberOfInterfaces](../iphlpapi/GetNumberOfInterfaces.md), [GetIfEntry](../iphlpapi/GetIfEntry.md).  
  
***  

