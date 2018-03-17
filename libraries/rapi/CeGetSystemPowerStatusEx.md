<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetSystemPowerStatusEx
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function retrieves the power status of the system.
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
BOOL CeGetSystemPowerStatusEx(
  PSYSTEM_POWER_STATUS_EX pstatus,
  BOOL fUpdate
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeGetSystemPowerStatusEx IN rapi;
	STRING  @ pstatus,;
	INTEGER   fUpdate  
```  
***  


## Parameters:
```txt  
pstatus
[out] Pointer to the SYSTEM_POWER_STATUS_EX structure receiving the power status information.

fUpdate
[in] If this Boolean is set to TRUE, CeGetSystemPowerStatusEx gets the latest information from the device driver, otherwise it retrieves cached information that may be out-of-date by several seconds.  
```  
***  


## Return value:
This function returns TRUE if successful; otherwise, it returns FALSE.  
***  


## Comments:
The status indicates whether the system is running on AC or DC power, whether or not the batteries are currently charging, and the remaining life of main and backup batteries.  
  
***  

