<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTcpStatistics
Group: IP Helper - Library: iphlpapi    
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
```txt  
pStats
[out] Pointer to a MIB_TCPSTATS structure that receives the TCP statistics for the local computer.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

