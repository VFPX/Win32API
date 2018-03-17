<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsNetworkAlive
Group: System Information - Library: sensapi    
***  


#### The IsNetworkAlive function determines whether the local system is connected to a network and the type of network connection. For example, whether the local system has connectivity to a LAN, WAN, or both networks.
***  


## Code examples:
[Determining if an Active Network Connection is Available](../../samples/sample_324.md)  

## Declaration:
```foxpro  
Bool IsNetworkAlive(
  LPDWORD lpdwFlags  // Specifies the type of network connection
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsNetworkAlive IN sensapi;
	INTEGER @ lpdwFlags  
```  
***  


## Parameters:
```txt  
lpdwFlags
[out] Provides information on the type of network connection available when the return value is TRUE.  
```  
***  


## Return value:
Returns True if the local system is connected to a network.   
***  

