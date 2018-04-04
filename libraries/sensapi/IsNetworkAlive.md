[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsNetworkAlive
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [sensapi](../../Libraries.md#sensapi)  
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
lpdwFlags 
[out] Provides information on the type of network connection available when the return value is TRUE.  
***  


## Return value:
Returns True if the local system is connected to a network.   
***  

