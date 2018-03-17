<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetNativeSystemInfo
Group: System Information - Library: kernel32    
***  


#### Retrieves information about the current system to an application running under WOW64. 
***  


## Declaration:
```foxpro  
void WINAPI GetNativeSystemInfo(
  __out  LPSYSTEM_INFO lpSystemInfo
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetNativeSystemInfo IN kernel32;
	STRING @lpSystemInfo
  
```  
***  


## Parameters:
```txt  
lpSystemInfo
A pointer to a SYSTEM_INFO structure that receives the information.
  
```  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
If the function is called from a 64-bit application, it is equivalent to the GetSystemInfo function.  
  
See also: GetSystemWow64Directory   
  
***  

