[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetIpStatistics
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetIpStatistics function retrieves the IP statistics for the current computer.
***  


## Code examples:
[Retrieving IP statistics for the computer](../../samples/sample_248.md)  

## Declaration:
```foxpro  
DWORD GetIpStatistics(
  PMIB_IPSTATS pStats  // pointer to IP stats
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetIpStatistics IN iphlpapi;
	STRING @ pStats  
```  
***  


## Parameters:
pStats 
[out] Pointer to a MIB_IPSTATS structure that receives the IP statistics for the local computer.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the function fails, use FormatMessage to obtain the message string for the returned error.  
***  

