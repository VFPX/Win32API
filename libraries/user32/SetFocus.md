<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetFocus
Group: Keyboard Input - Library: user32    
***  


#### Sets the keyboard focus to the specified window. The window must be attached to the calling thread"s message queue
***  


## Declaration:
```foxpro  
HWND SetFocus(
	HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetFocus IN user32;
AS SetFocusAPI INTEGER hWindow
  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window that will receive the keyboard input. If this parameter is NULL, keystrokes are ignored.  
```  
***  


## Return value:
If the function succeeds, the return value is the handle to the window that previously had the keyboard focus.   
***  


## Comments:
<div class="precode">DECLARE INTEGER SetFocus IN user32;  
	AS SetFocusAPI INTEGER hWindow  
? SetFocusAPI(_screen.HWnd)  
</div>  
See also: GetFocus, SetForegroundWindow, GetForegroundWindow, GetActiveWindow.  
  
***  

