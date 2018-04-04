[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetSuspendState
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [powrprof](../../Libraries.md#powrprof)  
***  


#### The SetSuspendState function suspends the system by shutting power down. Depending on the Hibernate parameter, the system either enters a suspend (sleep) state or hibernation (S4).
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
BOOLEAN SetSuspendState(
  BOOL Hibernate,
  BOOL ForceCritical,
  BOOL DisableWakeEvent
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetSuspendState IN Powrprof;
	INTEGER Hibernate,;
	INTEGER ForceCritical,;
	INTEGER DisableWakeEvent
  
```  
***  


## Parameters:
Hibernate 
[in] If this parameter is TRUE, the system hibernates. If the parameter is FALSE, the system is suspended. 

ForceCritical 
[in] If this parameter is TRUE, the system suspends operation immediately; if it is FALSE, the system broadcasts a PBT_APMQUERYSUSPEND event to each application to request permission to suspend operation. 

DisableWakeEvent 
[in] If this parameter is TRUE, the system disables all wake events.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
An application may use SetSuspendState to transition the system from the working state to the standby (sleep), or optionally, hibernate (S4) state. This function is similar to the SetSystemPowerState function.  
  
To prevent the user from putting the computer in standby mode, the application must deny the PBT_APMQUERYSUSPEND event.  
  
***  

