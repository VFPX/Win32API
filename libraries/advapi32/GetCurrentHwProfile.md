<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetCurrentHwProfile
Group: System Information - Library: advapi32    
***  


#### Retrieves information about the current hardware profile for the local computer.
***  


## Code examples:
[Reading current hardware profile](../../samples/sample_134.md)  

## Declaration:
```foxpro  
BOOL GetCurrentHwProfile(
  LPHW_PROFILE_INFO lpHwProfileInfo  // profile information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentHwProfile IN advapi32;
	STRING @ lpHwProfileInfo  
```  
***  


## Parameters:
```txt  
lpHwProfileInfo
[out] Pointer to an HW_PROFILE_INFO structure that receives information about the current hardware profile.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.
  
***  

