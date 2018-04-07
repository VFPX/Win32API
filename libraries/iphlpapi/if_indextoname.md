[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : if_indextoname
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Converts the local index for a network interface to the ANSI interface name.
***  


## Declaration:
```foxpro  
PCHAR WINAPI if_indextoname(
  __in   NET_IFINDEX InterfaceIndex,
  __out  PCHAR InterfaceName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER if_indextoname IN Iphlpapi;
	INTEGER InterfaceIndex,;
	STRING @InterfaceName  
```  
***  


## Parameters:
InterfaceIndex 
The local index for a network interface.

InterfaceName 
A pointer to a buffer to hold the NULL-terminated ANSI string containing the interface name when the function returns successfully.
  
***  


## Return value:
On success, if_indextoname returns a pointer to NULL-terminated ANSI string containing the interface name.  
***  


## Comments:
Minimum OS: Vista.  
  
See also: [if_nametoindex](../iphlpapi/if_nametoindex.md), [GetNumberOfInterfaces](../iphlpapi/GetNumberOfInterfaces.md), [GetIfEntry](../iphlpapi/GetIfEntry.md).  
  
***  

