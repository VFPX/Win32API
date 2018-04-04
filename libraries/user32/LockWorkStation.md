[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LockWorkStation
Group: [System Shutdown](../../functions_group.md#System_Shutdown)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The LockWorkStation function locks the workstation"s display, protecting it from unauthorized use.
***  


## Code examples:
[Locking the workstation](../../samples/sample_300.md)  

## Declaration:
```foxpro  
BOOL LockWorkStation(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LockWorkStation IN user32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function is callable only by processes running on the interactive desktop. In addition, the user must be logged on, and the workstation cannot already be locked.  
  
It has the same result as pressing Ctrl+Alt+Del and clicking Lock Workstation. To unlock the workstation, the user must log in. To receive notification when the user logs in, use the WTSRegisterSessionNotification function to receive WM_WTSSESSION_CHANGE messages.  
  
Windows NT/2000/XP: Included in Windows 2000 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

