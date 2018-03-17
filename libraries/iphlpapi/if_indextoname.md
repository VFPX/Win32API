<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : if_indextoname
Group: IP Helper - Library: iphlpapi    
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
```txt  
InterfaceIndex
The local index for a network interface.

InterfaceName
A pointer to a buffer to hold the NULL-terminated ANSI string containing the interface name when the function returns successfully.
  
```  
***  


## Return value:
On success, if_indextoname returns a pointer to NULL-terminated ANSI string containing the interface name.  
***  


## Comments:
Minimum OS: Vista.  
  
See also: if_nametoindex, GetNumberOfInterfaces, GetIfEntry   
  
***  

