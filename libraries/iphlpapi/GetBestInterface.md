[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetBestInterface
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Retrieves the index of the interface that has the best route to the specified IPv4 address.
***  


## Declaration:
```foxpro  
DWORD GetBestInterface(
	IPAddr dwDestAddr,
	PDWORD pdwBestIfIndex
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG GetBestInterface IN Iphlpapi;
	LONG dwDestAddr,;
	LONG @pdwBestIfIndex  
```  
***  


## Parameters:
dwDestAddr 
[in] The destination IPv4 address for which to retrieve the interface that has the best route, in the form of an IPAddr structure. 

pdwBestIfIndex 
[out] A pointer to a DWORD variable that receives the index of the interface that has the best route to the IPv4 address specified by dwDestAddr.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
```foxpro
LOCAL nDstIP, nIIndex  
  
nDstIP = inet_addr("66.94.234.13")  
nIIndex=0  
  
IF GetBestInterface(nDstIP, @nIIndex) = 0  
	? "Index of the interface", nIIndex  
ENDIF
```
See also: [GetBestRoute](../iphlpapi/GetBestRoute.md), [GetNumberOfInterfaces](../iphlpapi/GetNumberOfInterfaces.md), [GetIfEntry](../iphlpapi/GetIfEntry.md).  
  
***  

