[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShowWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The ShowWindow function sets the show state for the specified window.
***  


## Code examples:
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Saying "Hello World!" with VFP and WinAPI](../../samples/sample_119.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[How to block the ALT+TAB shortcut (WinXP)](../../samples/sample_432.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  

## Declaration:
```foxpro  
BOOL ShowWindow(
  HWND hWnd,     // handle to window
  int nCmdShow   // show state
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShowWindow IN user32;
    INTEGER hwnd,;
    INTEGER nCmdShow  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window

nCmdShow 
[in] Specifies how the window is to be shown  
***  


## Return value:
If the window was previously visible, the return value is nonzero. 
If the window was previously hidden, the return value is zero
  
***  

