<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetStartupInfo
Group: Process and Thread - Library: kernel32    
***  


#### Retrieves the contents of the STARTUPINFO structure that was specified when the calling process was created.
***  


## Code examples:
[Reading STARTUPINFO structure for the current VFP session](../../samples/sample_153.md)  

## Declaration:
```foxpro  
VOID GetStartupInfo(
  LPSTARTUPINFO lpStartupInfo   // startup information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetStartupInfo IN kernel32;
	STRING @ lpStartupInfo  
```  
***  


## Parameters:
```txt  
lpStartupInfo
[out] Pointer to a STARTUPINFO structure that receives the startup information.  
```  
***  


## Return value:
This function does not return a value.  
***  

