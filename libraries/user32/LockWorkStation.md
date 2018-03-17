<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LockWorkStation
Group: System Shutdown - Library: user32    
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
```txt  
This function has no parameters.  
```  
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

