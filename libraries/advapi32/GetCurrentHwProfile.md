[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrentHwProfile
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
lpHwProfileInfo 
[out] Pointer to an HW_PROFILE_INFO structure that receives information about the current hardware profile.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.
  
***  

