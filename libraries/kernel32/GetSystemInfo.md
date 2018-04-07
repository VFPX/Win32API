[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemInfo
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Returns information about the current system.
***  


## Code examples:
[Current System information](../../samples/sample_096.md)  

## Declaration:
```foxpro  
VOID GetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo  // system information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetSystemInfo IN kernel32 STRING @ lpSystemInfo  
```  
***  


## Parameters:
lpSystemInfo 
[out] Pointer to a SYSTEM_INFO structure that receives the information.  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
WinNT: much of this info you can find in environment strings. Skip to the examples with GetEnvironmentStrings.  
  
See also: [GetNativeSystemInfo](../kernel32/GetNativeSystemInfo.md).  
  
***  

