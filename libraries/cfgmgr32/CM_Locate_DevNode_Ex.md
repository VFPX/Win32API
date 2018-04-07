[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Locate_DevNode_Ex
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [cfgmgr32](../../Libraries.md#cfgmgr32)  
***  


#### Obtains a device instance handle to the device node that is associated with a specified device instance identifier, on a local machine or a remote machine.

***  


## Code examples:
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI
	CM_Locate_DevNode_Ex(
	OUT PDEVINST pdnDevInst,
	IN DEVINSTID pDeviceID,
	OPTIONAL IN ULONG ulFlags,
	IN HMACHINE hMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Locate_DevNode_Ex IN cfgmgr32;
	INTEGER @pdnDevInst,;
	INTEGER pDeviceID,;
	LONG ulFlags,;
	INTEGER hMachine  
```  
***  


## Parameters:
pdnDevInst 
A pointer to the device instance handle that this function retrieves. The retrieved handle is bound to the machine handle specified by hMachine. 

pDeviceID 
A pointer to a NULL-terminated string representing a device instance identifier.

ulFlags 
A variable of ULONG type that supplies one of the predefined flag values.

hMachine 
A machine handle obtained from a call to CM_Connect_Machine, or a machine handle to which a device information set is bound.   
***  


## Return value:
If the operation succeeds, CM_Locate_DevNode returns CR_SUCCESS (0).  
***  


## Comments:
See also: [CM_Connect_Machine](../cfgmgr32/CM_Connect_Machine.md), [CM_Get_Child_Ex](../cfgmgr32/CM_Get_Child_Ex.md), [CM_Get_Sibling_Ex](../cfgmgr32/CM_Get_Sibling_Ex.md).  
  
***  

