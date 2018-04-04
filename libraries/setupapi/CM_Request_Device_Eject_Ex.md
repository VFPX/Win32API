[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CM_Request_Device_Eject_Ex
Group: [PnP Configuration Manager](../../functions_group.md#PnP_Configuration_Manager)  -  Library: [setupapi](../../Libraries.md#setupapi)  
***  


#### Prepares a local or a remote device instance for safe removal, if the device is removable.
***  


## Code examples:
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  

## Declaration:
```foxpro  
CMAPI CONFIGRET WINAPI
CM_Request_Device_Eject_Ex (
	IN DEVINST  dnDevInst,
	OUT PPNP_VETO_TYPE  pVetoType,
	OUT LPTSTR  pszVetoName,
	IN ULONG  ulNameLength,
	IN ULONG  ulFlags,
	IN HMACHINE  hMachine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CM_Request_Device_Eject_Ex IN setupapi;
	INTEGER dnDevInst,;
	INTEGER pVetoType,;
	INTEGER pszVetoName,;
	LONG ulNameLength,;
	LONG ulFlags,;
	INTEGER hMachine  
```  
***  


## Parameters:
dnDevInst 
Caller-supplied device instance handle that is bound to the machine handle supplied by hMachine.

pVetoType 
(Optional.) Can be set to NULL. 

pszVetoName 
(Optional.) Can be set to NULL.

ulNameLength 
(Optional.) Caller-supplied value representing the length of the string buffer supplied by pszVetoName. This should be set to MAX_PATH.

ulFlags 
Not used. 

hMachine 
Caller-supplied machine handle to which the caller-supplied device instance handle is bound.  
***  


## Return value:
If the operation succeeds, the function returns CR_SUCCESS (0).  
***  


## Comments:
Initially I expected the function to be located in <Em>cfgmgr32.dll</Em> not in <Em>setupapi.dll</Em>.  
  
***  

