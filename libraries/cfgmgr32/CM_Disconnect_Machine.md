<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CM_Disconnect_Machine
Group: PnP Configuration Manager - Library: cfgmgr32    
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
```txt  
hMachine
Caller-supplied machine handle, obtained from a previous call to CM_Connect_Machine.  
```  
***  


## Return value:
If the operation succeeds, the function returns CR_SUCCESS (0).  
***  


## Comments:
See also: CM_Connect_Machine   
  
***  

