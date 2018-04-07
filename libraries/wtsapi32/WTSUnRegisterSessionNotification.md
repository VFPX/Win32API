[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSUnRegisterSessionNotification
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
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
hWnd 
[in] Handle of the window to be unregistered from receiving session notifications.  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
This function must be called once for every call to the WTSRegisterSessionNotification function.  
  
See also: [LockWorkStation](../user32/LockWorkStation.md).  
  
***  

