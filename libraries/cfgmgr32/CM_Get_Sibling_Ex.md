[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Get_Sibling_Ex
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [cfgmgr32](../../Libraries.md#cfgmgr32)  
***  


#### Obtains a device instance handle to the next sibling node of a specified device node, in a local or a remote machine"s device tree.
***  


## Code examples:
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI
	CM_Get_Sibling_Ex(
	OUT PDEVINST pdnDevInst,
	IN DEVINST DevInst,
	IN ULONG ulFlags,
	IN HMACHINE hMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Get_Sibling_Ex IN cfgmgr32;
	INTEGER @pdnDevInst,;
	INTEGER DevInst,;
	LONG ulFlags,;
	INTEGER hMachine  
```  
***  


## Parameters:
pdnDevInst 
Caller-supplied pointer to the device instance handle to the sibling node that this function retrieves. The retrieved handle is bound to the machine handle specified by hMachine. 

DevInst 
Caller-supplied device instance handle that is bound to the machine handle specified by hMachine. 

ulFlags 
Not used, must be zero. 

hMachine 
Caller-supplied machine handle to which the caller-supplied device instance handle is bound.  
***  


## Return value:
If the operation succeeds, the function returns CR_SUCCESS (0).  
***  


## Comments:
The CM_Get_Child_Ex and the CM_Get_Sibling_Ex calls make possible  to enumerate all device nodes in the device tree for a machine specified by the mean of CM_Connect_Machine call.  
  
See also: [CM_Connect_Machine](../cfgmgr32/CM_Connect_Machine.md), [CM_Get_Child_Ex](../cfgmgr32/CM_Get_Child_Ex.md).  
  
***  

