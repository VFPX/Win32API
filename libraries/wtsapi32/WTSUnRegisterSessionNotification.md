<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WTSUnRegisterSessionNotification
Group: Terminal Services - Library: wtsapi32    
***  


#### Unregisters the specified window so that it receives no further session change notifications.
***  


## Code examples:
[Locking the workstation](../../samples/sample_300.md)  

## Declaration:
```foxpro  
BOOL WTSUnRegisterSessionNotification(
  HWND hWnd
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSUnRegisterSessionNotification IN wtsapi32;
	INTEGER hWindow

  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle of the window to be unregistered from receiving session notifications.  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
This function must be called once for every call to the WTSRegisterSessionNotification function.  
  
See also: LockWorkStation.  
  
***  

