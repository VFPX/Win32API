[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSRegisterSessionNotification
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
***  


#### Registers the specified window to receive session change notifications.

***  


## Code examples:
[Locking the workstation](../../samples/sample_300.md)  

## Declaration:
```foxpro  
BOOL WTSRegisterSessionNotification(
  HWND hWnd,
  DWORD dwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSRegisterSessionNotification IN Wtsapi32;
	INTEGER hWindow,;
	LONG dwFlags  
```  
***  


## Parameters:
hWnd 
[in] Handle of the window to receive session change notifications. 

dwFlags 
[in] Specifies which session notifications are to be received: NOTIFY_FOR_THIS_SESSION, NOTIFY_FOR_ALL_SESSIONS.  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
Session change notifications are sent in the form of a WM_WTSSESSION_CHANGE message. When a window no longer requires these notifications, it must call WTSUnRegisterSessionNotification before being destroyed.  
  
See also: [LockWorkStation](../user32/LockWorkStation.md).  
  
***  

