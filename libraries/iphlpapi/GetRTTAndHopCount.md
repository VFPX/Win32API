[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetRTTAndHopCount
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetRTTAndHopCount function determines the round-trip time (RTT) and hop count to the specified destination.
***  


## Code examples:
[How to ping a remote site using IP Helper API calls](../../samples/sample_382.md)  

## Declaration:
```foxpro  
BOOL GetRTTAndHopCount(
  IPAddr DestIpAddress,
  PULONG HopCount,
  ULONG MaxHops,
  PULONG RTT
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetRTTAndHopCount IN Iphlpapi;
	INTEGER   DestIpAddress,;
	LONG    @ HopCount,;
	INTEGER   MaxHops,;
	LONG    @ RTT
  
```  
***  


## Parameters:
DestIpAddress 
[in] IP address of the destination for which to determine the RTT and hop count. 

HopCount 
[out] This variable receives the hop count to the destination specified by the DestIpAddress parameter. 

MaxHops 
[in] Maximum number of hops to search for the destination. 

RTT 
[out] Round-trip time, in milliseconds, to the destination specified by DestIpAddress.   
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
To convert an IP address between dotted decimal notation and IPAddr format, use the inet_addr and inet_ntoa functions.  
  
***  

