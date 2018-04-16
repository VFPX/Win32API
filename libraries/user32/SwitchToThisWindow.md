[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SwitchToThisWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The function is called to switch focus to a specified window and bring it to the foreground. 
***  


## Code examples:
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
VOID SwitchToThisWindow(
	HWND hWnd,
	BOOL fAltTab
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SwitchToThisWindow IN user32;
	INTEGER hWindow,;
	INTEGER fAltTab  
```  
***  


## Parameters:
hWnd
[in] Handle to the window being switched to. 

fAltTab
[in] A TRUE for this parameter indicates that the window is being switched to using the Alt/Ctl+Tab key sequence.  
***  


## Return value:
None.  
***  


## Comments:
Requires Windows XP/2K. You can access this function by using LoadLibrary and GetProcAddress combined in Microsoft Windows versions prior to Windows XP.  
  
MSDN: This function is deprecated and not intended for general use. It is recommended that you do not use it in new programs because it might be altered or unavailable in subsequent versions of Windows.   
  
* * *  
To bring the FoxPro window to the front, in VFP version 7+:
```foxpro
DECLARE SwitchToThisWindow IN user32;  
	INTEGER hWindow, INTEGER fAltTab  
= SwitchToThisWindow(_Screen.HWND, 0)
```
In older VFP versions:
```foxpro
* save the value on app start<font color=#0000a0>  
DECLARE INTEGER GetActiveWindow IN user32  
hScreen = GetActiveWindow()<font color=#00a000>  
* ... later ...<font color=#0000a0>  
DECLARE SwitchToThisWindow IN user32;  
	INTEGER hWindow, INTEGER fAltTab  
= SwitchToThisWindow(m.hScreen, 0)
```

***  

