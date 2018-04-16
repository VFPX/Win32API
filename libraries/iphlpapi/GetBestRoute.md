[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetBestRoute
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Retrieves the best route to the specified destination IP address.

***  


## Declaration:
```foxpro  
DWORD GetBestRoute(
	DWORD dwDestAddr,
	DWORD dwSourceAddr,
	PMIB_IPFORWARDROW pBestRoute
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG GetBestRoute IN Iphlpapi;
	LONG dwDestAddr,;
	LONG dwSourceAddr,;
	INTEGER pBestRoute  
```  
***  


## Parameters:
dwDestAddr 
[in] Destination IP address for which to obtain the best route. 

dwSourceAddr 
[in] Source IP address. This IP address corresponds to an interface on the local computer.

pBestRoute 
[out] Pointer to a MIB_IPFORWARDROW structure containing the best route for the IP address specified by dwDestAddr.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
```foxpro
#DEFINE MIB_IPFORWARDROW_SIZE 56  
  
nSrcIP = inet_addr("192.168.0.200")  
nDstIP = inet_addr("66.94.234.13")  
  
oBuffer = CREATEOBJECT("PChar",;  
	REPLICATE(CHR(0), MIB_IPFORWARDROW_SIZE))  
  
IF GetBestRoute(nDstIP, nSrcIP, oBuffer.GetAddr()) <> 0  
	? "GetBestRoute failed with error code:",;  
		GetLastError()  
	RETURN  
ENDIF  
  
cBuffer = oBuffer.GetValue()  
nHopIP = buf2dword(SUBSTR(cBuffer, 13, 4))  
? inet_ntoa(nSrcIP)
```

See also: [GetBestInterface](../iphlpapi/GetBestInterface.md).  
  
***  

