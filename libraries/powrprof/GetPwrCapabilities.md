[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPwrCapabilities
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [powrprof](../../Libraries.md#powrprof)  
***  


#### The GetPwrCapabilities function retrieves information about the system power capabilities.
***  


## Code examples:
[Power capabilities of the system: battery, UPS, sleep and hibernation modes, processor throttling](../../samples/sample_394.md)  

## Declaration:
```foxpro  
BOOLEAN GetPwrCapabilities(
  PSYSTEM_POWER_CAPABILITIES lpSystemPowerCapabilities
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPwrCapabilities IN powrprof;
	STRING @lpSystemPowerCapabilities
  
```  
***  


## Parameters:
lpSystemPowerCapabilities 
[out] Pointer to a SYSTEM_POWER_CAPABILITIES structure that receives the information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

