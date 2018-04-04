[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnableWindow
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Enables or disables mouse and keyboard input to the specified window or control.
***  


## Code examples:
[Locking mouse and keyboard input for the VFP application](../../samples/sample_084.md)  

## Declaration:
```foxpro  
BOOL EnableWindow(
  HWND hWnd,     // handle to window
  BOOL bEnable   // enable or disable input
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnableWindow IN user32;
	INTEGER hwnd,;
	INTEGER fEnable  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to be enabled or disabled. 

bEnable 
[in] Specifies whether to enable or disable the window. If this parameter is TRUE, the window is enabled. If the parameter is FALSE, the window is disabled.  
***  


## Return value:
If the window was previously disabled, the return value is nonzero.  
***  


## Comments:
A window must be enabled before it can be activated. That is why VFP application can not be accessed through the Task Manager, when disabled with this function.  
  
Only a few windowed controls in VFP expose HWND property. They can be disabled or enabled by calling this function.  
  
***  

