<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSRegisterSessionNotification
Group: Terminal Services - Library: wtsapi32    
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
```txt  
hWnd
[in] Handle of the window to receive session change notifications.

dwFlags
[in] Specifies which session notifications are to be received: NOTIFY_FOR_THIS_SESSION, NOTIFY_FOR_ALL_SESSIONS.  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
Session change notifications are sent in the form of a WM_WTSSESSION_CHANGE message. When a window no longer requires these notifications, it must call WTSUnRegisterSessionNotification before being destroyed.  
  
See also: LockWorkStation.  
  
***  

