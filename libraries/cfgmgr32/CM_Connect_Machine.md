[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Connect_Machine
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [cfgmgr32](../../Libraries.md#cfgmgr32)  
***  


#### Creates a connection to a remote machine
***  


## Code examples:
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI
	CM_Connect_Machine(
	IN PCTSTR UNCServerName,
	OUT PHMACHINE phMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Connect_Machine IN cfgmgr32;
	STRING UNCServerName,;
	INTEGER @phMachine  
```  
***  


## Parameters:
UNCServerName 
Caller-supplied pointer to a text string representing the UNC name, including the \\ prefix, of the system for which a connection will be made. If the pointer is NULL, the local system is used. 

phMachine 
Address of a location to receive a machine handle.  
***  


## Return value:
If the operation succeeds, the function returns CR_SUCCESS (0).  
***  


## Comments:
Callers of CM_Connect_Machine must call CM_Disconnect_Machine to deallocate the machine handle, after it is no longer needed.  
  
Use machine handles obtained with this function only with the PnP configuration manager functions.  
  
***  

