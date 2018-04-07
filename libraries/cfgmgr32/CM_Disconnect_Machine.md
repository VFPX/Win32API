[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Disconnect_Machine
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [cfgmgr32](../../Libraries.md#cfgmgr32)  
***  


#### Removes a connection to a remote machine established in a previous call to CM_Connect_Machine.
***  


## Code examples:
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI
	CM_Disconnect_Machine(
	IN HMACHINE hMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Disconnect_Machine IN cfgmgr32;
	INTEGER hMachine
  
```  
***  


## Parameters:
hMachine 
Caller-supplied machine handle, obtained from a previous call to CM_Connect_Machine.  
***  


## Return value:
If the operation succeeds, the function returns CR_SUCCESS (0).  
***  


## Comments:
See also: [CM_Connect_Machine](../cfgmgr32/CM_Connect_Machine.md).  
  
***  

