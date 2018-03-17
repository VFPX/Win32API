<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetSystemInfo
Group: System Information - Library: kernel32    
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
```txt  
lpSystemInfo
[out] Pointer to a SYSTEM_INFO structure that receives the information.  
```  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
WinNT: much of this info you can find in environment strings. Skip to the examples with GetEnvironmentStrings.  
  
See also: GetNativeSystemInfo   
  
***  

