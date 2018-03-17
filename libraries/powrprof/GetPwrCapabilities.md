<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetPwrCapabilities
Group: Power Management - Library: powrprof    
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
```txt  
lpSystemPowerCapabilities
[out] Pointer to a SYSTEM_POWER_CAPABILITIES structure that receives the information.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

