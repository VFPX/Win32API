[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExitWindowsEx
Group: [System Shutdown](../../functions_group.md#System_Shutdown)  -  Library: [user32](../../Libraries.md#user32)  
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
uFlags
Specifies the type of shutdown. See all constants listed in an example

dwReserved
Reserved; this parameter is ignored  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
Test under Windows Me was ok for EWX_LOGOFF and EWX_REBOOT modes  
  
***  

