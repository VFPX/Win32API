<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetIpStatistics
Group: IP Helper - Library: iphlpapi    
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
```txt  
pStats
[out] Pointer to a MIB_IPSTATS structure that receives the IP statistics for the local computer.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the function fails, use FormatMessage to obtain the message string for the returned error.  
***  

