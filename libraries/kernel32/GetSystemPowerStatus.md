[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemPowerStatus
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the power status of the system. The status indicates whether the system is running on AC or DC power, whether the battery is currently charging, and how much battery life remains.
***  


## Code examples:
[Get the power status of your laptop computer](../../samples/sample_006.md)  

## Declaration:
```foxpro  
BOOL GetSystemPowerStatus(
  LPSYSTEM_POWER_STATUS lpSystemPowerStatus
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemPowerStatus IN kernel32;
	STRING @lpSystemPowerStatus
  
```  
***  


## Parameters:
lpSystemPowerStatus 
[out] Pointer to a SYSTEM_POWER_STATUS structure that receives status information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

