<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ShowWindow
Group: Window - Library: user32    
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
```txt  
hWnd
[in] Handle to the window

nCmdShow
[in] Specifies how the window is to be shown  
```  
***  


## Return value:
If the window was previously visible, the return value is nonzero. 
If the window was previously hidden, the return value is zero
  
***  

