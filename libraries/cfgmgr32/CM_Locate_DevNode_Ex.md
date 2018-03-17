<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CM_Locate_DevNode_Ex
Group: PnP Configuration Manager - Library: cfgmgr32    
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
```txt  
pdnDevInst
A pointer to the device instance handle that this function retrieves. The retrieved handle is bound to the machine handle specified by hMachine.

pDeviceID
A pointer to a NULL-terminated string representing a device instance identifier.

ulFlags
A variable of ULONG type that supplies one of the predefined flag values.

hMachine
A machine handle obtained from a call to CM_Connect_Machine, or a machine handle to which a device information set is bound.  
```  
***  


## Return value:
If the operation succeeds, CM_Locate_DevNode returns CR_SUCCESS (0).  
***  


## Comments:
See also: CM_Connect_Machine, CM_Get_Child_Ex, CM_Get_Sibling_Ex   
  
***  

