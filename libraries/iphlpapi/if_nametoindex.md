<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : if_nametoindex
Group: IP Helper - Library: iphlpapi    
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
```txt  
InterfaceName
A pointer to a NULL-terminated ANSI string containing the interface name.
  
```  
***  


## Return value:
On success, if_nametoindex returns the local interface index. On failure, zero is returned.  
***  


## Comments:
Minimum OS: Vista.  
  
See also: if_indextoname, GetNumberOfInterfaces, GetIfEntry   
  
***  

