[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetStartupInfo
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
lpStartupInfo 
[out] Pointer to a STARTUPINFO structure that receives the startup information.  
***  


## Return value:
This function does not return a value.  
***  

