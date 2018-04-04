[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTcpStatistics
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetTcpStatistics function retrieves the TCP statistics for the local computer.
***  


## Code examples:
[Retrieving statistics for the TCP protocol running on the local computer](../../samples/sample_231.md)  

## Declaration:
```foxpro  
DWORD GetTcpStatistics(
  PMIB_TCPSTATS pStats  // pointer to TCP stats
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTcpStatistics IN iphlpapi;
	STRING @ pStats  
```  
***  


## Parameters:
pStats 
[out] Pointer to a MIB_TCPSTATS structure that receives the TCP statistics for the local computer.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

