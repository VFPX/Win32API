<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ExitWindowsEx
Group: System Shutdown - Library: user32    
***  


#### Either logs off, shuts down, or shuts down and restarts the system
***  


## Code examples:
[Closing Windows](../../samples/sample_036.md)  
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  

## Declaration:
```foxpro  
BOOL ExitWindowsEx(
	UINT  uFlags,		// shutdown operation
	DWORD  dwReserved 	// reserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ExitWindowsEx IN user32;
	INTEGER uFlags,;
	INTEGER dwReserved  
```  
***  


## Parameters:
```txt  
uFlags
Specifies the type of shutdown. See all constants listed in an example

dwReserved
Reserved; this parameter is ignored  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
Test under Windows Me was ok for EWX_LOGOFF and EWX_REBOOT modes  
  
***  

