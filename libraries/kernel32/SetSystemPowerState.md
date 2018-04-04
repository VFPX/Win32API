[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetSystemPowerState
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetSystemPowerState function suspends the system by shutting power down. Depending on the ForceFlag parameter, the function either suspends operation immediately or requests permission from all applications and device drivers before doing so.
***  


## Declaration:
```foxpro  
BOOL SetSystemPowerState(
  BOOL fSuspend,
  BOOL fForce
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetSystemPowerState IN kernel32;
	INTEGER fSuspend,;
	INTEGER fForce

  
```  
***  


## Parameters:
fSuspend 
[in] If this parameter is TRUE, the system is suspended. If the parameter is FALSE, the system hibernates. 

fForce 
[in] If this parameter is TRUE, the function broadcasts a PBT_APMSUSPEND event to each application and driver, then immediately suspends operation. If the parameter is FALSE, the function broadcasts a PBT_APMQUERYSUSPEND event to each application to request permission to suspend operation.  
***  


## Return value:
If power has been suspended and subsequently restored, the return value is nonzero.  
***  


## Comments:
The first parameter is ignored in Windows Me/98/95.  
This function is similar to the SetSuspendState function.  
  
***  

