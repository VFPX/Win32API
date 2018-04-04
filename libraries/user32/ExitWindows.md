[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExitWindows
Group: [System Shutdown](../../functions_group.md#System_Shutdown)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Logs the current user off
***  


## Code examples:
[Closing Windows](../../samples/sample_036.md)  

## Declaration:
```foxpro  
BOOL ExitWindows(
	DWORD  dwReserved,	// reserved
	UINT  uReserved 	// reserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ExitWindows IN user32;
	INTEGER dwReserved,;
	INTEGER uReserved  
```  
***  


## Parameters:
dwReserved
Reserved; must be zero. 

uReserved
Reserved; must be zero  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
Windows Me: using this function causes an error: entry point not found; it looks like this function is not implemented or it has an alias different from "ExitWindow".  
  
Most evidently ExitWindows call is completely equivalent to  
ExitWindowsEx (EWX_LOGOFF, 0)  
  
***  

