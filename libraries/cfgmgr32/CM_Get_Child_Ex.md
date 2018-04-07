[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Get_Child_Ex
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [cfgmgr32](../../Libraries.md#cfgmgr32)  
***  


#### The function is used to retrieve a device instance handle to the first child node of a specified device node, in a local or a remote machine"s device tree.

***  


## Code examples:
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI CM_Get_Child_Ex(
	OUT PDEVINST pdnDevInst,
	IN DEVINST dnDevInst,
	IN ULONG ulFlags,
	IN HMACHINE  hMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Get_Child_Ex IN cfgmgr32;
	INTEGER @pdnDevInst,;
	INTEGER DevInst,;
	LONG ulFlags,;
	INTEGER hMachine  
```  
***  


## Parameters:
pdnDevInst 
Caller-supplied pointer to the device instance handle to the child node that this function retrieves. The retrieved handle is bound to the machine handle supplied by hMachine.

dnDevInst 
Caller-supplied device instance handle that is bound to the machine handle supplied by hMachine. 

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
  
See also: [CM_Connect_Machine](../cfgmgr32/CM_Connect_Machine.md), [CM_Locate_DevNode_Ex](../cfgmgr32/CM_Locate_DevNode_Ex.md), [CM_Get_Sibling_Ex](../cfgmgr32/CM_Get_Sibling_Ex.md).  
  
***  

